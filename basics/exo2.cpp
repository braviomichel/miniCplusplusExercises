#include<iostream>
using namespace std;
class Compte_Bancaire {
	private: 
		int num_compte;
		float solde;
	public:
	
		Compte_Bancaire(int c,float s)
		{
			num_compte=c;
			solde=s;
		}
		
		void debiter( float montant){
			if(montant>solde)
				cout <<"Impossible de debiter. Solde insuffiasant!" <<endl ;
			else
				solde-=montant;
		}
		
		void crediter (float montant){
			solde+=montant;
		}
		
		void VirVerser(float montant, Compte_Bancaire C)
		{
			debiter(montant);
			C.crediter(montant);
		}
		
		float getSolde()
		{
			return solde;
		}
		
		int getNumero(){
			return num_compte;
		}
		void afficher()
		{
			cout <<"Votre numero de compte est " << num_compte<< " et votre solde est de "<< solde <<endl;
		}
		
};





int main ()
{
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
	
	// menu
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
	
}




