#include<stdio.h>
#include<stdlib.h>

typedef struct element{
	int val;
	element * suiv;
};
 element * creerElement( int val){
 	element *nv =(element*)malloc(sizeof(element));
 	nv->val=val;
 	nv->suiv=NULL;
 	return nv;
 }
 void creerListe(element **rac){
 	element *parc;
 	int val;
 	do{
 		element *nv;
 		printf("\n entrez la valeur : ");
 		scanf("%d",&val);
 		if(val>0){
 			nv=creerElement(val);
 			if(*rac==NULL){
 				*rac=nv;
 				parc=nv;
		 		}
			else{
				parc->suiv=nv;
				parc=parc->suiv;
			}	
		 }
		
 		
 		
	} while(val>0);
 }
 
 void afficherListe(element *rac){
 	element *parc=rac;
 	if(rac==NULL)
 		printf("\n Liste vide");
 	while(parc!=NULL){
 		printf("%d\t",parc->val);
 		parc=parc->suiv;
	 }
	 printf("\n");
 }
 void creerListeCroissante(element **rac){
 	element *parc,*prec;
 	int val;
	 do{
 		element *nv;
 		printf("\n entrez la valeur : ");
 		scanf("%d",&val);
 		if(val>0){
 			parc=*rac;
 			nv=creerElement(val);
 			if(*rac==NULL){
 				*rac=nv;
		 		}
			else if(nv->val < parc->val){
				nv->suiv=parc;
				*rac=nv;
			}
			else{
				while((nv->val > parc->val) && (parc->suiv!=NULL) ){
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
	} while(val>0);
 }
 
 void AjoutFin(element **rac, int val){
 	element *nv, *parc=*rac;
 	nv=creerElement(val);
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
 element* concatenation(element *rac1,element *rac2 ){
 	element *parc1=rac1, *parc2=rac2,*rac=NULL;

 		while(parc1!=NULL){
 			AjoutFin(&rac,parc1->val);
 			parc1=parc1->suiv;
		 }
		 while(parc2!=NULL){
 			AjoutFin(&rac,parc2->val);
 			parc2=parc2->suiv;
		 }
	 	return rac;
 }
 int rechercheElement(element *rac, int n){
 	element *parc=rac;
 	while(parc!=NULL){
 		if(parc->val==n)
 			return 1;
 		parc=parc->suiv;
	}
	return 0;
 }
 int main()
 {
 	element *rac=NULL ,*rac2=NULL,*racine;
 	creerListeCroissante(&rac);
 	afficherListe(rac);
 	/*creerListe(&rac2);
 	afficherListe(rac2);
 	racine =concatenation(rac,rac2);
 	afficherListe(racine);*/
 	//printf("\n recherher !: %d ",rechercheElement(rac, 5));
 	//AjoutFin(&rac,4);
 	//afficherListe(rac);
 }
