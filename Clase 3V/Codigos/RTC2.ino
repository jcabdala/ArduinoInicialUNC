#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
void digitalClockDisplay()
   {   
         Serial.print(hour());
         printDigits(minute());
         printDigits(second());
         Serial.print(" ");
         Serial.print(day());
         Serial.print(" ");
         Serial.print(month());
         Serial.print(" ");
         Serial.print(year());
         Serial.println();
   }
void printDigits(int digits)
   {     Serial.print(":");
         if(digits < 10)
            Serial.print('0');
         Serial.print(digits);
   }

void setup()
   {   
      Serial.begin(115200);
      pinMode(3, OUTPUT);
      setSyncProvider(RTC.get);      // Vamos a usar el RTC

      setTime(21,45,00,8,11,2015); // Las 21:45:00 del dia 8 de Nov de 2015

   }
void loop()

   {  
      digitalWrite(13, HIGH);   
      digitalClockDisplay();
      digitalWrite(13, LOW);
      delay(1000);
   }
