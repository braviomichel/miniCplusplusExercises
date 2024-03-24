#include<stdio.h>
#include<stdlib.h>

typedef struct noeud {
	int val;
	noeud* fg;
	noeud * fd;
};
noeud * creerNoeud(int val){
	noeud * nv = (noeud*)malloc(sizeof(noeud));
	nv->val=val;
	nv->fg=NULL;
	nv->fd=NULL;
	return nv;
}
void insererNoeud(noeud ** rac , noeud * n){
	if (*rac==NULL)
		*rac=n;
	else if((*rac)->val > n->val)
		insererNoeud(&((*rac)->fg), n);
	else
		insererNoeud(&((*rac)->fd), n);
}

void creerArbre(noeud **rac){
	int nb, val;
	noeud * n;
	printf ("Nombre d elements!: ");
	scanf("%d",&nb);
	for (int i=0;i<nb;i++){
		printf ("entrez un nombre:  ");
		scanf("%d",&val);
		n=creerNoeud(val);
		insererNoeud(rac, n);
	}
}

void afficherCroissant(noeud *rac){
	if(rac!=NULL){
		afficherCroissant(rac->fg);
		printf("%d\t",rac->val);
		afficherCroissant(rac->fd);
	}
}
void afficherCroissantNouveau(noeud *rac){
	if(rac==NULL)
		printf("\n liste vide");
	else
		afficherCroissant(rac);
}

void afficherDecroissant(noeud *rac){
	if(rac!=NULL){
		afficherDecroissant(rac->fd);
		printf("%d\t",rac->val);
		afficherDecroissant(rac->fg);
	}
}

int nbNoeud (noeud *rac){
	if(rac==NULL)
		return 0;
	else
		return 1+ nbNoeud(rac->fg)+nbNoeud(rac->fd);
}
int nbFeuilles(noeud *rac){
	if(rac==NULL)
		return 0;
	else if (rac->fg==NULL && rac->fd==NULL)
		return 1;
	else
		return nbFeuilles(rac->fd) + nbFeuilles(rac->fg);
}


void afficherFeuilles(noeud *rac){
	if(rac==NULL)
		return ;
	else if (rac->fg==NULL && rac->fd==NULL)
		printf("%d\t", rac->val);
	else{
		afficherFeuilles(rac->fd);
		afficherFeuilles(rac->fg);
	}
}

int max(int a, int b){
	return a > b ? a : b;
}

int profondeur( noeud * rac){
	if(rac==NULL)
		return 0 ;
	else
		return 1+ max(profondeur(rac->fg), profondeur(rac->fd));
}

void afficherCroissantF(noeud *rac,FILE *f){
	if(rac!=NULL){
		afficherCroissantF(rac->fg,f);
		fprintf(f,"%d\t",rac->val);
		afficherCroissantF(rac->fd,f);
	}
}

void enregistrerFichier(noeud * rac, char * nomFichier){
	FILE *pfile;
	pfile = fopen(nomFichier, "w");
	if(pfile){
		afficherCroissantF(rac,pfile);
	}
	fclose (pfile);
}
void enregistrerF(noeud * rac, FILE *f){
	if(rac!=NULL){
		enregistrerF(rac->fg, f);
		fprintf(f,"%d\t", rac->val);
		enregistrerF(rac->fd, f);
	}
}

void initialiserFichier(noeud ** rac, char *nomFichier){
	FILE *pfile;
	pfile=fopen(nomFichier, "r");
	if(pfile){
		int val;
		noeud * n;
		while(!feof(pfile)){
			fscanf(pfile,"%d",&val);
			n=creerNoeud(val);
			insererNoeud(rac, n);
		}
	}
	fclose(pfile);
}
noeud * recherche(noeud* rac ,int val){
	noeud *parc=rac, *prec=NULL;
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
int appartenir(noeud *rac, int n){
	if(rac==NULL)
		return 0;
	else if(rac->val==n)
		return 1;
	else if(rac->val<n){
		return appartenir(rac->fd, n);
	}
	else{
		return appartenir(rac->fg, n);
	}
	
}
void supprimerNoeud (noeud **rac, int val){
	if(appartenir(*rac,val)==0)
		return;
	else{
		noeud *prec = recherche(*rac, val);
		noeud *parc;
		if(prec->fg==NULL)
			parc=prec->fd;
		else
			parc=prec->fg;
		
		if((parc->fg==NULL)&&(parc->fd==NULL))
			parc=NULL;
		else if(parc->fg==NULL){
			prec=parc->fd;
			free(parc);
		}
		else if(parc->fd==NULL){
			prec=parc->fg;
			free(parc);
		}
		else{
			while(parc->fd!=NULL){
				parc=parc->fd;
			}
			parc=prec->fg;
			prec=parc;
		}
	}
}

void supprimerArbre(noeud ** rac){
	if(*rac!=NULL){
		noeud *tmp = *rac;
		supprimerArbre(&((*rac)->fg));
		supprimerArbre(&((*rac)->fd));
		free(tmp);
	}
	*rac=NULL;
}

int main (){
	char nomFichier[]="arbre.txt";
	/*
	noeud * rac=NULL;
	creerArbre(&rac);
	printf("\n sens croissant!\t");
	afficherCroissant(rac);
	printf("\n sens decroissant!\t");
	afficherDecroissant(rac);
	printf("\n nombre de noeuds : %d", nbNoeud(rac));
	printf("\n nombre de feuilles : %d", nbFeuilles(rac));
	printf("\n profondeur : %d", profondeur(rac));
	printf("\n les feuilles : ");
	afficherFeuilles(rac);

	*/
	//enregistrerFichier(rac,nomFichier);
	noeud *racine=NULL;
	//FILE *f=fopen("test.txt", "w");
	creerArbre(&racine);
	//initialiserFichier(&racine,nomFichier);
	afficherCroissant(racine);
	//enregistrerF(racine,f);
	//supprimerArbre(&racine);
	//afficherCroissantNouveau(racine);
	printf("\n appartenir %d\n", appartenir(racine,4));
	//supprimerNoeud(&racine,4);
	//afficherCroissant(racine);
}
