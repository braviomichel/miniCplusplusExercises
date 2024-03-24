#include<iostream>
using namespace std;

class Point {
    private: 
        float x;
        float y;
    public:
        Point(float a, float b){
         x=a;
     	y=b;
		}
        void deplace (int n )
        {
        	 x+=n;
    		 y+=n;
		}
        void affiche(){
        	 cout << "x= "<< x <<endl << "y= "<< y;
		}

};


int main()
{
    Point p(4,5);
    p.affiche();
    p.deplace(4);
    
    
}
