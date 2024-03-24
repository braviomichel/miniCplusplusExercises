#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud{
	int val;
	Noeud * suiv;
}noeud;

noeud * creerNoeud(){
	noeud * nv;
	nv=(noeud *) malloc(sizeof(noeud));
	nv->suiv=NULL;
	printf("\nEntrez la valeur de l element: ");
	scanf("%d",&nv->val);
	return nv;
}


noeud * creerNoeud2(int n){
	noeud * nv;
	nv=(noeud *) malloc(sizeof(noeud));
	nv->suiv=NULL;
	nv->val=n;
	return nv;
}

noeud* creerListe(){
	noeud * rac,*parc,*nv;
	int N;
	printf("Quel est le nombre de noeuds? :");
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

void creerListe2(noeud **rac){
	*rac=creerListe();
}

void afficherNoeud(noeud *N){
	printf("%d\t",N->val);	
}

void afficherListe(noeud *rac){
	noeud *parc=rac;
	if(parc==NULL)
		printf("\nListe vide");
	while(parc!=NULL){
		afficherNoeud(parc);
		parc=parc->suiv;
	}
	printf("\n");
}

void afficherListeRecursive(noeud *rac){
	if(rac!=NULL){
		afficherNoeud(rac);
		afficherListeRecursive(rac->suiv);
	}
}

int nbNoeuds(noeud *rac){
	noeud * parc=rac;
	int n=0;
	while(parc!=NULL){
		n++;
		parc=parc->suiv;
	}
return n;	
}

int testerVide( noeud *rac){
	if(rac==NULL)
		return 1;
	else 
		return 0;
}

void supprimerListe(noeud **rac){
	noeud *tmp, *parc=*rac;
	while(parc->suiv!=NULL){
		tmp=parc;
		parc=parc->suiv;
		free(tmp);
	}
	*rac=NULL;
}

void afficherInverse(noeud *rac){
	noeud *parc=rac;
	if(parc!=NULL){
		afficherInverse(parc->suiv);
		afficherNoeud(parc);
	}
}

void insererDebut(noeud **rac){
	noeud *nv;
	nv=creerNoeud();
	if(*rac==NULL){
		*rac=nv;
	}
	else{
		nv->suiv=*rac;
		*rac=nv;
	}
}


void insererDebut2(noeud **rac, int v){
	noeud *nv;
	nv=creerNoeud2(v);
	if(*rac==NULL){
		*rac=nv;
	}
	else{
		nv->suiv=*rac;
		*rac=nv;
	}
}

void supprimerDebut(noeud **rac){
	noeud *tmp;
	if(*rac==NULL)
		return;
	else{
		tmp=*rac;
		*rac=(*rac)->suiv;
		free(tmp);
	}
}

void insererFin(noeud** rac){
	noeud *nv, *parc=*rac;
	nv=creerNoeud();
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


void insererFin2(noeud** rac, int v){
	noeud *nv, *parc=*rac;
	nv=creerNoeud2(v);
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

void supprimerFin(noeud** rac){
	 noeud *tmp, *parc=*rac;
	 if((parc->suiv==NULL)||(parc==NULL)){
	 	supprimerDebut(rac);
	 }
	 else{
	 	while(parc->suiv->suiv!=NULL){
	 		parc=parc->suiv;
		 }
		 tmp=parc->suiv;
		 parc->suiv=NULL;
		 free(tmp);
	 }
	 
}                 
void effectuerRotation(noeud** rac, int ordre){
	noeud *parc;
	if(nbNoeuds(*rac)>ordre)
		ordre%=nbNoeuds(*rac);
	for(int i=0;i<ordre;i++){
		parc=*rac;
		insererFin2(rac,parc->val);
		*rac=(*rac)->suiv;
		supprimerDebut(&parc);
	}
}
void effectuerRotation2(noeud **rac, int ordre){
	noeud *parc1,*parc2;
	if(nbNoeuds(*rac)>ordre)
		ordre%=nbNoeuds(*rac);
	
	for(int i=0;i<ordre;i++){
		
		parc1=*rac;
		parc2=*rac;
		while(parc2->suiv!=NULL){
			parc2=parc2->suiv;
		}
			
		*rac=parc1->suiv;
		parc2->suiv=parc1;
		parc1->suiv=NULL;
	//	parc2->suiv=parc1;
	//	parc1->suiv=NULL;
	//	*rac=(*rac)->suiv;
		
	}
}
      
int appartenir(noeud *rac,int n){
	noeud *parc=rac;
	while(parc!=NULL){
		if(parc->val==n)
			return 1;
		parc=parc->suiv;
	}
	return 0;
	
}

void trierListe(noeud **rac){
	if((*rac==NULL)||((*rac)->suiv==NULL)){
		return;
	}
	
	int ordre;
	do{
		noeud *precedent = NULL;
		noeud * parc=*rac;
		noeud * suivant =parc->suiv;
		ordre=0;
		while(suivant!=NULL){
			if(suivant->val < parc->val){
				ordre = 1;
				if(precedent==NULL){
					parc->suiv = suivant->suiv;
					suivant->suiv = parc;
					*rac = suivant;
					}
				else if(parc->suiv->suiv==NULL){
					precedent->suiv=suivant;
					suivant->suiv=parc;
					parc->suiv=NULL;
				}
				else{
					precedent->suiv=suivant;
					parc->suiv=suivant->suiv;
					suivant->suiv=parc;
				
				}
				
				precedent = suivant;
				suivant = parc->suiv;
		
			}
			else{
				precedent = parc;
				parc = parc->suiv;
				suivant = parc->suiv;
			}
		}
	}while(ordre);
	

}

void insererTrie(noeud **rac, int n){
	noeud *nv=creerNoeud2(n);
	noeud *parc=*rac;
	noeud *precedent =NULL;
	if(parc->val > nv->val){
		nv->suiv=parc;
		*rac=nv;
	}
	else{
		while((parc!=NULL) && (parc->val<nv->val)){
			precedent=parc;
			parc= parc->suiv;
		}
		precedent->suiv=nv;
		nv->suiv=parc;
	}
}
void supprimerTrie(noeud**rac,int n){
	if(appartenir(*rac, n)==0)
		return;
	noeud * precedent=NULL;
	noeud *parc=*rac;
	while(parc->val!=n){
		precedent=parc;
		parc=parc->suiv;
	}
	if(precedent==NULL)
		*rac=parc->suiv;
	else
		precedent->suiv=parc->suiv;
	
	free(parc);
	
	
}
int enregistrerListeFichier(noeud *rac,char* nom){
	FILE *pfile= fopen(nom,"w");
	if ((pfile==NULL) || (rac==NULL)){
		return(0);
	}
	else{
		noeud *parc=rac;
		while(parc!=NULL){
			fprintf(pfile,"%d\t",parc->val);
			parc=parc->suiv;
		}
		fclose(pfile);
		return 1;
	}
}
/*
element * load(char* filepath){
element * rzc =NULL;
int val;
FILE *f = fopen(filepath, "r");
while (!feof(f)){
}
*/
void initialiserListeFichier(noeud **rac, char * nom){
	FILE *pfile=fopen(nom,"r");
	if(pfile==NULL)
		return;       
	else{
		int v;
		while(!feof(pfile) ){
			fscanf(pfile,"%d\t",&v);
			insererFin2(rac,v);
		}  
	}
}              
int main(){
	noeud *rac=NULL;
	char nom[]="liste.txt";
	//noeud *N1=creerNoeud2(3);
	//afficherNoeud(N1);
	//rac=creerListe();
	creerListe2(&rac);
	afficherListe(rac);
	/*afficherListeRecursive(rac);
	printf("\n nombre de noeuds : %d",nbNoeuds(rac));
	printf("\ntest vide : %d\n",testerVide(rac));
	afficherInverse(rac);
	supprimerListe(&rac);
	afficherListe(rac);*/
	//insererDebut2(&rac,9);
	//afficherListe(rac);
	//supprimerDebut(&rac);
	//afficherListe(rac);
	//insererFin2(&rac,7);
	//afficherListe(rac);
	//supprimerFin(&rac);
	//afficherListe(rac);
	//effectuerRotation(&rac,2);
	afficherListe(rac);
	//printf("\n appartient : %d",appartenir(rac,5));
	//printf("\n enregistrement  : %d",enregistrerListeFichier(rac, nom));
	//initialiserListeFichier(&rac,nom);
	
	effectuerRotation2(&rac,2);
	//trierListe(&rac);
	afficherListe(rac);
	
	//insererTrie(&rac,7);
	//supprimerTrie(&rac,2);
	//afficherListe(rac);
	system("PAUSE");
}
