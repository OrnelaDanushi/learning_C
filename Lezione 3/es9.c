/*STAMPA RETTANGOLO: 
Scrivere un programma che stampi un rettangolo di 10 righe e 3 colonne la cui cornice 
sia costituita da caratteri asterisco e la parte interna da 'X'.
Output:		***
		*X*
		*X*
		*X*
		*X*
		*X*
		*X*
		*X*
		*X*
		***		*/

#include<stdio.h>
int main(){
	int i=0;
	if(i==0)		printf("***\n");
	for(i=1; i<9; i++)	printf("*X*\n");
	if(i==9)		printf("***\n");

	/*oppure
	printf("***\n");
	int i=0;
	for(i=0; i<8; i++)	printf("*X*\n");
	printf("***\n");
	*/

	return 0;
}
