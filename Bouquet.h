#ifndef BOUQUET_H
#define BOUQUET_H
#include "Fleur.h"
class Bouquet
{
	private:
		int nb;
		Fleur *f;
	public:
		Bouquet();
		bool parfum();
		double prix();
		Bouquet operator +=(Fleur f1);
		
	
};

#endif
