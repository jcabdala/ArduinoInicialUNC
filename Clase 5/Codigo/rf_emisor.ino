

#include <SPI.h>
#include "RF24.h"



/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 9 & 10 */
RF24 radio(9,10);
/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};

// Used to control whether this node is sending or receiving


void setup() 
{
  Serial.begin(115200);
 
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1,addresses[0]);
 
  
  // Start the radio listening for data
  radio.startListening();
}

void loop() 
{
  

    
    radio.stopListening();                                    // First, stop listening so we can talk.
    
    
    Serial.println(F("Now sending"));
    byte txByte = '1'; 
                                
     if (!radio.write( &txByte, 1))
     {
       Serial.println(F("failed"));
     }
    
    if (byteRX == '1')
    {
     digitalWrite(4, HIGH);  
    } 
    else
    {
      digitalWrite(4, LOW); 
    } 
       
        
  
    // Try again 1s later
    delay(5000);
  



} // Loop
