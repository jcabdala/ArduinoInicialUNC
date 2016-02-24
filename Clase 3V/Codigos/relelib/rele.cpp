#include "rele.h"
#include <Arduino.h>

void ReleClass::inicio(int rele1, int rele2)
{
  pinMode(rele1, OUTPUT); // Declaramos que utilizaremos el pin 4 como salida
  pinMode(rele2, OUTPUT);
}
void ReleClass::prender(int pin)
{
	digitalWrite(pin, LOW);
}
void ReleClass::apagar(int pin)
{
	digitalWrite(pin, HIGH);
}
