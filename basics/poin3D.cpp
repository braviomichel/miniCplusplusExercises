#include "poin3D.h"
#include<iostream>
using namespace std;

int poin3D :: compteur;

poin3D::poin3D(float a,float b,float c)
{
	x=a;
	y=b;
	z=c;
	compteur++;
}


void poin3D::nombre_classe()
{
	cout<< "Nombre de classes crees "<< compteur<<endl;
}
