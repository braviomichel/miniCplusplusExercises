#include<iostream>
using namespace std;
class Rectangle 
{
	private:
		int largeur;
		int hauteur;
	public:
		Rectangle(int=0,int=0);
		int calcule_perimetre();
		int calcul_aire();
		void affiche();
		void modifier_hauteur(int);
		void modifier_largeur(int);
		Rectangle(int l, int h)
		{
			largeur=l;
			hauteur=h;
		}
		int calcule_perimetre()
		{
			return (largeur+hauteur)*2 ;
		}
		int calcule_aire(){
			return largeur*hauteur;
		}
		void affiche()
		{
			cout<<"Hauteur= "<<hauteur<<endl<<"Largeur= "<<largeur<< endl;
		}
		void modifier_largeur(int nl)
		{
			largeur=nl;
		}
		void mofifier_hauteur(int nh)
		{
			hauteur=nh;
		}
		
};

int main()
{
	int choix, l,h,nh,nl;
	cout<<"Entrez la hauteur"<<endl;
	cin>>h;
	cout<<"Entrez la largeur"<<endl;
	cin>>l;
	Rectangle r(l,h);
	do{
		do{
			cout << "Entrez un choix "<<endl;
			cout<< "1.Modifier Largeur"<<endl<<"2.Modifier Hauteur"<<endl<<"3.Calculer les proprietes"<<endl<<"4.Afficher le recantgle"<<endl<<"5.Quitter"<<endl;
			cin>> choix;
		}while ((choix<1)|| (choix>5));
		switch (choix) {
			case 1 :
				cout<< "Entrez la nouvelle hauteur"<<endl;
				cin>> nh;
				r.mofifier_hauteur(nh);
				break;
			case 2 :
				cout<< "Entrez la nouvelle largeur"<<endl;
				cin>> nl;
				r.mofifier_hauteur(nl);BOOL CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case : {
			break;
		}
		default:
			return false;
	}
	return true;
}

				break;
			case 3 :
				cout<<"Aire du rectangle "<<r.calcule_aire()<<endl;
				cout<<"Perimetre du rectangle "<<r.calcule_perimetre()<<endl;
				break;
			case 4 :
				r.affiche();
				break; 
				 }
	
	}while(choix!=5);
	
}




