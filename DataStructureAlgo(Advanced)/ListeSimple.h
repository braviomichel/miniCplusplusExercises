#ifndef LISTESIMPLE_H
#define LISTESIMPLE_H



class ListeSimple
{
	private:
		noeud * rac;
		int nbElement;
	public:
		ListeSimple();
	//	ListeSimple(&ListeSimple);
		void creerListe();
		void afficherListe();
		/*int nbNoeuds();
		int testerVide();
		void supprimerListe();
		void afficherInverse();
		void insererDebut(int val);
		void supprimerDebut();
		void insererFin( int val);
		void supprimerFin();
		void effectuerRotation(int ordre);
		int appartenir(int n);
		void trierListe();
		void insererTrie(int val);
		void supprimerTrie(int val);
		void enregistrerListeFichier( char * nom );
		void initialiserListeFichier(char *nom);
		*/
};

#endif
