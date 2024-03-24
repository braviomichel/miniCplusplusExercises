#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
	int val;
	noeud* suiv;
};

noeud * creerNoeud(){
	noeud *nv=(noeud*)malloc(sizeof(noeud));
	nv->suiv=NULL;
	printf("\nEntrez la valeur :");
	scanf("%d",&nv->val);
	return nv;
}
noeud * creerListe(){
	int N;
	noeud * rac;
	noeud * nv;
	noeud * parc;
	printf("\nEntrez le nombre de noeuds :");
	scanf("%d",&N);
	for(int i=0;i<N;i++){
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
 void creerListe2( noeud ** rac){
 	*rac=creerListe();
 }
 void afficherNoeud(noeud *N){
 	printf("%d\t", N->val);
 }
 void afficherListe(noeud * rac){
 	if(rac!=NULL){
 		afficherNoeud(rac);
 		afficherListe(rac->suiv);
	 }
 }
 int nbNoeud(noeud** rac){
 	int n=0;
 	while(*rac!=NULL){
 		n++;
 		*rac=(*rac)->suiv;
 		
	 }
	 return n;
	 
 }
 int testerVide( noeud** rac){
 	//nbNoeud(rac)==0 ? return 1 : return 0;
 	int n;
 	if((*rac)==NULL)
 		return 1;
 	else
 		return 0;
 }
void supprimerListe(noeud** rac){
	noeud *parc=*rac , *courant;
	while(parc!=NULL){
		courant = parc;
		parc=parc->suiv;
		free(courant);
	}
	*rac=NULL;
}	
void afficherInverse(noeud *rac){
	if(rac!=NULL){
		afficherInverse(rac->suiv);
		afficherNoeud(rac);
	}
}

int main(){
/*	noeud *N =creerNoeud();
	afficherNoeud(N);
	noeud* rac=creerListe();
	afficherListe(rac);
*/
noeud *rac=NULL;
creerListe2(&rac);
afficherListe(rac);	
printf("\nnombre de noeuds: %d\n",nbNoeud(&rac));
printf(" \n liste vide : %d\n",testerVide(&rac));
afficherInverse(rac);
supprimerListe(&rac);
printf(" liste vide %d\n",testerVide(&rac));
	
	
	system("PAUSE");
	}
