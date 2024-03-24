#include <iostream>
#include<string>
using namespace std;
const int n=10;
class Bouquet;
class Fleur;
class Fleur
{
	private:
		string espece;
		string couleur;
		double prix_base;
		bool parfumee;
		bool promotion;
		
	public:
		Fleur(string="",string="",double=0,bool=true,bool=false);
		bool operator != (Fleur f1);
		
};

Fleur::Fleur(string espece,string couleur, double prix_base, bool parfumee, bool promotion)
{
	this->espece=espece;
	this->couleur=couleur;
	this->prix_base=prix_base;
	this->parfumee=parfumee;
	this->promotion=promotion;
}

/*void Fleur :: affiche()
{
	cout<<"Espece= "<<espece<<endl;
	cout<<"couleur= "<<couleur<<endl;
	cout<<"prixbase= "<<prix_base<<endl;
	cout<<"parfumee= "<<parfumee<<endl;
	cout<<"promotion= "<<promotion<<endl;
}*/

bool Fleur :: operator!=(Fleur f1)
{
	return ((f1.couleur!=couleur)&&(f1.espece!=espece)&&(f1.prix_base!=prix_base)&&(f1.parfumee!=parfumee)&&(f1.promotion!=promotion));
 } 
 
 
 class Bouquet{
 	private:
	 Fleur *t;
	 int nombre;
	public:
		Bouquet();
		Bouquet operator +=(Fleur);
		friend int coincide(Bouquet, Bouquet);
 	
 };
 Bouquet::Bouquet(){
 	string eb;
	string cb;
	double pb;
	bool parfb;
	bool promob;
 	cout<<"Entrez le nombre de fleurs dans le bouquet: "<<endl;
 	cin>>nombre;
	 t= new Fleur[n];
	 for(int i=0;i<nombre;i++)
	 {
	 	cout<<"Fleur"<< i<<endl;
	 	cout<<"Entrez l'esepce"<<endl;
	 	cin>>eb;
	 	cout<<"Entrez la couleur"<<endl;
	 	cin>>cb;
	 	cout<<"parfum oui ou non"<<endl;
	 	cin>>parfb;
	 	cout<<"promotion oui ou non"<<endl;
	 	cin>>promob;
	 	Fleur F(eb,cb,pb,parfb,promob);
	 	t[i]=F;
	 	
	 }
 	
 }
 
 
 Bouquet Bouquet :: operator +=(Fleur f1){
	t[nombre]=f1;
	nombre++;
}
 
 
 int coincide(Bouquet b1,Bouquet b2)
 {
 	int a=0;
 	for (int i=0;i<b1.nombre;i++)
 	{
 		if ((b1.t[i].operator!=(b2.t[i])) ){
 			a=1;
		 }
	break;	
	 }
	 return a;
 }
 int main(int argc, char** argv) {
	
	//tests classes 
	Fleur F1;
	// surchage de l'operateur !=

	Fleur f1;
	if(F1!=f1)
		cout<<"different";
	else
		cout<<"non different"<<endl;
		
	// test bouquet
	cout<<"Bouquet 1"<<endl;
	Bouquet b2;
	cout<<"Bouquet 2"<<endl;
	Bouquet b1;
	Fleur f4,f3;
	b1+=f3;
	b2+=f4;
	if(coincide(b1,b2))
		cout<<"Les bouquets coincident"<<endl;
		
	else
		cout<<"Les bouquets ne coincident pas"<<endl;
	
		
	return 0;
}
