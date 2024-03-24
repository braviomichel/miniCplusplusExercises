#include<stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct element {
	int coef;
	int expo;
	element *suiv;
};
element* creerElement(){
	int coeff, expo;
	
	do{
		printf("\n Entrez le coeff: ");
		scanf("%d",&coeff);
	}while(coeff==0);
	printf("\n entrez l exposant: ");
	scanf("%d",&expo);
	element *nv=(element*)malloc(sizeof(element));
	nv->coef=coeff;
	nv->expo=expo;
	nv->suiv=NULL;
	return nv;
}
void saisirPoly(element **rac){
	int taille;
	element *parc, *prec;
	printf("\n Entrez le nombre de polynomes: ");
	scanf("%d",&taille);
	for(int i=0;i<taille;i++){
		parc=*rac;
		element *nv=creerElement();
		if(*rac==NULL){
			*rac=nv;
		}
			
		else if(parc->expo < nv->expo){
			nv->suiv=parc;
			*rac=nv;
		}
		else{
			while((parc->expo > nv->expo) && (parc->suiv!=NULL)){
				prec=parc;
				parc=parc->suiv;
			}
			if(parc->suiv==NULL){
				parc->suiv=nv;
			}
			else{
				nv->suiv=parc;
				prec->suiv=nv;
			}
		}
	}
}

void afficherPoly(element *rac){
	element *parc=rac;
	if(rac==NULL)
		printf("\nListe VIde : ");
	else{
		while(parc!=NULL){
			printf("[%dx^%d]\t", parc->coef, parc->expo);
			parc=parc->suiv;
		}
		printf("\n");
	}
}

float EvaluerPoly(element *rac, float x){
	element *parc=rac;
	int P=0;
	while(parc!=NULL){
		P+= (parc->coef*pow(x,parc->expo));
		parc=parc->suiv;
	}
	return P;
}
element* creerElement2( int coeff, int expo){
		element *nv=(element*)malloc(sizeof(element));
		nv->coef=coeff;
		nv->expo=expo;
		nv->suiv=NULL;
		return nv;
}

void ajouterPoly( element **rac, int coeff, int expo){
	element *nv=creerElement2( coeff, expo);
	element *parc=*rac, *prec;
		if(*rac==NULL){
			*rac=nv;
			parc=nv;
		}
		else if(parc->expo < nv->expo){
			nv->suiv=parc;
			*rac=nv;
			
		}
		else{
			while((parc->expo > nv->expo) && (parc->suiv!=NULL)){
				prec=parc;
				parc=parc->suiv;
			}
			if(parc->suiv==NULL){
				parc->suiv=nv;
			}
			else{
				nv->suiv=parc;
				prec->suiv=nv;
			}
		}
}
float derivee(element *rac, int x){
	element *parc=rac;
	int P=0;
	while(parc!=NULL){
		P+= (parc->coef*parc->expo*pow(x,parc->expo-1));
		parc=parc->suiv;
	}
	return P;
}
int main()
{
	element *rac=NULL;
	saisirPoly(&rac);
	afficherPoly(rac);
	printf("Evaluation : %f",EvaluerPoly(rac,1));
	ajouterPoly(&rac, 8,2);
	afficherPoly(rac);
	printf("Derivee : %f",derivee(rac,1));
	afficherPoly(rac);

}
