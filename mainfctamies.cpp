#include <iostream>
#include "vect.h"
#include "matrice.h"
using namespace std;



int main(int argc, char** argv) {
	vect V1(4,5,6),V2;
	matrice M1;
	M1.saisie();
	M1.affiche();
	cout<<"vecteur: "<<endl;
	V1.affiche();
	V2=M1.prod(V1);
	cout<<"produit: "<<endl;
	V1.affiche();
	return 0;
}
