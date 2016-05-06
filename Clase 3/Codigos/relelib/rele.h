#ifndef __RELE__
#define __RELE__
class ReleClass 
{
	public:
		static void inicio(int rele1, int rele2);
		static void prender(int pin);
		static void apagar(int pin);	
};
extern ReleClass rele;
#endif
