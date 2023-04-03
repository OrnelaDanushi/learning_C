//il programma stampa due colonne in cui nella prima ci sono i numeri fino a 25 e nella seconda il loro quadrato
#include<stdio.h>
int main(){
	int i=0;
	printf("\t Number \t\t Square of Number\n\n");
	for(i=0; i<=25; ++i)
        		printf("\t %d \t\t\t %d \n",i,i*i);
	return 0;
}
//oppure
/*Questo programma utilizza la funzione square per calcolare il quadrato dei numeri fino a 10.
#include<stdio.h>
int square(int);
int main(){
	int x;
	for(x=1; x<=10; x++)
		printf("Il numero %d e' quadrato di %d\n",square(x),x);
	return 0;
}
int square(int y){
	return y*y;
}
*/
