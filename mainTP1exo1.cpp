#include "point.h"
#include<iostream>
using namespace std;
int main()
{
    Point p1(4,5),p2(3,4),p3;
    p1.affiche();
    p2.deplace(4,5);
    p1.affiche();
}
