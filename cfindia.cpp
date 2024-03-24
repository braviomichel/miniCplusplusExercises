#include<iostream>
#include<string>
using namespace std ;

class Employe
{
	private:
		int code;// code de l'employé
		char *nom ; // nom de l'employé 
		float salaire; // salaire de base
	public :
 		Employe() ;//constructeur sans arguments
 		Employe(int, char *, float);//constructeur avec arguments
 		Employe(Employe &) ; // constructeur par recopie 
 		void afficher() ; // fonction d’affichage 
 		float calculer_salaire();// retourne le salaire de base 
 		~ Employe() ; // destructeur
 		Employe& operator>(Employe &e);
 		Employe operator=(Employe); 
};
class employe_admin:public Employe
{
	private:
		int indice;
	public:
		employe_admin(int c, char *n,float s, int i);
		employe_admin(employe_admin&);
		float calculer_salaire();
};
Employe::Employe()
{
	code=0;
	nom=new char;
	//*nom="jj";
	salaire=0;
}
Employe::Employe(int c, char *n, float s)
{
	code=c;
	nom = new char;
	nom=n;
	salaire=s;
}
Employe::Employe(Employe &e)
{
	code=e.code;
	nom=new char;
	*nom=*(e.nom);
	salaire=e.salaire;
}
void Employe:: afficher()
{
	cout<<"code: "<<code<<endl;
	cout<<"nom: "<<*nom<<endl;
	cout<<"salaire: "<<salaire<<endl;
}
float Employe::calculer_salaire()
{
	return salaire;
}
Employe::~Employe()
{
	if(nom!=NULL)
		delete nom;
}
Employe& Employe:: operator>(Employe &e)
{
	if(salaire>e.salaire)
		return (*this);
	else
		return(e);
  }  
Employe Employe::operator=(Employe e1)
{
	salaire=e1.salaire;
	*nom=*(e1.nom);
	code=e1.code;
	return *this;
}
employe_admin::employe_admin(int c, char *n,float s, int i):Employe(c,n,s)
{
	indice=i;
}
employe_admin::employe_admin(employe_admin &e):Employe(&e)
{
	indice=e.i;
}
float employe_admin::calculer_salaire()
{
	float prime;
	if(indice==1)
		prime=(salaire*5)/100;
	else if(indice==2)
		prime=(salaire*10)/100;
	else
		prime=(salaire*15)/100;
	return (salaire+prime);
}

