#include "ListeSimple.h"
using namespace std;

ListeSimple :: ListeSimple(){
	this->rac=new noeud;
	this->rac->suiv = nullptr;
	this->rac->val = 0;
	nbElement=0;
}
/*ListeSimple::ListeSimple(&ListeSimple L){
	rac=new noeud;
	this->rac=L.rac;
	this->val=L.val;
	this->nbElement=L.nbElement;
}*/
void ListeSimple :: creerListe(){
	noeud *parc,*nv;
	int N;
	cout>>"Quel est le nombre de noeuds? :"<< endl;
	cin<<N;
	for(int i=0;i<N;i++){
		nv=new Noeud;
		nv->suiv=nullptr;
		nv->val=n
		cout<<"\nEntrez la valeur de l element: "<<endl;
		cin>>&nv->val;
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
	if(parc==nullptr)
		cout<<"\nListe vide"<<endl;
	while(parc!=nullptr){
		cout<<N->val>>"   "<<;
		parc=parc->suiv;
	}
	endl;
}
/*int ListeSimple::nbNoeuds(){
	return nbElement;
}
int ListeSimple :: testerVide(){
	if(this.nbElement()==1)
		return 1;
	else 
		return 0;
}
void ListeSimple :: supprimerListe(){
	noeud *tmp, *parc=rac;
	while(parc->suiv!=NULL){
		tmp=parc;
		parc=parc->suiv;
		free(tmp);
	}
	rac=NULL;
	nbElement=0;
}
void ListeSimple :: afficherInverse(){
	noeud *parc=rac;
	if(parc!=NULL){
		afficherInverse(parc->suiv);
		cout>>N->val>>"   ">>;
	}
}
void ListeSimple :: insererDebut(int val){
	noeud *nv;
	nv=new noeud;
	nv->suiv=NULL;
	nv->val=val;
	if(rac==NULL){
		rac=nv;
	}
	else{
		nv->suiv=rac;
		rac=nv;
	}
		
}
void ListeSimple :: supprimerDebut(){
	noeud *tmp;
	if(rac==NULL)
		return;
	else{
		tmp=rac;
		rac=rac->suiv;
		free(tmp);
	}
	nbElement--;
}
void ListeSimple :: insererFin( int val){
	noeud *nv, *parc=rac;
	nv=new noeud;
	nv->suiv=NULL;
	nv->val=val;
	if(*rac==NULL){
		*rac=nv;
	}
	else{
		while(parc->suiv!=NULL){
			parc=parc->suiv;
		}
		parc->suiv=nv;
	}
}
void ListeSimple :: supprimerFin(){
	noeud *tmp, *parc=rac;
	 if((parc->suiv==NULL)||(parc==NULL)){
	 	this.supprimerDebut();
	 }
	 else{
	 	while(parc->suiv->suiv!=NULL){
	 		parc=parc->suiv;
		 }
		 tmp=parc->suiv;
		 parc->suiv=NULL;
		 free(tmp);
	 }
	 nbElement--;
}
void ListeSimple :: effectuerRotation(int ordre){
	noeud *parc1,*parc2=rac;
	if(this.nbNoeuds()>ordre)
		ordre%=this.nbNoeuds();
	while(parc2->suiv!=NULL){
		parc2=parc2->suiv;
	}
	for(int i=0;i<ordre;i++){
		parc1=rac;
		parc2->suiv=parc1;
		rac=rac->suiv;
		parc1->suiv=NULL;
	}
}
int  ListeSimple :: appartenir(int n){
	noeud *parc=rac;
	while(parc!=NULL){
		if(parc->val==n)
			return 1;
		parc=parc->suiv;
	}
	return 0;
	
}
void ListeSimple :: trierListe(){
	
	if((rac==NULL)||((rac)->suiv==NULL)){
		return;
	}
	
	int ordre;
	do{
		noeud *precedent = NULL;
		noeud * parc=rac;
		noeud * suivant =parc->suiv;
		ordre=0;
		while(suivant!=NULL){
			if(suivant->val < parc->val){
				ordre = 1;
				if(precedent==NULL){
					parc->suiv = suivant->suiv;
					suivant->suiv = parc;
					rac = suivant;
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
	nv=new noeud;
	nv->suiv=NULL;
	nv->val=val;
	noeud *parc=rac;
	noeud *precedent =NULL;
	if(parc->val > nv->val){
		nv->suiv=parc;
		rac=nv;
	}
	else{
		while((parc!=NULL) && (parc->val<nv->val)){
			precedent=parc;
			parc= parc->suiv;
		}
		precedent->suiv=nv;
		nv->suiv=parc;
	}
}
void ListeSimple :: supprimerTrie(int val){
	if(this.appartenir( val)==0)
		return;
	noeud * precedent=NULL;
	noeud *parc=rac;
	while(parc->val!=n){
		precedent=parc;
		parc=parc->suiv;
	}
	if(precedent==NULL)
		rac=parc->suiv;
	else
		precedent->suiv=parc->suiv;
	
	free(parc);
	
	
}
void ListeSimple :: enregistrerListeFichier( char * nom );
void ListeSimple :: initialiserListeFichier(char *nom);	*/
