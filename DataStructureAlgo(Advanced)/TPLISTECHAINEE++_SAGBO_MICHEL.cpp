#include <iostream>
#include <fstream>
#include<string>

using namespace std;

typedef struct Noeud{
	int val;
	Noeud * suiv;
}noeud;

class ListeSimple
{
	private:
		noeud * rac;
		int nbElement;
	public:
		ListeSimple();
		ListeSimple(ListeSimple &);
		void creerListe();
		void afficherListe();
		int nbNoeuds();
		int testerVide();
		void supprimerListe();
		void insererDebut(int val);
		void supprimerDebut();
		void insererFin( int val);
		void supprimerFin();
		void effectuerRotation(int ordre);
		int appartenir(int n);
		void trierListe();
		void insererTrie(int val);
		void supprimerTrie(int val);
		friend noeud * creerNoeud(int n);
		friend void afficherInverse();
		noeud * racine();
		int enregistrerListeFichier( string pathname );
		void initialiserListeFichier(string pathname);
		 
};

noeud * creerNoeud(int n){
	noeud * nv;
	nv=new noeud;
	nv->suiv=NULL;
	nv->val=n;
	return nv;
}


ListeSimple :: ListeSimple(){
	this->rac=new noeud;
	this->rac->suiv = NULL;
	this->rac->val = 0;
	nbElement=0;
}


ListeSimple::ListeSimple(ListeSimple &L){
	this->rac=new noeud;
	this->rac=L.rac;
	this->nbElement=L.nbElement;
}


void ListeSimple :: creerListe(){
	noeud *parc,*nv;
	int N,val;
	cout<<"Quel est le nombre de noeuds? :"<< endl;
	cin>>N;
	for(int i=0;i<N;i++){
		cout<<"\nEntrez la valeur de l element: "<<endl;
		cin>>val;
		nv=creerNoeud(val);
		this->nbElement++;
		
		if(i==0){
			this->rac=nv;
			parc=nv;
		}
		else{
			parc->suiv=nv;
			parc=parc->suiv;
		}
	}
}


void ListeSimple :: afficherListe(){
	noeud *parc=this->rac;
	if(parc==NULL)
		cout<<"\nListe vide"<<endl;
	while(parc!=NULL){
		cout<<parc->val<<"   ";
		parc=parc->suiv;
	}
	cout<<endl;
}


int ListeSimple::nbNoeuds(){
	return nbElement;
}


int ListeSimple :: testerVide(){
	if(this->nbNoeuds()!=0)
		return 1;
	else 
		return 0;
}


void ListeSimple :: supprimerListe(){
	noeud *tmp, *parc=this->rac;
	while(parc->suiv!=NULL){
		tmp=parc;
		parc=parc->suiv;
		delete(tmp);
	}
	this->rac=NULL;
	this->nbElement=0;
}


noeud* ListeSimple::racine(){
	noeud* r=this->rac;
	return r;
}


void afficherInverse(noeud *rac){
	noeud *parc=rac;
	if(parc!=NULL){
		afficherInverse(parc->suiv);
		cout<<parc->val<<"   ";
	}
	
}


void ListeSimple :: insererDebut(int val){
	noeud *nv;
	nv=creerNoeud(val);
	if(this->rac==NULL){
		this->rac=nv;
	}
	else{
		nv->suiv=this->rac;
		this->rac=nv;
	}
		
}


void ListeSimple :: supprimerDebut(){
	noeud *tmp;
	if(this->rac==NULL)
		return;
	else{
		tmp=this->rac;
		this->rac=this->rac->suiv;
		delete(tmp);
	}
	this->nbElement--;
}


void ListeSimple :: insererFin( int val){
	noeud *nv, *parc=this->rac;
	nv=creerNoeud(val);
	if(this->rac==NULL){
		this->rac=nv;
	}
	else{
		while(parc->suiv!=NULL){
			parc=parc->suiv;
		}
		parc->suiv=nv;
	}
}


void ListeSimple :: supprimerFin(){
	noeud *tmp, *parc=this->rac;
	 if((parc->suiv==NULL)||(parc==NULL)){
	 	this->supprimerDebut();
	 }
	 else{
	 	while(parc->suiv->suiv!=NULL){
	 		parc=parc->suiv;
		 }
		 tmp=parc->suiv;
		 parc->suiv=NULL;
		 delete(tmp);
	 }
	 this->nbElement--;
}


