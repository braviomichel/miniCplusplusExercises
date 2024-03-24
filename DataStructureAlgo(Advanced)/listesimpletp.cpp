#include <iostream>
#include "ListeSimple.h"

using namespace std;

typedef struct Noeud{
	int val;
	Noeud * suiv;
}noeud;


ListeSimple :: ListeSimple(){
	this->rac=new noeud;
	this->rac->suiv = nullptr;
	this->rac->val = 0;
	nbElement=0;
}
int main() {
	ListeSimple *L=new ListeSimple();
	L->creerListe();
	L->afficherListe();

	system("pause");
}


