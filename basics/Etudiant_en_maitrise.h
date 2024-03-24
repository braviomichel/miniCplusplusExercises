#ifndef ETUDIANT_EN_MAITRISE_H
#define ETUDIANT_EN_MAITRISE_H
#include "Etudiant.h"
#include<string>
class Etudiant_en_maitrise : public Etudiant{
	private:
		float note_memoire;
	public:
		void saisie();
		void affichage();
		float moyenne();
		int admis();
		int exae_quo(Etudiant_en_maitrise E);
};

#endif
