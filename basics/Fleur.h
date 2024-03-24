#ifndef FLEUR_H
#define FLEUR_H
#include<string>


class Fleur
{
	private:
		std::string espece;
		std::string couleur;
		double prix_base;
		bool parfumee;
		bool promotion;
		
	public:
		Fleur(std::string="",std::string="",double=0,bool=true,bool=false);
		bool operator != (Fleur f1);
		void affiche();
		
};

#endif
