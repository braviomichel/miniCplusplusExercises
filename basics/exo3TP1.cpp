#include <iostream>
#include "Rectangle.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int choix, l,h,nh,nl;
	cout<<"Entrez la hauteur"<<endl;
	cin>>h;
	cout<<"Entrez la largeur"<<endl;
	cin>>l;
	Rectangle r(l,h);
	do{
		do{
			cout << "Entrez un choix "<<endl;
			cout<< "1.Modifier Largeur"<<endl<<"2.Modifier Hauteur"<<endl<<"3.Calculer les proprietes"<<endl<<"4.Afficher le recantgle"<<endl<<"5.Quitter"<<endl;
			cin>> choix;
		}while ((choix<1)|| (choix>5));
		switch (choix) {
			case 1 :
				cout<< "Entrez la nouvelle hauteur"<<endl;
				cin>> nh;
				r.modifier_hauteur(nh);
				break;
			case 2 :
				cout<< "Entrez la nouvelle largeur"<<endl;
				cin>> nl;
				r.modifier_hauteur(nl);
				break;
			case 3 :
				cout<<"Aire du rectangle "<<r.calcule_aire()<<endl;
				cout<<"Perimetre du rectangle "<<r.calcule_perimetre()<<endl;
				break;
			case 4 :
				r.affiche();
				break; 
				 }
	
	}while(choix!=5);
	
	return 0;
}
