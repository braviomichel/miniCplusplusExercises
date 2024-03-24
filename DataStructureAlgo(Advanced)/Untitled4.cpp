	
	#include<stdio.h>
	#include<string.h>
	int main(){
		char nom[20];
		char *prenom;
		prenom="marc";
		for(int j=0;j<strlen(nom);j++){
		nom[j]=prenom[j];
	}
		
		printf("%s",nom);
	}
