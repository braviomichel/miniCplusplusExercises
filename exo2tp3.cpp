#include "employe.h"
#include<string>
#include<iostream>
#include "vendeur.h"
using namespace std;
const int N=1;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//test employe
/*	employe E;
	E.saisie();
	E.afficher();
	cout<<"salaire: "<<E.calcul_salaire()<<endl;
*/	
	//test vendeur
	
/*	vendeur v;
	v.saisie();
	v.afficher();
	cout<<"salaire: "<<v.calcul_salaire()<<endl;
*/	
	
	//fonction main
	
	employe tab[N];
	int i;
	for(i=0;i<N;i++)
	{
		cout<<"employe "<<i+1<<endl;
		tab[i].saisie();
	}
	
	cout<<"affichage des employes"<<endl;
	for(i=0;i<N;i++)
	{
		cout<<"employe " <<i+1<<endl;
		tab[i].afficher();
		cout<<"salaire : "<<tab[i].calcul_salaire()<<endl;
	}
	
	
	
	
	return 0;
}
