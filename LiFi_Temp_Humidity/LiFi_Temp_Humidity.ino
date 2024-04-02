#include <dht11.h>
#define DHT11PIN 4
#define hold 50
#define newBit 50

dht11 DHT11;

byte sensorPin = A0;
byte Temp_Led = 3;
byte Hum_Led = 7;
void blinkCode(char* code, byte G_LedPin) {
  int index = 0;
    while(code[index] != '\0'){
      if(code[index] == '0') {
            digitalWrite(G_LedPin, LOW);
            delay(hold);
        }
        else {
            digitalWrite(G_LedPin, HIGH);
            delay(hold);
        }
        int curr = analogRead(sensorPin);
        if(curr >= 900){
          Serial.print(1);
        }
        else{
          Serial.print(0);
        }
        digitalWrite(G_LedPin, LOW);
        delay(newBit);
      //  Serial.println(code[index]);
        index++;
    }
    Serial.println("");
}

void  setup()
{
  pinMode(Temp_Led, OUTPUT);
  pinMode(Hum_Led, OUTPUT);
  digitalWrite(Temp_Led, LOW);
  digitalWrite(Hum_Led, LOW);

  Serial.begin(9600);
 
}

void loop()
{
  byte brightness;
  // analogWrite(Temp_Led, 255);
  // Serial.println(analogRead(sensorPin));
  // delay(1000);
  // analogWrite(Temp_Led, 5);
  // Serial.println(analogRead(sensorPin));
  // delay(1000);
  // analogWrite(Temp_Led, 0);
  // Serial.println(analogRead(sensorPin));

  int chk = DHT11.read(DHT11PIN);
  int hum = (int)DHT11.humidity;
  //
  uint8_t bitsCount = 7 ;
  char str_hum[ bitsCount + 1 ];

  uint8_t i = 0;
  while ( bitsCount-- )
    str_hum[ i++ ] = bitRead( hum, bitsCount ) + '0';
  str_hum[ i ] = '\0';
  
  //



  int temp = (int)DHT11.temperature;
  //
   bitsCount = 7 ;
  char str_temp[ bitsCount + 1 ];

  i = 0;
  while ( bitsCount-- )
    str_temp[ i++ ] = bitRead( temp, bitsCount ) + '0';
  str_temp[ i ] = '\0';
  
  Serial.print("Humidity (%): ");
  Serial.println(str_hum);

  Serial.print("Temperature  (C): ");
    Serial.println(str_temp);

  //Serial.println(str_temp);
  //Serial.println("Temperature...");
  blinkCode(str_temp, Temp_Led);
  delay(1000);
  //Serial.println("Humidity...");
  blinkCode(str_hum, Hum_Led);
  delay(1000);
  

}