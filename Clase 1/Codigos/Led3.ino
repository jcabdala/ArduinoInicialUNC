//Arrays de pines que voy a usar
int pines[]= {10,11, 12, 13};

void setup()
{
  int i=0;
  //Declaro todos los pines como output
  for (i=0;i<4;i++)
  {   
       	pinMode (pines[i], OUTPUT);
  }
  //inicio una funcion semilla, con el adc
  randomSeed(analogRead(0));
}

void loop() 
{
  int i=0;
  //Recorro todos los pines 
  for ( i=0;i<4;i++)
  { 
  		//Depende de si random sale cero o 1 para  prender
        digitalWrite( pines[i], random(2));
  }
  delay(1000);
}