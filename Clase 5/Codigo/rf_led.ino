#include <SPI.h>
#include "RF24.h"

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(9,10);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};



void setup() {
  Serial.begin(115200);
  
  
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_MAX);
  
 
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  
  // Start the radio listening for data
  radio.startListening();
}

void loop() 
{
  
  


   byte byteRX;
    
    if( radio.available())
    {
                                                                    // Variable for the received timestamp
                                  // While there is data ready
      radio.read( &byteRx, 1 );             // Get the payload

                                          
         
                                             // Now, resume listening so we catch the next packets.     
      Serial.print(F("Byte RX"));
      Serial.println(byteRx);  

   }
 





} // Loop
