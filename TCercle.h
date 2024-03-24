#include "Cercle.h"
#ifndef TCERCLE_H
#define TCERCLE_H

class TCercle
{
	private:
		Cercle *T;
		int nbp;
	public:
		TCercle();
		friend bool coincide(TCercle t1, TCercle t2);
		
};

#endif
