/*SIZEOF:
Scrivere un programma che legga da tastiera un numero intero x 
e stabilisca il numero di byte necessario a memorizzare x variabili di tipo intero*/

#include<stdio.h>
int main(){
	int x;
	scanf("%d",&x);
	printf("%d\n",sizeof(int)*x);
	return 0;
}
