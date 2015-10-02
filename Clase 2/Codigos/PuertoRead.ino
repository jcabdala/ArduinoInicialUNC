int val  = 0;     // variable donde guardo lo que leo del puerto

int puerto = 2 

void setup()
{
  Serial.begin(9600);
  pinMode(puerto, INPUT);    
}

void loop()
{
   	// lee el valor de entrada	
	val = digitalRead(puerto);  
	
	// si la puerta esta abierta
 	if(val == 0) 
 	{
 		Serial.println("Puerta Abierta"); 
 	}
          
 	//Si la puerta esta cerrada
	else	
	{
		Serial.println("Puerta Cerrada"); 
	} 
	
	delay(1000);
}
