/*CAPITALIZE: Scrivere un programma che legga da tastiera un carattere alfabetico in minuscolo e stampi lo stesso carattere in maiuscolo. NB: Ogni carattere puo' essere visto come un intero;
Input:	c	Output: C */
#include<stdio.h>
int main(){
	char x;
	scanf("%c",&x);
	printf("%c\n",x-32);
	return 0;
}
