#include <iostream>
#include "Compte_Bancaire.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int choix,num,numd;
	float s,retrait,depot,sd,md;
	cout<< "Entrez votre nulero de compte"<< endl;
	cin>>num;
	cout<<"Entrez votre solde "<<endl;
	cin>> s;
	Compte_Bancaire C (num, s);

	do{
		do{
			cout << "Entrez un choix "<<endl;
			cout<< "1.Consulter le solde"<<endl<<"2.Retirer argent"<<endl<<"3.Deposer argent"<<endl<<"4.Effectuer virement"<<endl<<"5.Quitter"<<endl;
			cin>> choix;
		}while ((choix<1)|| (choix>5));
		switch (choix) {
			case 1 :
				cout<< C.getSolde()<<endl;
				break;
			case 2 :
				cout<<"Montant a retirer"<<endl;
				cin>>retrait;
				C.debiter(retrait);
				C.afficher();
				break;
			case 3 :
				cout<<"Montant a deposer"<<endl;
				cin>>depot;
				C.crediter(depot);
				C.afficher();
				break;
			case 4 :
				cout<<"Numero du compte du destinataire"<<endl;
				cin>> numd;
				cout<<"Solde"<<endl;
				cin>>sd;
				cout<<"Montant a virer"<<endl;
				cin>>md;
				Compte_Bancaire Cd(numd,sd);
				C.VirVerser(md,Cd);
				C.afficher();
				Cd.afficher();
				break;
		
		}
				
	}while(choix!=5);
	

	return 0;
}




	/*
	// Tester tous les programmes
	Compte_Bancaire C1(102, 1500.50);
	Compte_Bancaire C2(50, 7000);
	C1.afficher();
	C2.afficher();
	C1.debiter(40.6);
	C1.afficher();
	C2.crediter(900);
	C2.afficher();
	C2.VirVerser(500, C1);
	C2.afficher();
	C1.afficher();*/
