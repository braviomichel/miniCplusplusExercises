#ifndef MATRICE_H
#define MATRICE_H
#include "vect.h"
class matrice;
class vect;
class matrice
{
	private:
		int m[3][3];
	public:
		//matrice();
		void saisie();
		void affiche();
		friend vect matrice::prod(vect);
};

#endif
