void setup() 
{ 
	 // Establece un pin digital como salida.
	 // El Pin 2 tiene un LED conectado a el.
	  pinMode(2, OUTPUT);
	  pinMode(3, OUTPUT);
	  pinMode(4, OUTPUT);
	  pinMode(5, OUTPUT);
}
void loop() 
{
	digitalWrite(2, HIGH);   // enciende led 
	delay(200);           // espera un segundo
	digitalWrite(2, LOW);    // apaga el LED 
	digitalWrite(3, HIGH);   // enciende led 
	delay(200); // espera un segundo
	digitalWrite(3, LOW);    // apaga el LED
	digitalWrite(4, HIGH);   // enciende led 
	delay(200); // espera un segundo
	digitalWrite(4, LOW);    // apaga el LED
	digitalWrite(5, HIGH);   // enciende led 
	delay(200);    // espera un segundo
	digitalWrite(5, LOW);    // apaga el LED
	delay(200);    // espera un segundo
}
