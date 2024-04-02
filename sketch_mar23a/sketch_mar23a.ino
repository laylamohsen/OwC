#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 27
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hic = dht.computeHeatIndex(t,h,false);
  Serial.print(F("humidity: "));
  Serial.print(h);
  Serial.print(F("% temperature: "));
  Serial.print(t);
  Serial.print(F("degrees Celsius"));
  Serial.print(F("heat index:"));
  Serial.print(hic);
  Serial.print(F("degrees celsius \n"));

}
