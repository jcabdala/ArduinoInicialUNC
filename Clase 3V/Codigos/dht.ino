#include <dht.h>

dht DHT;

#define DHT11_PIN 5

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t");
  DHT.read11(DHT11_PIN);

  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(2000);
}