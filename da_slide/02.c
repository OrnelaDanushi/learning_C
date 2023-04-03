//stampa due colonne, nella prima i numeri fino a 25 e nella seconda la radice di essi, 
// con approssimazione a 4 numeri dopo la virgola, se non specificato sarebbe stato di 6 numeri dopo la virgola. 

#include <stdio.h>
#include <math.h>	//serve per usare la sqrt()

int main(){
	int i=0;
	printf("\t Number \t\t Square Root of Number\n\n");
	for(i=0; i<=25; ++i)
		printf("\t %d \t\t\t %.4lf \n",i, sqrt((double) i)); //la SquareRootFunction vuole un numero in double con segnaposto %lf
	return 0;
}
