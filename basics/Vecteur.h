#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur
{
	private :
		float v[2];
	public:
		Vecteur(float =0,float =0,float=0);
		~Vecteur();
		void afficher();
		static void coincide( Vecteur &v1, Vecteur &v2);
		static void somme(Vecteur &v1, Vecteur &v2); 

};

#endif
