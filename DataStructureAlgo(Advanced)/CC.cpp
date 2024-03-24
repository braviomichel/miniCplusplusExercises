#include<stdio.h>
#include<stdlib.h>


typedef struct element {
 	int val;
 	element *suiv;
};
element* creerElement(int val){
	element *nv;
	nv=(element*)malloc(sizeof(element));
	nv->suiv=NULL;
	nv->val=val;
	return nv;
}
void creerListe(element **rac){
	int nb, val;
	element *nv,*parc=*rac;
	printf("\nEntrez le nombre d elements: ");
	scanf("%d",&nb);
	for(int i = 0; i<nb;i++){
		printf("\nEntrez l element");
		scanf("%d",&val);
		nv=creerElement(val);
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

void creerListe2(element **rac, char *nomFichier){
	FILE *f=fopen(nomFichier, "r");
	if(f){
		int val;
		element *nv, *parc=nv;
		while(!feof(f)){
			fscanf(f,"%d\t",&val);
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
	}
	fclose(f);
}

void afficherListe(element *rac){
	element *parc=rac;
	if(rac==NULL)
		printf("\nListe Vide");
	else{
		while(parc!=NULL){
		printf("%d\t",parc->val );
		parc=parc->suiv;
	}
	printf("\n");
	}
	
}

void ajouterAvant(element **rac,int x, int y){
	element *parc=*rac, *nv,*prec=NULL;
	nv=creerElement(x);
	while((parc!=NULL) && (parc->val != y)){
		prec=parc;
		parc=parc->suiv;
	}
	if(prec==NULL){
		nv->suiv=parc;
		*rac=nv;
	}
	else{
		nv->suiv=parc;
		prec->suiv=nv;
	}
	
}

void supprimerApres(element **rac, int x){
	element *parc=*rac,*tmp,*prec; 
	while((parc->suiv!=NULL)&&(parc->val!=x)){
		prec=parc;
		parc=parc->suiv;
	}
	if(parc->suiv==NULL){
		if(parc->val==x){
			prec->suiv=NULL;
			free(parc);	
		}
		else return;
		
	}
	else if(prec==NULL){
		*rac=(*rac)->suiv;
		free(parc);
	}
	else{
		tmp=parc->suiv;
		parc->suiv=tmp->suiv;
		free(tmp);	
	}
	
}

void deplacerDebut(element **rac){
	element *parc1, *parc2, *tmp;
	for(int i=0;i<3;i++){
		parc1=*rac;
		parc2=*rac;
		while(parc2->suiv!=NULL)
		{
			tmp=parc2;
			parc2=parc2->suiv;
		}
		parc1->suiv=parc1;
		tmp->suiv=NULL;
		*rac=parc2;
		
	}
	
}
int main(){
	element *rac=NULL, *racL=NULL;
	creerListe(&rac);
	afficherListe(rac);
	//char nomFichier[]="liste.txt";
	//creerListe2(&racL, nomFichier);
	//afficherListe(racL);
//	ajouterAvant(&rac, 4,2);
//	afficherListe(rac);
	//supprimerApres(&rac, 4);
	//afficherListe(rac);
	deplacerDebut(&rac);
	afficherListe(rac);
	
}
