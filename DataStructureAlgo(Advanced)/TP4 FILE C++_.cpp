#include<iostream>
#include<string>
#include<fstream>
using namespace std;

typedef struct file{
	int taille, fin , debut;
	int *tab;
};
class File{
	private :
		file f;
	public :
		File(int); //init
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
		void enregistrer( string, int );//nombre d elements à traiter
};

File::File( int taille){
	this->f.tab= new int[taille];
	this->f.debut=0;
	this->f.fin=0;
	this->f.taille=taille;
}

int File::testerVide(){
	if(this->f.debut == this->f.fin)
		return 1;
	else
		return 0;	
}

int File::testerPlein(){
	if(this->f.debut == ((this->f.fin +1) % this->f.taille))
		return 1;
	else
		return 0;
}

void File::etendre(int tailleAjout){
	int *t=new int[(this->f.taille + tailleAjout)];
	int i,j=0;
	for(i=this->f.debut; i % this->f.taille != this->f.fin ;++i % this->f.taille){
		t[j++]=this->f.tab[i];
	}
	this->f.fin =j;
	this->f.debut =0;
	this->f.taille += tailleAjout;
	this->f.tab=t;
}
void File::inserer(int val){
	if(this->testerPlein())
		this->etendre(10);
	this->f.tab[this->f.fin]=val;
	this->f.fin ++;
	this->f.fin %= this->f.taille;
	
}
 int File::retirer(){
 	if(this->testerVide())
 		return -1;
 	int val=this->f.tab[f.debut];
 	this->f.debut++;
 	this->f.debut %= this->f.taille;
 	return val;
 }

void File::afficher(){
	if(this->testerVide()){
		cout<<"file vide"<<endl;
		return;
	}
	int i;
	cout<<"File : ";
	for(i=this->f.debut; i%this->f.taille != this->f.fin; ++i % this->f.taille){
		cout<<this->f.tab[i]<<"\t";
	}
}

int File::nbElement(){
	int nb=0;
	for(int i=this->f.debut; i%this->f.taille != this->f.fin; ++i % this->f.taille){
		nb++;
	}
	return nb;
}

void File::vider(){
	if(this->testerVide())
		return;
	this->f.debut=0;
	this->f.fin=0;
}
 
void File::sauvegarder(string pathname){
	ofstream myfile(pathname.c_str(), ios::app);
	if (!myfile){
		return;
	}
	else{
		for(int i=this->f.debut; i%this->f.taille != this->f.fin; ++i % this->f.taille){
			myfile << this->f.tab[i]<<" ";
		}
	
	}
}


void File::initialiser(string pathname){
	int valeur;
	ifstream myfile("file.txt"); 

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
void File::enregistrer(string pathname, int n){ //n represente le nombre d elements à traiter
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
	File f1(2);
	File f2(2);
	string pathname ="file.txt";
	string pathname2="file_supp.txt";
	cout<<"vide!: "<<f1.testerVide()<<endl;
	cout<<"plein!: "<<f1.testerPlein()<<endl;
	f1.inserer(2);
	f1.inserer(3);
	f1.inserer(5);
	cout<<"nbElement: "<<f1.nbElement()<<endl;
	f1.inserer(4);
	f1.afficher();
	cout<<endl<<"element retire: "<<f1.retirer()<<endl;
	f1.afficher();
	f1.sauvegarder(pathname);
	/*f2.initialiser(pathname);
	f2.afficher();*/
	f1.enregistrer(pathname2,2);
	//f1.afficher();

}
