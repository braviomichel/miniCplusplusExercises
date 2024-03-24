#include<stdio.h>
#include<stdlib.h>

typedef  struct element{
	int val;
	element* suiv;
	element * prec;
	
};
 element * creerElement( int val){
 	element * nv=(element*) malloc(sizeof(element));
 	nv->val=val;
 	nv->suiv=nv;
 	nv->prec= nv;
 	return nv;
 }
 
 element * insererDebut(element *rac, int val){
 	element *nv= creerElement(val);
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
 
 element * creerListe(){
 	int n, val;
 	element *rac=NULL;
 	printf("\nNombre d elements :");
 	scanf("%d",&n);
 	for(int i=0;i<n ;i++){
 		printf("\nEntrez la valeur: ");
 		scanf("%d", &val);
 		rac=insererDebut(rac, val);
	 }
	 return rac;
 }
 
 void parcoursEndroit(element *rac){
 	if(rac==NULL)
 		printf("\n Liste vide");
	else{
		printf("\n Parcours Endroit :");
		element *parc=rac;
		do {
			printf("%d\t", parc->val);
			parc=parc->suiv;
		}while(parc!=rac);
	}
 	
 }
 
 void parcoursEnvers(element *rac){
 	if(rac==NULL)
 		printf("\n Liste vide");
	else{
		printf("\n Parcours Envers :");
		element *parc=rac->prec;
		do {
			printf("%d\t", parc->val);
			parc=parc->prec;
		}while(parc!=rac->prec);
	}
 	
 }
 
 int main(){
 	
 	element * rac=NULL;
 	rac=creerListe();
 	parcoursEndroit(rac);
 	parcoursEnvers(rac);
 	
 	
 	system("PAUSE");
 }
