/*Scrivere un programma che legga da tastiera un numero n compreso tra 20 e 89 e stampi il suo valore espresso come stringa.
input:	23	output:	ventitre
input: 81	output:	ottantuno	*/

#include<stdio.h>
#include<stdlib.h>

void funzione(int value){
	int i=0;
	char **decine=(char **)malloc(9*sizeof(char *));
	for(i=0; i<9; i++){
		decine[0]="dieci";
		decine[1]="dieci";
		decine[2]="venti";
		decine[3]="trenta";
		decine[4]="quaranta";
		decine[5]="cinquanta";
		decine[6]="sessanta";
		decine[7]="settanta";
		decine[8]="ottanta";
	}
	char **unita=(char**)malloc(10*sizeof(char*));
	for(i=0; i<10; i++){
		unita[0]="zero";
		unita[1]="uno";
		unita[2]="due";
		unita[3]="tre";
		unita[4]="quattro";
		unita[5]="cinque";
		unita[6]="sei";
		unita[7]="sette";
		unita[8]="otto";
		unita[9]="nove";
	}
	int newvalue=0;
	if(value/10 != 0){
		newvalue=value/10;
		printf("%s", decine[newvalue]);
	}if(value%10!=0){
		newvalue=value%10;
		printf("%s", unita[newvalue]);
	}
	printf("\n");
}	
int main(){
	int n;
	scanf("%d", &n);	
	printf("%d\n", n);
	funzione(n);
	return 0;
}
