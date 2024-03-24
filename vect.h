#ifndef VECT_H
#define VECT_H
#include "matrice.h"
#include<iostream>
class matrice;
class vect;
class vect
{
	private:
		float v[3];
	public:
		vect(float=0,float=0,float=0);
		//friend vect prod(vect V,matrice M);
		void affiche();
		
	
};

#endif
