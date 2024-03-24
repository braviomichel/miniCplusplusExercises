#include "Etudiant_en_maitrise.h"
#include "Etudiant.h"
#include<iostream>
#include<string>
using namespace std;

void Etudiant_en_maitrise:: saisie(){
	Etudiant::saisie();
	cout<<"Entrez la note memoire"<<endl;
	cin>>this->note_memoire;
}

void Etudiant_en_maitrise::affichage() {
	Etudiant::affichage();
	cout<<endl<<"note memoire:"<<note_memoire;
}
float Etudiant_en_maitrise::moyenne(){
	Etudiant::moyenne();
}

int Etudiant_en_maitrise::admis(){
	if((Etudiant::admis()==1)&&(note_memoire>10))
		return 1;
	else
		return 0;
}

int Etudiant_en_maitrise::exae_quo(Etudiant_en_maitrise E){
	if((Etudiant::exae_quo(E)==1)&&(note_memoire==E.note_memoire))
		return 1;
	else
		return 0;
	
}
