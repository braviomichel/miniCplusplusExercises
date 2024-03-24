#include<stdio.h>
#include<stdlib.h>


/**********************************ARBRES************************/



typedef struct elementA {
	int val;
	elementA* fg;
	elementA * fd;
};


elementA * creerElementA(int val){
	elementA * nv = (elementA*)malloc(sizeof(elementA));
	nv->val=val;
	nv->fg=NULL;
	nv->fd=NULL;
	return nv;
}
void insererElementA(elementA ** rac ,elementA * n){
	if (*rac==NULL)
		*rac=n;
	else if((*rac)->val > n->val)
		insererElementA(&((*rac)->fg), n);
	else
		insererElementA(&((*rac)->fd), n);
}

void creerArbre(elementA **rac){
	int nb, val;
	elementA * n;
	printf ("Nombre d elements!: ");
	scanf("%d",&nb);
	for (int i=0;i<nb;i++){
		printf ("entrez un nombre:  ");
		scanf("%d",&val);
		n=creerElementA(val);
		insererElementA(rac, n);
	}
}
int chercherElementA(elementA *rac, int n){
	if(rac->val==n)
		return 1;
	else if(rac->val<n){
		return chercherElementA(rac->fd, n);
	}
	else if((rac->val>n)) {
		return chercherElementA(rac->fg, n);
	}
	
	return 0;

}


elementA * recherche(elementA* rac ,int val){
	elementA *parc=rac, *prec=NULL;
	if(rac==NULL)
		parc=rac;
	else if(rac->val < val){
		prec=rac;
		parc=recherche(rac->fg,val);
		}
	else{
		prec=rac;
		parc=recherche(rac->fd, val);
	}
	return prec;
}


void afficherCroissantA(elementA *rac){
	if(rac!=NULL){
		afficherCroissantA(rac->fg);
		printf("%d\t",rac->val);
		afficherCroissantA(rac->fd);
	}
}


/************************************LISTE SIMPLEMENT CHAINEE********************************/

typedef struct elementL{
	int val;
	elementL *suiv;
};
elementL * creerElementL(int n){
	elementL * nv;
	nv=(elementL *) malloc(sizeof(elementL));
	nv->suiv=NULL;
	nv->val=n;
	return nv;
}

void  creerListe(elementL **rac){
	elementL *parc, *nv;
	int N,val;
	printf("Quel est le nombre de noeuds? :");
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		printf("\nEntrez la valeur de l element: ");
		scanf("%d",&val);
		nv=creerElementL(val);
		if(i==0){
			*rac=nv;
			parc=nv;
		}
		else{
			parc->suiv=nv;
			parc=parc->suiv;
		}
	}
	
}
void afficherElementL(elementL *N){
	printf("%d\t",N->val);	
}

void afficherListe(elementL *rac){
	elementL *parc=rac;
	if(parc==NULL)
		printf("\nListe vide");
	while(parc!=NULL){
		afficherElementL(parc);
		parc=parc->suiv;
	}
	printf("\n");
}



void insererFinL(elementL** rac, int v){
	elementL *nv, *parc=*rac;
	nv=creerElementL(v);
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

/***********************************LISTE CIRCULAIRES*****************************************/

typedef  struct elementDC{
	int val;
	elementDC* suiv;
	elementDC * prec;
	
};
 elementDC * creerElementDC( int val){
 	elementDC * nv=(elementDC*) malloc(sizeof(elementDC));
 	nv->val=val;
 	nv->suiv=nv;
 	nv->prec= nv;
 	return nv;
 }
 
 elementDC * insererDebutDC(elementDC *rac, int val){
 	elementDC *nv= creerElementDC(val);
	 if(rac==NULL)
	 	rac=nv;
	else{
		nv->suiv=rac;
		nv->prec= rac->prec;
		rac->prec->suiv=nv;
		rac->prec=nv;
		rac=nv;
	}
	return rac;
 }
 
 elementDC * creerListe(){
 	int n, val;
 	elementDC *rac=NULL;
 	printf("\nNombre d elements :");
 	scanf("%d",&n);
 	for(int i=0;i<n ;i++){
 		printf("\nEntrez la valeur: ");
 		scanf("%d", &val);
 		rac=insererDebutDC(rac, val);
	 }
	 return rac;
 }
 
 void parcoursEndroit(elementDC *rac){
 	if(rac==NULL)
 		printf("\n Liste vide");
	else{
		printf("\n Parcours Endroit :");
		elementDC *parc=rac;
		do {
			printf("%d\t", parc->val);
			parc=parc->suiv;
		}while(parc!=rac);
	}
 	
 }

/*************************************************MAIN******************************/


int main(){
	
	/*********************ARBRE***************/
	elementA *rac=NULL;
	creerArbre(&rac);
	afficherCroissantA(rac);
	printf("\nRecherche: %d\t",chercherElementA(rac, 4));
	//elementA *prec=recherche(rac,4);
	//printf(" \n Revherche %d", prec->val);
	/********LISTE CAHINE******************/
	
	
	
	/*****************LISTES CIRCULAIRES********************/
}
