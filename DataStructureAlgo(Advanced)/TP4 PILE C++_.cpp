#include<iostream>
#include<string>
#include<fstream>
using namespace std;

typedef struct pile{
	int taille, fin;
	int *tab;
};
class Pile{
	private :
		pile p;
	public :
		Pile(int); //init
		int testerVide();
		int testerPlein();
		void etendre(int);
		void inserer( int );
		int retirer();
		void afficher();
		int nbElement();
		void vider();
		void sauvegarder( string );
		void initialiser(string);
		void enregistrer( string);
		void enregistrer( string, int );//nombre d elements à traiter
};

Pile::Pile( int taille){
	this->p.tab= new int[taille];
	this->p.fin=0;
	this->p.taille=taille;
}

int Pile::testerVide(){
	if(this->p.fin == 0)
		return 1;
	else
		return 0;	
}

int Pile::testerPlein(){
	if( ((this->p.fin +1) % this->p.taille) == 0)
		return 1;
	else
		return 0;
}

void Pile::etendre(int tailleAjout){
	int *t=new int[(this->p.taille + tailleAjout)];
	int i,j=0;
	for(i=0; i % this->p.taille != this->p.fin ;++i % this->p.taille){
		t[j++]=this->p.tab[i];
	}
	this->p.fin =j;
	this->p.taille += tailleAjout;
	this->p.tab=t;
}
void Pile::inserer(int val){
	if(this->testerPlein())
		this->etendre(10);
	this->p.tab[this->p.fin]=val;
	this->p.fin ++;
	this->p.fin %= this->p.taille;
	
}
 int Pile::retirer(){
 	if(this->testerVide())
 		return -1;
 	int val=this->p.tab[p.fin-1];
 	this->p.fin--;
 	this->p.fin %= this->p.taille;
 	return val;
 }

void Pile::afficher(){
	if(this->testerVide()){
		cout<<"pile vide"<<endl;
		return;
	}
	int i;
	cout<<"Pile : ";
	for(i=0; i%this->p.taille != this->p.fin; ++i % this->p.taille){
		cout<<this->p.tab[i]<<"\t";
	}
}

int Pile::nbElement(){
	int nb=0;
	for(int i=0; i%this->p.taille != this->p.fin; ++i % this->p.taille){
		nb++;
	}
	return nb;
}

void Pile::vider(){
	if(this->testerVide())
		return;
	this->p.fin=0;
}

void Pile::sauvegarder(string pathname){
	ofstream myfile(pathname.c_str(), ios::app);
	if (!myfile){
		return;
	}
	else{
		for(int i=0; i%this->p.taille != this->p.fin; ++i % this->p.taille){
			myfile << this->p.tab[i]<<" ";
		}
	
	}
}

void Pile::initialiser(string pathname){
	int valeur;
	ifstream myfile("pile.txt"); 

	if(!myfile)
		return;       
	else{
		while(!myfile.eof()){
			myfile >>valeur;
			this->inserer(valeur);
			}
		}
	myfile.close();
}

void Pile::enregistrer(string pathname, int n){ //n represente le nombre d elements à traiter
	ofstream myfile(pathname.c_str(), ios::app);
	if ((!myfile) || (this->nbElement()<n)){
		return;
	}
	else{
		for(int j=0;j<n;j++){
			int val=this->retirer();
			myfile << val<<" ";
		}
	
	}
}

int main(){
	Pile p1(2);
	Pile p2(2);
	string pathname ="pile.txt";
	string pathname2="pile_supp.txt";
	cout<<"vide!: "<<p1.testerVide()<<endl;
	cout<<"plein!: "<<p1.testerPlein()<<endl;
	p1.inserer(2);
	p1.inserer(3);
	p1.inserer(5);
	cout<<"nbElement: "<<p1.nbElement()<<endl;
	p1.inserer(4);
	p1.afficher();
	cout<<endl<<"element retire: "<<p1.retirer()<<endl;
	p1.afficher();
	p1.sauvegarder(pathname);
	//p2.initialiser(pathname);
	//p2.afficher();
	p1.enregistrer(pathname2,2);
}
