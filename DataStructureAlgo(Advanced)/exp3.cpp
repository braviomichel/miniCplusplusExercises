#include<stdio.h>
#include<stdlib.h>

typedef struct person {
	char nom [30];
	int age;
};

void saisirPerson(person * p) {
	printf("Entrez le nom : ");
	scanf("%s", p->nom);
	printf("Entrez l'age : ");
	scanf("%d", &p->age);	
}

void afficherPerson(person p) {
	printf("\nPerson[%s, %d]", p.nom, p.age);
}

void saisirTabPerson(person * T, int n) {
	for(int i = 0; i < n; i++) {
		saisirPerson(T+i);
	}
}

void saisirTabAdressPerson(person ** T, int n) {
	for(int i = 0; i < n; i++) {
		saisirPerson(*(T+i));
	}
}

void afficherTabPerson(person * T, int n) {
	for(int i = 0; i < n; i++) {
		afficherPerson(*(T+i));
	}
}

void afficherTabAdressPerson(person ** T, int n) {
	for(int i = 0; i < n; i++) {
		afficherPerson(**(T+i));
	}
}

int main() {
/*	person p;
	person *q = (person *)malloc(sizeof(person));
	
	saisirPerson(&p);
	afficherPerson(p);
	saisirPerson(q);
	afficherPerson(*q);

	person fs1[3];	
	saisirTabPerson(fs1, 3);
	afficherTabPerson(fs1, 3);

	person * fd1;
	fd1 = (person *)malloc(3 * sizeof(person));	
	saisirTabPerson(fd1, 3);
	afficherTabPerson(fd1, 3);

	person * fs2[3];
	for(int i = 0; i < 3; i++) {
		fs2[i] = (person *)malloc(sizeof(person));
	}
	saisirTabAdressPerson(fs2, 3);	
	afficherTabAdressPerson(fs2, 3);
*/
	person ** fd2;
	fd2 = (person **)malloc(3 * sizeof(person *));
	for(int i = 0; i < 3; i++) {
		fd2[i] = (person *)malloc(sizeof(person));
	}
	saisirTabAdressPerson(fd2, 3);
	afficherTabAdressPerson(fd2, 3);
		
}



