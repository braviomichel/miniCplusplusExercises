#include<stdio.h>
#include<stdlib.h>

typedef struct maillon
{
float val ;
struct maillon *suivant ;
} ;

maillon* creerMaillon( float val){
	maillon *nv = (maillon*)malloc(sizeof(maillon));
	nv->suivant=NULL;
	nv->val=val;
	return nv;
}
void ajoutFin(maillon ** rac, float val){
	maillon *parc=*rac, *nv=creerMaillon(val);
	if(*rac==NULL)
		*rac=nv;
	else{
		while(parc->suivant!=NULL){
			parc=parc->suivant;
		}
		parc->suivant=nv;
	}
}

void creerListe(maillon **rac,int n){
	float val;
	for(int i=0; i<n;i++){
		printf("\n valeur du mailllon!!: ");
		scanf("%f",&val);
		ajoutFin(rac,val);
	}
}
void afficher(maillon *rac){
	maillon *parc=rac;
	if(rac==NULL)
		printf("\nListe VIde : ");
	else{
		while(parc!=NULL){
			printf("%f\t", parc->val);
			parc=parc->suivant;
		}
		printf("\n");
	}
}
float moyenne(maillon *rac){
	int n=0;
	float S=0;
	maillon *parc=rac;
	while(parc!=NULL){
		S+=parc->val;
		n++;
		parc=parc->suivant;
	}
	return float(S/n);
}
float covariance(maillon *rac1,maillon *rac2){
	float m1,m2,a=0,b=0;
	int n=0;
	maillon *parc1=rac1, *parc2=rac2;
	m1=moyenne(rac1);
	m2=moyenne(rac2);
	while(parc1!=NULL){
		a+=(parc1->val - m1);
		n++;
		parc1=parc1->suivant;
	}	
	while(parc2!=NULL){
		b+=(parc2->val - m2);
		parc2=parc2->suivant;
	}
	return float((a+b)*n);
}

int main(){
	maillon *rac=NULL;
	creerListe(&rac,3);
	afficher(rac);
	printf("\nmoyenne: %f",moyenne(rac));
	maillon *rac2=NULL;
	creerListe(&rac2,3);
	afficher(rac2);
	printf("\nmoyenne: %f",moyenne(rac2));
	printf("\n covariance: %f",covariance(rac,rac2));
}
