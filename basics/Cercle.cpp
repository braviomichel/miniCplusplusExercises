#include "Cercle.h"
#include <iostream>
using namespace std;

Cercle::Cercle(float x, float y, float r, char *nom)
{
	this->x=x;
	this->y=y;
	this->r=r;
	this->nom=nom;
}

Cercle::Cercle(Cercle &c )
{
	x=c.x;
	y=c.y;
	r=c.r;
	nom=c.nom;
}

float Cercle :: surface()
{
	return((3,14)*r*r);
}

void Cercle::tracer()
{
	
}
Cercle::~Cercle()
{
	delete nom;
}

