#include "matrice.h"
#include "vect.h"
using namespace std;

void matrice :: saisie()
{
	int i, j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<"entrez l element "<<i<<"-"<<j<<endl;
			cin>>m[i][j];
		}
	}
}

void matrice::affiche(){
	int i, j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}
	
}

vect matrice::prod( vect V)
{
	int i,j,k;
	vect res;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			res.v[i]+=this->m[i][j]*V.v[j];
		}
	}

	return res;
}


