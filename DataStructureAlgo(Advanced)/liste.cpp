#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int val;
	element * suiv;
};

element * creerElement(int val) {
	element * nv = (element *)malloc(sizeof(element));
	nv->val = val;
	nv->suiv = NULL;
	return nv;
}

void insererDebut(element ** rac, int val) {
	if(*rac == NULL)
		*rac = creerElement(val);
	else {
		element * nv = creerElement(val);
		nv->suiv = *rac;
		*rac = nv;
	}
}

void afficherListe(element * rac) {
	printf("\n les elements de la liste sont : ");
	element * parc = rac;
	while(parc != NULL) {
		printf("%d\t", parc->val);
		parc = parc->suiv;
	}
}

void afficherListeRec(element * rac) {
	if(rac != NULL) {
		printf("%d\t", rac->val);
		afficherListeRec(rac->suiv);
	}
}

void afficherListeInverse(element * rac) {
	if(rac != NULL) {
		afficherListeInverse(rac->suiv);
		printf("%d\t", rac->val);
	}
}

element * creerListe() {
	int n, x; 
	printf("Entrez le nb d'elments : ");
	scanf("%d", &n);
	element * rac;
	element * nv;
	element * parc;
	for(int i = 0; i < n; i++) {
		printf("Entrez un nb : ");
		scanf("%d", &x);
		if(i == 0) {
			rac = creerElement(x);
			parc = rac;
		} else {
			element * nv = creerElement(x);
			parc->suiv = nv;
			parc = parc->suiv;
		}
	}
	return rac;
}



int main() {
	element * rac = NULL;
	
//	insererDebut(&rac, 1);
//	insererDebut(&rac, 2);
//	insererDebut(&rac, 3);
//	afficherListe(rac);
//	afficherListeRec(rac);
//	afficherListeInverse(rac);

	rac = creerListe();
	afficherListe(rac);

}
