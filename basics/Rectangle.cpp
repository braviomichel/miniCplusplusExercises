#include "Rectangle.h"
#include<iostream>
using namespace std;

	Rectangle::Rectangle(int l, int h)
		{
			largeur=l;
			hauteur=h;
		}
		
		
	int Rectangle:: calcule_perimetre()
		{
			return (largeur+hauteur)*2 ;
		}
		
		
	int Rectangle:: calcule_aire(){
			return largeur*hauteur;
		}
		
		
	void  Rectangle:: affiche()
		{
			cout<<"Hauteur= "<<hauteur<<endl<<"Largeur= "<<largeur<< endl;
		}
		
		
	void Rectangle::  modifier_largeur(int nl)
		{
			largeur=nl;
		}
		
		
	void Rectangle:: modifier_hauteur(int nh)
		{
			hauteur=nh;
		}
		
