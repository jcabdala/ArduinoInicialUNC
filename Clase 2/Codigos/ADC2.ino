const int analogInPin = A0;  // pin analogico a usar

int sensorValue = 0;        // variable para guardar dato

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // Leo el dato del puerto Analogico
  sensorValue = analogRead(analogInPin);
  
  float voltage = sensorValue * (5.0 / 1024.0);
  // Imprimo el paso de conversion
  Serial.print("sensor = " );
  Serial.println(sensorValue);
  
  Serial.print("voltaje = " );
  Serial.println(voltage);

  delay(100);
}