#include<iostream>
#include<string>
   class Cercle
   {
      protected:
       char*nom ;
       float x,y ; 	 //centre
       float r;    //rayon 
       Cercle (float x, float y, float r, char*nom)
	   {
	   	this->x=x;
	   	this->y=y;
	   	this->r=r;
	   	this->nom=nom;
		} ;      
       Cercle (Cercle &) ;                                        
       float surface();  			
       void Tracer(); 			
       ~ Cercle(); 			
   } ;

