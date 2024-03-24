#include "Etudiant.h"
#include<iostream>
#include<string>
using namespace std;

void Etudiant:: saisie()
{
	int i;
	cout<<"Entrez votre prenom:";
	cin>>this->prenom;
	cout<<"Entrez votre nom:";
	cin>>this->nom;
	for(i=0;i<N;i++)
	{
		cout<<"Entrez la ote  "<<i+1<<"  "<<endl;
		cin>>this->tabnotes[i];
	}
	
}
void Etudiant::affichage(){
	int i;
	cout<<"Nom:"<<nom<<endl;
	cout<<"prenom " <<prenom<<endl;
	cout <<"Notes:";
	for(i=0;i<N;i++)
	{
		cout<<endl<<tabnotes[i]<<"  ";
		
	}
	
}

float Etudiant::moyenne(){
	float S=0,moy;
	int i;
	for(i=0;i<N;i++)
	{
		S+=tabnotes[i];
	}
	moy=S/N;
	return moy;
}
 int Etudiant::admis(){
 	float M;
 	M=moyenne();
 	if(M<10)
 		return 0;
 	else
 		return 1;
 }
 int Etudiant::exae_quo(Etudiant E)
 {
 	if((Etudiant::moyenne())==E.moyenne())
 		return 1;
 	else
 		return 0;
 }
 
 
 
