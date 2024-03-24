#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<string>
const int N=3;
class Etudiant
{
	private:
		std::string nom;
		std::string prenom;
		float tabnotes[N];
		
	public:
		void saisie();
		void affichage();
		float moyenne();
		int admis();
		int exae_quo( Etudiant E);
		

};


#endif
