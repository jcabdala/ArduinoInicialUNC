char dato_recibido = 0;   // para almacenar la info recibida

void setup() 
{
        // iniciamos el serial 
        Serial.begin(115200);     
}
void loop() 
{        
     if (Serial.available() > 0) // verifico si recibo: 
     {
	    // leo el dato recibido:	
	    dato_recibido = Serial.read();                     
       // y lo imprimo
	    Serial.print("El dato recibido fue: ");                 
	    Serial.println(dato_recibido);
     }
}
