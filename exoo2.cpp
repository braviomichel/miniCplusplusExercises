#include <iostream>
#include"Vecteur.h"
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float x,y,z;
 
	cout<<"Entrez x ";
	cin >>x;
	cout<<"Entrez y ";
	cin >>y;
	cout<<"Entrez z ";
	cin >>z;
	Vecteur v1(x,y,z);
	cout<< "Valeurs entrees: "<<endl;
	v1.afficher();
	
	
	//Modification
	cout<<endl<<"Entrez la nouvelle valeur x ";
	cin >>x;
	cout<<"Entrez la nouvelle valeur y ";
	cin >>y;
	cout<<"Entrez la nouvelle valeur z ";
	cin >>z;
	Vecteur tmp(x,y,z);
	v1=tmp;
	cout<< "Valeurs modifiees: "<<endl;
	v1.afficher();
	
	// comparaison
	cout<<"Entrez le vecteur a comparer:"<<endl;
	cout<<"Entrez x ";
	cin >>x;
	cout<<"Entrez y ";
	cin >>y;
	cout<<"Entrez z ";
	cin >>z;
	
	Vecteur v2(x,y,z);
	
	//fonction coincide
	Vecteur::coincide(v2,v1);
	
	
	//fonction somme par référence
	cout<<"Somme des deux vecteurs"<<endl;
	Vecteur::somme (v1,v2);
	

	
	return 0;
}
