#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
		int largeur;
		int hauteur;
	public:
		Rectangle(int=0,int=0);
		int calcule_perimetre();
		int calcule_aire();
		void affiche();
		void modifier_hauteur(int);
		void modifier_largeur(int);
};

#endif
