#include<stdio.h>
#include<stdlib.h>


/*********************ARBRES*******************************/
typedef struct elementArbre {
	int val;
	elementArbre *fg;
	elementArbre *fd;
};

elementArbre * creerElementArbre(int val){
	elementArbre *nv= (elementArbre *)malloc(sizeof(elementArbre));
	nv->fd=NULL;
	nv->fg=NULL;
	nv->val=val;
	return nv;
}
void insererElementArbre(elementArbre **rac, elementArbre *n){
	if(*rac==NULL)
		*rac=n;
	else if((*rac)->val < n->val)
		insererElementArbre(&(*rac)->fd,n);
	else
		insererElementArbre(&(*rac)->fg, n);
		
}

void creerArbre(elementArbre **rac){
	elementArbre *nv;
	int val, nb;
	printf("\nEntrez le nombre de noeuds :");
	scanf("%d",&nb);
	for(int i=0;i<nb;i++){
		printf("\nEntrez l'element: ");
		scanf("%d",&val);
		nv=creerElementArbre(val);
		insererElementArbre(rac,nv);
	}                     
}
void afficherArbre(elementArbre *rac){
	if(rac!=NULL){
		afficherArbre(rac->fg);
		printf("%d\t",rac->val);
		afficherArbre(rac->fd);
	}
}

int chercherElementArbre(elementArbre *rac, int n){
	if(rac==NULL)
		return 0;
	else if(rac->val==n)
		return 1;
	else if(rac->val<n){
		return chercherElementArbre(rac->fd, n);
	}
	else{
		return chercherElementArbre(rac->fg, n);
	}
}

elementArbre * successeur(elementArbre *rac){
	elementArbre *parc=rac;
	while(parc->fg != NULL){
		parc=parc->fg;
	}
	return parc;
}
void supprimerElementArbre(elementArbre **rac, int n){
	if(*rac==NULL)
		return;
	if(n < (*rac)->val)
		supprimerElementArbre(&((*rac)->fg),n);
	else if(n > (*rac)->val)
		supprimerElementArbre(&((*rac)->fd),n);
	else{
		
		if((*rac)->fg ==NULL){
			elementArbre *tmp=(*rac)->fd;
			*rac=NULL;
			free(tmp);
		}
		else if((*rac)->fd ==NULL){
			elementArbre *tmp=(*rac)->fg;
			*rac=NULL;
			free(tmp);
		}
		
		elementArbre* suiv=successeur((*rac)->fd);
		(*rac)->val=suiv->val;
		supprimerElementArbre(&((*rac)->fd), suiv->val);

		
	}
}


/***************************LISTES CHAINEES****************/

typedef struct elementListe{
	int val;
	elementListe *suiv;
};

elementListe* creerElementListe(int val){
	elementListe *nv=(elementListe*)malloc(sizeof(elementListe));
	nv->suiv=NULL;
	nv->val=val;
	return nv;
}
void insererFinListe(elementListe **rac,int val){
	elementListe *nv, *parc=*rac;
	nv=creerElementListe(val);
	if(*rac==NULL)
		*rac=nv;
	else{
		while(parc->suiv!=NULL){
			parc=parc->suiv;
		}
		parc->suiv=nv;
	}
}
void creerListe(elementListe **rac){
	int nb, val;
	elementListe *nv;
	printf("\n Entrez le nombre d elements : ");
	scanf("%d", &nb);
	for(int i=0;i<nb;i++){
		printf("\nEntrez l element : ");
		scanf("%d",&val);
		insererFinListe( rac, val);
		
	}
}

void afficherListe(elementListe *rac){
	elementListe *parc=rac;
	printf("\nListe Chainee : ");
	while(parc!=NULL) {
		printf("%d\t",parc->val);
		parc=parc->suiv;
	}
}

/*********************LISTES CIRCULAIRES**************/

typedef struct elementCirculaire{
	int val;
	elementCirculaire *suiv;
	elementCirculaire *prec;	
};
elementCirculaire * creerElementCirculaire(int val){
	elementCirculaire *nv;
	nv=(elementCirculaire *)malloc(sizeof(elementCirculaire));
	nv->prec=nv;
	nv->suiv==nv;
	nv->val=val;
	return nv;
}

void insererFinCirculaire(elementCirculaire **rac, int val){
	elementCirculaire *nv=creerElementCirculaire(val);
	if(*rac==NULL)
		*rac=nv;
	else{
		nv->suiv=*rac;
		nv->prec=(*rac)->prec;
		(*rac)->prec->suiv=nv;
		(*rac)->prec=nv;
		
	}
}
void creerListeCirculaire(elementCirculaire **rac){
	int nb, val;
	printf("\n Entrez le nombre d elements circulaires : ");
	scanf("%d",&nb);
	for(int i=0;i<nb;i++){
		printf("\nEntrez l elemeent :");
		scanf("%d", &val);
		insererFinCirculaire(rac, val);
	}
}

void afficherCirculaire(elementCirculaire *rac){
	elementCirculaire *parc=rac;
	printf("\nListe Circulaire : ");
	do{
		printf("%d\t",parc->val);
		parc=parc->suiv;
	}while(parc!=rac);
	
}


/*************FONCTIONS DE CONVERSIONS*****************/

void arbreToChaineSimple(elementArbre *racA, elementListe **racL){
	if(racA!=NULL){
		arbreToChaineSimple(racA->fg,racL);
		insererFinListe(racL, racA->val);
		arbreToChaineSimple(racA->fd,racL);
	}
}

void chaineSimpleToArbre(elementArbre **racA, elementListe *racL){
	elementListe *parc=racL;
	while(parc!=NULL) {
		elementArbre *nv=creerElementArbre(parc->val);
		insererElementArbre( racA, nv);
		parc=parc->suiv;
	}
}
void arbreToChaineDC(elementArbre *racA, elementCirculaire **racC){
	if(racA!=NULL){
		arbreToChaineDC(racA->fg,racC );
		insererFinCirculaire(racC, racA->val);
		arbreToChaineDC(racA->fd, racC);
	}
}

void chaineDCtoArbre(elementArbre **racA, elementCirculaire *racC){
	elementCirculaire *parc=racC;
	while(parc!=racC){
		elementArbre *nv=creerElementArbre(parc->val);
		insererElementArbre(racA,nv );
		parc=parc->suiv;
	}
}

/*************************main*************************/

int main(){
	elementArbre *racA1=NULL, *racA2=NULL,*racA3=NULL;
	elementListe *racL1=NULL, *racL2=NULL;
	elementCirculaire *racC1=NULL, *racC2=NULL;
	

	
	creerArbre(&racA1);
	afficherArbre(racA1);
	//supprimerElementArbre(&racA1, 5);
	//afficherArbre(racA1);
	
	creerListe(&racL1);
	afficherListe(racL1);
	
	creerListeCirculaire(&racC1);
	afficherCirculaire(racC1);
	
	arbreToChaineSimple(racA1,&racL2);
	afficherListe(racL2);
	
	chaineSimpleToArbre(&racA2,racL1);
	afficherArbre(racA2);
	
	arbreToChaineDC(racA1,&racC2);
	afficherCirculaire(racC2);
	
	chaineDCtoArbre(&racA3,racC1);
	printf("\n");
	afficherArbre(racA3);

}
