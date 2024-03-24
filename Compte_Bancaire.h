#ifndef COMPTE_BANCAIRE_H
#define COMPTE_BANCAIRE_H

class Compte_Bancaire
{
	private: 
		int num_compte;
		float solde;
	public:
		Compte_Bancaire(int =0, float =100);
		void debiter(float);
		void crediter(float);
		void VirVerser(float, Compte_Bancaire &);
		float getSolde();
		int getNumero();
		void afficher();
};

#endif
