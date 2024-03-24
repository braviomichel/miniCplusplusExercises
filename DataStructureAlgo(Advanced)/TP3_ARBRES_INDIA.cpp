#include<iostream>
#include<string>
#include<fstream>
using namespace std;

typedef struct Element{
	int val;
	Element * fg;
	Element * fd;
}element;

class Arbre{
	private:
		element *rac;
	public:
		Arbre();
		Arbre(Arbre &);
		friend element * creerElement(int );
		element ** racine();
		friend void insererElement(element **,element *);
		void creerArbre();
		friend void afficherCroissant(element **);
		friend void afficherDecroissant(element **);
		friend int nbElements();
		friend int nbFeuilles();
		friend void afficherFeuilles();
		friend int calculerProfondeur();
		friend bool chercherElement();
		friend int minArbre(element *);
		friend int maxArbre(element *);
		friend void supprimerArbre(element **);
};




Arbre::Arbre(){
	rac=new element;
	rac=NULL;
}
Arbre::Arbre(Arbre &A){
	rac=new element;
	this->rac=A.rac;
	
}
element ** Arbre::racine(){
	element ** rac =&(this->rac);
	return rac;
}
element* creerElement(int val){
	element *nv;
	nv=new element;
	nv->val=val;
	nv->fd=NULL;
	nv->fg=NULL;
	return nv;
}
void insererElement( element **rac,element * n){
	element* racine=*rac;
	if(*rac==NULL){
		*rac=n;
	}
	else if ((*rac)->val > n->val){
		insererElement(&((*rac)->fg),n);
	}
		
	else
		insererElement(&((*rac)->fd),n);
}
void Arbre::creerArbre(){
	int nb, val;
	element *n;
	cout<<"Entrez le nombre d elements\n : "<<endl;
	cin>>nb;
	element ** rac=racine();
	for(int i=0;i<nb;i++){
		cout<<"Entrez la valeur de l element: "<<endl;
		cin>>val;
		n=creerElement(val);
		insererElement(rac, n);
	}
}

 void afficherCroissant( element **rac){
	if(*rac==NULL)
		return;     
	else {
		afficherCroissant(&(*rac)->fg);
		cout<< (*rac)->val<<"\t";
		afficherCroissant(&((*rac)->fd));
	}

}

 void afficherDecroissant( element **rac){
	if(*rac==NULL)
		return;
	else {
		afficherDecroissant(&(*rac)->fd);
		cout<<(*rac)->val<<"\t";
		afficherDecroissant(&(*rac)->fg);
	}
}

int nbElements(element *rac){
	if(rac==NULL)
		return 0;
	else 
		return 1+ nbElements(rac->fd) + nbElements (rac->fg);
		
}
int nbFeuilles(element *rac){
	if (rac==NULL)
		return 0;
	else if(rac->fd==NULL && rac->fg==NULL)
		return 1;
	else
		return nbFeuilles(rac->fd) + nbFeuilles(rac->fg);
		
}
void afficherFeuilles(element *rac){
	if (rac==NULL)
		return ;
	else if(rac->fd==NULL && rac->fg==NULL)
		cout<<rac->val<<"\t";
	else{
		afficherFeuilles(rac->fd);
		afficherFeuilles(rac->fg);
	}
		
	
}
int max(int a, int b){
	return a > b ? a : b;
}
int calculerProfondeur(element *rac){
	if(rac==NULL)
		return 0;
	else 
		return 1+ max(calculerProfondeur(rac->fd),calculerProfondeur(rac->fg));
}

bool chercherElement(element *rac, int n){
	if(rac==NULL)
		return false;
	else if(rac->val == n)
		return true;
	else if(rac->val > n)
		return chercherElement(rac->fg,n);
	else
		return chercherElement(rac->fd, n);
		
}
int minArbre(element *rac){
	 if(rac==NULL)
	 	return -1;
	else if (rac->fg==NULL)
		return rac->val;
	else 
		return minArbre(rac->fg);
}

int maxArbre(element *rac){
	 if(rac==NULL)
	 	return -1;
	else if (rac->fd==NULL)
		return rac->val;
	else 
		return maxArbre(rac->fd);
}
void supprimerArbre(element ** rac){
	if(*rac!=NULL){
		element *tmp = *rac;
		supprimerArbre(&((*rac)->fg));
		supprimerArbre(&((*rac)->fd));
		delete(tmp);
	}
	*rac=NULL;
}


void enregistrerFichier(element *rac, ofstream *f){
	if(rac!=NULL){
		enregistrerFichier(rac->fg,f);
		*f<<rac->val;
		enregistrerFichier(rac->fd, f);
	}
		
	
}



void initialiserFichier(element ** rac, ifstream *myfile){
		int val;
		element *n;
		while(!(myfile->eof())){
			*myfile >> val;
			n=creerElement(val);
			insererElement(rac, n);
		}
	}
	
int main()
{
	Arbre *A=new Arbre();
	element **rac=A->racine();
	A->creerArbre();
	afficherCroissant(rac);
	cout<<endl<<"Nombre eleemnts: "<<nbElements(*rac)<<endl;
	cout<<endl<<"Min!: "<<minArbre(*rac)<<endl;
	afficherDecroissant(rac);
	cout<<endl<<"Nombre feuilles: "<<nbFeuilles(*rac)<<endl;
	cout<<endl<<"Feuilles : ";
	afficherFeuilles(*rac);
	cout<<endl<<"profondeur: "<<calculerProfondeur(*rac);
	cout<<endl<<"Max!: "<<maxArbre(*rac)<<endl;
	cout<<endl<<"Recherche: "<<chercherElement(*rac, 5);
	//supprimerArbre(rac);


	
}

