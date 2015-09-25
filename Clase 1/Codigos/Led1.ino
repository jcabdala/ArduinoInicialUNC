void setup() 
{ 
	 // Establece un pin digital como salida.
	 // El Pin 2 tiene un LED conectado a el.
	  pinMode(2, OUTPUT);
}
void loop() 
{
	digitalWrite(2, HIGH);   // enciende led 
	delay(1000);           // espera un segundo
	digitalWrite(2, LOW);    // apaga el LED
	delay(1000);           // espera un segundo
}
