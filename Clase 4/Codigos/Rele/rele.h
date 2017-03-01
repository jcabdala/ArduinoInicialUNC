#ifndef __rele__
#define __rele__

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class ReleClass 
{
public:
	void inicio(int rele1, int rele2);
	void prender(int pin);
	void apagar(int pin);	
};

#endif
