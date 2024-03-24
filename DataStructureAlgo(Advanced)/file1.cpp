#include<stdio.h>
#include<stdlib.h>


typedef struct patient {
	char nom[20];
	char prenom[20];
	int age;
};

typedef struct file{
	patient *T;
	int deb, fin, taille;
};

void saisirPatient(patient *p){
	printf("\nEntrez le nom: ");
	scanf("%s", p->nom);
	printf("\nEntrez le prenom: ");
	scanf("%s", p->prenom);
	printf("\nEntrez l age: ");
	scanf("%d", &p->age);
}
void afficherPatient(patient p){
	printf("\nPatient  [%s-%s-%d]",p.nom,p.prenom,p.age);
}

void init(file *f,int taille){
	if(f==NULL)
		return;
	f->T= (patient *)malloc(sizeof (patient) *taille);
	f->deb=0;
	f->fin=0;
	f->taille=taille;
}

int testerVide(file f){
	if(f.deb == f.fin)
		return 1;
	else 
		return 0;
}

int testerPleine(file f){
	if( f.deb == (f.fin+1) % f.taille )
		return 1;
	else return 0;
}

void etendre(file *f, int nvTaille){
	if(f==NULL)
		return;
	patient *nvT=(patient *)malloc(sizeof(patient)* (f->taille+nvTaille));
	int j=0;
	for(int i =f->deb ;i%f->taille != f->fin ;++i % f->taille){
		nvT[j++]=f->T[i];
	}
	f->deb = 0;
	f->fin=j;
	f->taille = f->taille + nvTaille;
	f->T=nvT;
}

void inserer(file *f, patient p){
	if(f==NULL)
		return;
	if(testerPleine(*f))
		etendre(f,10);
	f->T[f->fin]=p;
	f->fin = f->fin +1;
	f->fin = f->fin % f->taille;
}

void afficherFile(file f){
	if(testerVide(f))
		return;
	else{
		for(int i =f.deb ;i%f.taille != f.fin ;++i % f.taille){
		afficherPatient(f.T[i]);
		}
		
	}
}

void retirer(file *f ){
	if(f==NULL)
		return;
	if(testerVide(*f))
		return;
	f->deb = f->deb + 1;
	f->deb = f->deb % f->taille;
}
int nbPatients(file f){
	int cp=0;
	for(int i =f.deb ;i%f.taille != f.fin ;++i % f.taille){
		cp++;
		} 
	return cp;
}
void enregistrer(file f, char* nomf){
	FILE *pfile=fopen(nomf, "w");
	if(pfile){
		for(int i=f.deb; i%f.taille!=f.fin; ++i%f.fin){
			fprintf(pfile,"%s\t %s\t %d\t", f.T->nom,f.T->prenom,f.T->age);
		}
	}
	fclose(pfile);
}

int main(){
	file f;
	init(&f,3);
	afficherFile(f);
	patient p;
	saisirPatient(&p);
	inserer(&f,p);
	afficherFile(f);
	inserer(&f,p);
	afficherFile(f);
	inserer(&f,p);
	/*afficherFile(f);
	retirer(&f);
	*/
	char nom[]="testpile.txt";
	enregistrer(f, nom);
	afficherFile(f);
}
