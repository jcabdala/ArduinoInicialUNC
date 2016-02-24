#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

void setup()
   {   
       Serial.begin(115200);
    
       setSyncProvider(RTC.get);      // Vamos a usar el RTC

       setTime(21,45,00,8,11,2015); // Las 21:45:00 del dia 8 de Nov de 2015
       Serial.print(hour());
       Serial.print(":");
       Serial.print(minute());
       Serial.print(":");
       Serial.print(second());
       Serial.print(" ");
       Serial.print(day());
       Serial.print(" ");
       Serial.print(month());
       Serial.print(" ");
   }
void loop()
   {     
   }

         
         

