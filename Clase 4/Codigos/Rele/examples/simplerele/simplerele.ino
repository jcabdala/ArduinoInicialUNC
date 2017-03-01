#include <rele.h>

ReleClass rele;

int input;

void setup()
{
  Serial.begin(9600);
  rele.inicio(4,5);  
}
void loop()
{  
  if (Serial.available()>0)
  {
    input=Serial.read();
    switch (input)
    {
      case '1':
      rele.prender(4);
      break;
      case '2':
      rele.prender(5);
      break;
      case '3':
      rele.apagar(4);
      break;
      case '4':
      rele.apagar(5);
      break;
      
    }
  }
}
