void puerta() 
{ 
   delay(100);
    int val = digitalRead(2);   // lee el valor de entrada
	// si la puerta esta abierta
 	if(val == 0) { 
 	 	Serial.println("Puerta Abierta"); }
           //Si la puerta esta cerrada
	else{
		Serial.println("Puerta Cerrada"); 
	} 
	delay(100);	   
}

void setup() 
{
	Serial.begin(115200);
    pinMode(2, INPUT); 
	attachInterrupt(0, puerta,CHANGE);
}

void loop() 
{
		Serial.println("No pasa nada");
		delay(1000);
}
