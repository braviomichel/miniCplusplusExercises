#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Elements1 {
	int numEtu;
	char nom[20];
	float moyenne;
	int etat;
	Elements1 *suiv;
}elements1;

typedef struct Elements2 {
	int numEtu;
	char nom[20];
	float moyenne;
	Elements2 *suiv;
}elements2;

elements1 * creerElementS1(){
	elements1 *nv=(elements1*)malloc(sizeof(elements1));
	printf("\nEntrez le nimEtu: ");
	scanf("%d",&nv->numEtu);
	printf("\nEntrez le nom: ");
	scanf("%s",nv->nom);
	printf("\nEntrez la moyenne: ");
	scanf("%f",&nv->moyenne);
	printf("\nEntrez l etat: ");
	scanf("%d",&nv->etat);
	nv->suiv=NULL;
	return nv;
}
elements2* creerElementS2(int numEtu, char *nom,float moyenne){
	elements2 *nv=(elements2*)malloc(sizeof(elements2));
	nv->numEtu=numEtu;
	for(int j=0;j<strlen(nom);j++){
		nv->nom[j]=nom[j];
	}
	
	nv->moyenne=moyenne;
	nv->suiv=NULL;
	return nv;
}

void construireCroissanteS1(elements1 **rac){
	int taille;
	
	printf("\n Entrez la taille : ");
	scanf("%d",&taille);
	for(int i=0;i<taille;i++){
		elements1 *parc=*rac,*prec;
		elements1 *nv=creerElementS1();
		if(*rac==NULL)
			*rac=nv;
		else if( strcmp(nv->nom, parc->nom)<0){
			nv->suiv=parc;
			*rac=nv;
		}
		else{
			while((strcmp(parc->nom,nv->nom)>0)&&(parc!=NULL)){
				prec=parc;
				parc=parc->suiv;
			}
			if(parc->suiv==NULL)
				parc->suiv=nv;
			else{
				nv->suiv=parc;
				prec->suiv=nv;
			}
		}
	}
}




void construireCroissanteS2(elements2 **rac){
	int taille,numEtu,moyenne;
	char *nom;
	
	printf("\n Entrez la taille : ");
	scanf("%d",&taille);
	for(int i=0;i<taille;i++){
		elements2 *parc=*rac,*prec;
		printf("\nEntrez le nimEtu: ");
		scanf("%d",&numEtu);
		printf("\nEntrez le nom: ");
		scanf("%s",nom);
		printf("\nEntrez la moyenne: ");
		scanf("%f",&moyenne);
		elements2 *nv=creerElementS2(numEtu,nom,moyenne);
		if(*rac==NULL)
			*rac=nv;
		else if( strcmp(nv->nom, parc->nom)<0){
			nv->suiv=parc;
			*rac=nv;
		}
		else{
			while((strcmp(parc->nom,nv->nom)>0)&&(parc!=NULL)){
				prec=parc;
				parc=parc->suiv;
			}
			if(parc->suiv==NULL)
				parc->suiv=nv;
			else{
				nv->suiv=parc;
				prec->suiv=nv;
			}
		}
	}
}

void ajouterListeS2Fin(elements2 **rac, int numEtu, char *nom, float moyenne){
	elements2 *nv ,*parc=*rac;
	nv=creerElementS2(numEtu, nom, moyenne);
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
void fusion(elements1 *rac1,elements2 *rac2, elements2 **rac){
	elements1 *parc1=rac1;
	elements2 *parc2=rac2;
	while((parc1!=NULL)&&(parc2!=NULL)){
		if(strcmp(parc1->nom,parc2->nom)<0){
			ajouterListeS2Fin(rac,parc1->numEtu,parc1->nom,parc1->moyenne);
			parc1=parc1->suiv;
		}
		else{
			ajouterListeS2Fin(rac,parc2->numEtu,parc2->nom,parc2->moyenne);
			parc2=parc2->suiv;
		}
	}
	while(parc1!=NULL){
		ajouterListeS2Fin(rac,parc1->numEtu,parc1->nom,parc1->moyenne);
	}
	while(parc1!=NULL){
		ajouterListeS2Fin(rac,parc2->numEtu,parc2->nom,parc2->moyenne);
	}
}
 elements2 * promotion(elements2 *rac){
 	elements2 *parc=rac;
 	elements2 *nvRac=NULL;
 	while(parc!=NULL){
 		if(parc->moyenne >= 10){
 			ajouterListeS2Fin(&nvRac,parc->numEtu,parc->nom,parc->moyenne);
		 }
		 parc=parc->suiv;
	 }
	 return nvRac;
 		
 }
 void afficher1(elements1 *rac){
 	elements1 *parc=rac;
 	printf("\nLIste!:");
	 while(parc!=NULL){
 		printf("%d,%s,%f,%d\t", parc->numEtu,parc->nom,parc->moyenne, parc->etat);
 		parc=parc->suiv;
	 }
	 printf("\n");
 }
 void afficher2(elements2 *rac){
 	elements2 *parc=rac;
 	printf("\nLIste!:");
 	while(parc!=NULL){
 		printf("%d,%s,%f\t", parc->numEtu,parc->nom,parc->moyenne);
 		parc=parc->suiv;
	 }
	 printf("\n");
 }
int main(){
	elements1 *rac1=NULL;
	elements2 *rac2=NULL;
	elements2 *racine=NULL;
	elements2 *prac=NULL;
	construireCroissanteS1(&rac1);
	afficher1(rac1);
	construireCroissanteS2(&rac2);
	afficher2(rac2);
	fusion(rac1,rac2,&racine);
	afficher2(racine);
	prac=promotion(racine);
	afficher2(prac);
}
