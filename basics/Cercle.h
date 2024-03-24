#ifndef CERCLE_H
#define CERCLE_H

class Cercle
{
	protected:
		char *nom;
		float x,y;
		float r;
	public :
		Cercle (float x, float y, float r, char *nom);
		Cercle (Cercle &);
		float surface();
		void tracer();
		~Cercle();
		friend bool compare(Cercle c1, Cercle c2);
};

#endif
