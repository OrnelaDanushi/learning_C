/*Questo programma stampa su schermo la media dell'array eta costituito da tali valori.*/
#include<stdio.h>
int main(){
	int eta[]={23, 24, 17, 27, 25, 24, 24}, n=7, i, somma=0;
	double media=0;
	for(i=0; i<n; i++)
		somma=somma+eta[i];
	media=(double)somma/n;
	printf("%f\n",media);	
	return 0;
}
