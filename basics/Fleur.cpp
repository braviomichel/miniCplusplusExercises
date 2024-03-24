#include "Fleur.h"
#include<string>
#include<iostream>
using namespace std;


Fleur::Fleur(string espece,string couleur, double prix_base, bool parfumee, bool promotion)
{
	this->espece=espece;
	this->couleur=couleur;
	this->prix_base=prix_base;
	this->parfumee=parfumee;
	this->promotion=promotion;
}

void Fleur :: affiche()
{
	cout<<"Espece= "<<espece<<endl;
	cout<<"couleur= "<<couleur<<endl;
	cout<<"prixbase= "<<prix_base<<endl;
	cout<<"parfumee= "<<parfumee<<endl;
	cout<<"promotion= "<<promotion<<endl;
}

bool Fleur :: operator !=(Fleur f1)
{
	return ((f1.couleur!=couleur)&&(f1.espece!=espece)&&(f1.prix_base!=prix_base)&&(f1.parfumee!=parfumee)&&(f1.promotion!=promotion));
 } 
