#include "Compte_Bancaire.h"
#include<iostream>
using namespace std;

	Compte_Bancaire::Compte_Bancaire(int c,float s)
		{
			num_compte=c;
			solde=s;
		}
		
		void Compte_Bancaire::debiter( float montant){
			if(montant>solde)
				cout <<"Impossible de debiter. Solde insuffisant!" <<endl ;
			else
				solde-=montant;
		}
		
		void Compte_Bancaire:: crediter (float montant){
			solde+=montant;
		}
		
		void Compte_Bancaire:: VirVerser(float montant, Compte_Bancaire &C)
		{
			debiter(montant);
			if(montant>solde)
				C.crediter(montant);
			
		}
		
		float Compte_Bancaire:: getSolde()
		{
			return solde;
		}
		
		int Compte_Bancaire:: getNumero(){
			return num_compte;
		}
		void Compte_Bancaire:: afficher()
		{
			cout <<"Votre numero de compte est " << num_compte<< " et votre solde est de "<< solde <<endl;
		}
