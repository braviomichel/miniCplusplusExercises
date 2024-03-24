#include "vect.h"
#include<iostream>
using namespace std;

vect::vect(float x,float y,float z )
{
	v[0]=x;v[1]=y;v[2]=z;
}

void vect::affiche()
{
	int i;
	for(i=0;i<3;i++)
		cout<<v[i]<<"   ";
	
	cout<<endl;
}


