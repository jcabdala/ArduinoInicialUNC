const int analogInPin = A0;  // pin analogico a usar

int sensorValue = 0;        // variable para guardar dato

void setup() 
{
  Serial.begin(9600);
}

void loop() {
  // Leo el dato del puerto Analogico
  sensorValue = analogRead(analogInPin);
  
  // Imprimo el paso de conversion
  Serial.print("sensor = " );
  Serial.println(sensorValue);
 

  delay(100);
}