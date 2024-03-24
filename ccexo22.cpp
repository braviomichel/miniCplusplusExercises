#include<iostream>
#include<string>
using namespace std ;

class Compte
{
	protected :
		int numero ; // numéro de compte
		float soldeinit ; // solde initial
	public :
		Compte (int n, float s) // constructeur à deux arguments
		{	Numero= n;
			soldeinit=s;
		}
		float calculer_solde()
		{	return soldeinit; 
}
} ;

class compte_depot : public Compte
{
	private:
		float *t;
		int opmax;
		int opcourant;
	public :
		compte_depot( float *t, int =10,int=0);
		float calculer_solde();
		compte_depot operator> ( compte_depot cd);
		
}

