int input;
int rele1 = 4;
int rele2 = 5;


void setup()
{
  Serial.begin(9600);
  pinMode(rele1, OUTPUT); // Declaramos que utilizaremos el pin 4 como salida
  pinMode(rele2, OUTPUT); // Declaramos que utilizaremos el pin 5 como salida
  
}

void loop()
{
  
	if (Serial.available()>0)
	{

    	input=Serial.read();

		if (input == '1')
		{
			digitalWrite(13, LOW);// prender 1
		}
		if (input == '2')
	    
   	     digitalWrite(13, HIGH); // Apagar 1
		     
  		}

  }
}