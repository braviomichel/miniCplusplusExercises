#include "Cercle_col.h"
#include "Cercle.h"
#include <iostream>
using namespace std;

Cercle_col::Cercle_col(float x, float y, float r, char* nom, char clr) : Cercle(x, y, r, nom)
{
	this->clr=clr;
}
