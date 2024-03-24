#include <iostream>
#include"POINT.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Point p1(4,5),p2(3,4),p3;
    p1.affiche();
    p2.deplace(4,5);
    p2.affiche();
	return 0;
}
