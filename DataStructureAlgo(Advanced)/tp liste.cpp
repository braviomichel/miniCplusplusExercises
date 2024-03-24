

#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud{
	int val;
	noeud * suiv;
} noeud;

noeud* creerNoeud(){
	noeud * nv = (noeud*)malloc(sizeof(noeud));
	int val;
	printf("\nEntrez l element:");
	scanf("%d", &val);
	nv->val= val;
	nv->suiv=NULL;
	return nv;
}

noeud * creerListe()  {
	int n;
	noeud *rac=NULL;
	noeud *nv;
	noeud *parc=NULL;
	printf("\nEntrez le nombre d elements:");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		nv=creerNoeud();
		if(i==0){
			rac=nv;
			parc=nv;
		}
		
		else{
			parc->suiv=nv;
			parc=parc->suiv;
		}
	}
	return rac;
}
void creerListe2(noeud ** rac){
	int n ,val;
	noeud *nv;
	noeud *parc=NULL;
	printf("\nEntrez le nombre d elements:");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		nv=creerNoeud();
		if(i==0){
			*rac=nv;
			parc=*rac;
		}
		
		else{
			parc->suiv=nv;
			parc=parc->suiv;
		}
	}

}

void afficherNoeud(noeud *N){
	printf("%d\t", N->val);
}
void afficherListe(noeud * rac){
	while(rac!=NULL){
		afficherNoeud(rac);
		afficherListe(rac->suiv);
	}
}
int nbNoeuds(noeud * rac){
	noeud* parc=rac;
	int n=0;
	if(parc->suiv==NULL)
		return 1;
	else{
		while(parc!=NULL){
			n++;
			parc=parc->suivant;
		}
	
	}
	return n;	
}
int testerVide(noeud * rac) {
	(nbNoeuds(rac))== 0 ? return 1 : return 0;
}
void supprimerListe(noeud *rac){
	noeud *courant=NULL;
	noeud *parc=rac;
	while(parc!=NULL){
		courant=parc;
		parc=parc->suiv;
		free(courant);	
	}
	rac=NULL;
}
void afficherInverse(noeud *rac){
	
	while(rac!=NULL){
		aficherListe(rac->suiv);
		afficherNoeud(rac);
		
	}
}
int main(){
	noeud* N=creerNoeud();
	afficherNoeud(N);
}
