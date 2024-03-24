#include "Vecteur.h"
#include<iostream>
#include<vector>
using namespace std;

Vecteur::Vecteur(float x,float y,float z){
	
	v[0]=x;
	v[1]=y;
	v[2]=z;
}
Vecteur::~Vecteur()
{
}
void Vecteur:: afficher() 
{
	int i;
	for (i=0;i<3;i++)
		cout<<v[i]<<"    ";
	
	cout<<endl;
		
}
void Vecteur :: coincide(Vecteur &v1, Vecteur &v2)
{
	if((v2.v[0]==v1.v[0])&& (v2.v[1]==v1.v[1]) && (v2.v[2]==v1.v[2]))
		cout <<"true " <<endl;
	else
		cout << "false" <<endl;
}
// fonction somme par reference
void Vecteur :: somme(Vecteur &v1, Vecteur &v2)
{
	Vecteur V;
	V.v[0]=(v1.v[0]+v2.v[0]);
	V.v[1]=(v1.v[1]+v2.v[1]);
	V.v[2]=(v1.v[2]+v2.v[2]);
	cout<< "La somme est :   ";
	V.afficher();
	
}




