#include <iostream>
#include "Fleur.h"
#include "Bouquet.h"
#include<string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//tests classes 
	Fleur F1;
	F1.affiche();
	// surchage de l'operateur =
	Fleur f2("a","b",50,1,0);
	Fleur f1;
	if(F1!=f1)
		cout<<"different";
	else
		cout<<"non different";
		
	// test bouquet
/*	Bouquet b;
	Fleur f1("a","b",50,0,0),f2("c","d",5000,0,1);
	b+=f1;
	b+=f2;
	if(b.parfum())
		cout<<"parfume";
	else
		cout<<"np";
		
	cout<< b.prix();
	*/	
	return 0;
}
