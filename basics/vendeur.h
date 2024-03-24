#ifndef VENDEUR_H
#define VENDEUR_H
#include "employe.h"
#include<string>

class vendeur: public employe
{
	private:
		float m_vente,pourcentage;
	public:
		vendeur(int=0,std::string="",int=0, int=0,int=0, int=0,float=0,float=0,float=0);
		void saisie();
		void afficher();
		float calcul_salaire();
	
};

#endif
