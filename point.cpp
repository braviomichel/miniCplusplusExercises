#include "point.h"
#include <iostream>
 
 using namespace std;
 
 Point::Point (float a, float b)
 {
     x=a;
     y=b;
 }

 void Point :: affiche()
 {
    cout << "Les coordonnes sont " << x<<" et " << y<<endl;
 }
  
 void Point :: deplace(float dx,float dy){
     x+=dx;
     y+=dy;
 }


