#include<stdio.h>

void permuterValeur(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
	printf("\n fct x = %d, y = %d", x, y);
}

void permuterAdresse(int * x, int * y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
//	printf("\n fct x = %d, y = %d", x, y);
}

int main() {
	int x = 4, y = 6;
	
	printf("\n avant x = %d, y = %d", x, y);
//	permuterValeur(x, y);
	permuterAdresse(&x, &y);
	printf("\n apres x = %d, y = %d", x, y);
		
}
