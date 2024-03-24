#include "Bouquet.h"
#include "Fleur.h"
#include<iostream>
using namespace std;

const int n=10;
 Bouquet :: Bouquet()
{
	
	nb=0;
	f=new Fleur [n];	
}

bool Bouquet :: parfum()
{
	bool res=false;
	int i;
	for(i=0;i<nb;i++)
	{
		if(f[i].parfum()==true){
			res=true;
			break;
		}		
	}
	return res;
}

double Bouquet :: prix()
{
	double  priX=0;
	for(int i=0;i<nb;i++)
	{
		priX+=f[i].prix();
	}
	if(parfum())
		priX/=2;
	return priX;
}

Bouquet Bouquet :: operator +=(Fleur f1){
	f[nb]=f1;
	nb++;
}

