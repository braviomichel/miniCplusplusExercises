#include "vendeur.h"
#include "employe.h"
#include<string>
#include<iostream>
using namespace std;

vendeur::vendeur(int code,std::string nom,int jour, int mois,int annee, int nombre_heure,float taux_de_remu , float m_vente,float pourcentage ):employe( code,nom, jour,mois,annee,nombre_heure,taux_de_remu)
{

	this->m_vente=m_vente;
	this->pourcentage=pourcentage;
}
void vendeur::saisie(){
	employe::saisie();
	cout<<"Entrez le montant des ventes: "<<endl;
	cin>>this->m_vente;
	cout<<"Entrez le pourcentage: "<<endl;
	cin>>this->pourcentage;
}
void vendeur::afficher(){
	employe::afficher();
	cout<<" montant des ventes: "<<m_vente<<endl;
	cout<<" pourcentage "<<pourcentage<<endl;
}
float vendeur::calcul_salaire(){
	return (employe::calcul_salaire() + (m_vente*pourcentage));
}
