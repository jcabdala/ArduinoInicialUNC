#include "rele.h"

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
		     rele.prender(4); // prender 1
		      break;
		    case '2':
		    rele.prender(5); // prender 2
		      break;
		    case '3':
		    rele.apagar(4);// Apagar 1
		      break;
		    case '4':
		    rele.apagar(5); // apagar 2
		      break;
		    default: 
		     
		    break;
  		}

  }
}