void ListeSimple::effectuerRotation( int ordre){
	noeud *parc1,*parc2;
	if(this->nbNoeuds()>ordre)
		ordre%=this->nbNoeuds();
	for(int i=0;i<ordre;i++){
		parc1=this->rac;
		parc2=this->rac;
		while(parc2->suiv!=NULL){
			parc2=parc2->suiv;
		}
			
		this->rac=parc1->suiv;
		parc2->suiv=parc1;
		parc1->suiv=NULL;
	}
}


int  ListeSimple :: appartenir(int n){
	noeud *parc=this->rac;
	while(parc!=NULL){
		if(parc->val==n)
			return 1;
		parc=parc->suiv;
	}
	return 0;
	
}


void ListeSimple :: trierListe(){
	
	if((this->rac==NULL)||((this->rac)->suiv==NULL)){
		return;
	}
	
	int ordre;
	do{
		noeud *precedent = NULL;
		noeud * parc=this->rac;
		noeud * suivant =parc->suiv;
		ordre=0;
		while(suivant!=NULL){
			if(suivant->val < parc->val){
				ordre = 1;
				if(precedent==NULL){
					parc->suiv = suivant->suiv;
					suivant->suiv = parc;
					this->rac = suivant;
					}
				else if(parc->suiv->suiv==NULL){
					precedent->suiv=suivant;
					suivant->suiv=parc;
					parc->suiv=NULL;
				}
				else{
					precedent->suiv=suivant;
					parc->suiv=suivant->suiv;
					suivant->suiv=parc;
				
				}
				
				precedent = suivant;
				suivant = parc->suiv;
		
			}
			else{
				precedent = parc;
				parc = parc->suiv;
				suivant = parc->suiv;
			}
		}
	}while(ordre);
	

	
}


void ListeSimple :: insererTrie(int val){
	noeud *nv;
	nv=creerNoeud(val);
	noeud *parc=this->rac;
	noeud *precedent =NULL;
	if(parc->val > nv->val){
		nv->suiv=parc;
		this->rac=nv;
	}
	else{
		while((parc!=NULL) && (parc->val<nv->val)){
			precedent=parc;
			parc= parc->suiv;
		}
		precedent->suiv=nv;
		nv->suiv=parc;
	}
	this->nbElement++;
}


void ListeSimple :: supprimerTrie(int val){
	if(this->appartenir(val)==0)
		return;
	noeud * precedent=NULL;
	noeud *parc=this->rac;
	while(parc->val!=val){
		precedent=parc;
		parc=parc->suiv;
	}
	if(precedent==NULL)
		this->rac=parc->suiv;
	else
		precedent->suiv=parc->suiv;
	
	delete(parc);
	this->nbElement--;
}


int ListeSimple:: enregistrerListeFichier( string pathname ){
	ofstream myfile(pathname.c_str(), ios::app);
	if ((!myfile) || (rac==NULL)){
		return(0);
	}
	else{
		noeud *parc=this->rac;
		while(parc!=NULL){
			myfile << parc->val;
			parc=parc->suiv;
		}
		return 1;
	}
}


void ListeSimple::initialiserListeFichier(string pathname){
	ifstream myfile(pathname.c_str(), ios::app);
	if(!myfile)
		return;       
	else{
		int v;
		while(myfile.seekg(0,ios::beg) != myfile.seekg(0,ios::end) ){
			
			myfile >>v;
			this->insererFin(v);
		}  
		
	}
}


int main() {
	ListeSimple *L=new ListeSimple();
	L->creerListe();
	L->afficherListe();
	//cout<<"Affichage Inverse:" ; 
	//afficherInverse(L->racine());
	/*cout<<"nombre de noeuds: "<<L->nbNoeuds()<<endl;
	cout<<"Liste vide: "<<L->testerVide()<<endl;
	L->insererDebut(4);
	L->afficherListe();
	L->supprimerDebut();
	L->afficherListe();
	L->insererFin(10);
	L->afficherListe();
	L->supprimerFin();
	L->afficherListe();
*/
	/*cout<<"appartenance"<<L->appartenir(6)<<endl;
	L->trierListe();
	cout<<"Liste triee"<<endl;
	L->afficherListe();
	L->insererTrie(4);
	L->afficherListe();
	L->supprimerTrie(5);
	L->afficherListe();
	*/
	//L->effectuerRotation(2);
	//L->afficherListe();
	
	string  pathname("listee.txt");
	cout<<endl<<L->enregistrerListeFichier(pathname)<<endl;
	L->initialiserListeFichier(pathname);
	L->afficherListe();
	
}
