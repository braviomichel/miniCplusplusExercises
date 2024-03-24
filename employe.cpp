#include "employe.h"
#include<iostream>
#include<string>
using namespace std;


employe::employe(string nom,string prenom,unsigned int cne)
{
	this->nom=nom;
	this->prenom=prenom;
	this->cne=cne;
}
void employe::modifier()
