#ifndef EMPLOYE_H
#define EMPLOYE_H

class employe
{
	private:
		std::string nom;
		std::string prenom;
		unsigned int cne;
	public:
		employe(std::string="",std::string="",unsigned int=0);
		void affiche();
		void modifier();
		
	
};

#endif
