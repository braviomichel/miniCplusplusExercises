#include <iostream>
#include "Etudiant.h"
#include<string>
#include "Etudiant_en_maitrise.h"
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float m;
	int admis,equal;
	Etudiant e;
	//test question1

/*	e.saisie();
	e.affichage();
	m=e.moyenne();
	cout<<endl<<m;
	admis=e.admis();
	cout<<endl<<"admis  "<<admis;
	equal=e.exae_quo(e);
	cout<<endl<<"equal    "<<equal;
	*/
	
	//test question 2
	Etudiant_en_maitrise etu;
	etu.saisie();
	etu.affichage();
	m=etu.moyenne();
	cout<<endl<<m;
	admis=etu.admis();
	cout<<endl<<"admis  "<<admis;
	equal=etu.exae_quo(etu);
	cout<<endl<<"equal    "<<equal;
	
	return 0;
}
