#include "Cercle.h"
#ifndef CERCLE_COL_H
#define CERCLE_COL_H

class Cercle_col : public Cercle
{
	private:
		char clr;
	public:
		Cercle_col(float x, float y, float r,char *nom , char clr);
};

#endif
