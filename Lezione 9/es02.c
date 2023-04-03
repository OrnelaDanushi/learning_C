/*Si realizzi un programma che prenda in ingresso una stringa S (contenente anche spazi, di al piu' 40 caratteri) e un carattere c. 
Il programma deve stampare in uscita il numero di occorrenze di c in S. N.B. c'e' differenza tra maiuscole e minuscole.
input:	Hello World	o	output:	2	*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void contaoccorrenze(char *s, char c){
	int i=0, conta=0;
	while(s[i]!='\0'){
		if(s[i]==c){
			conta++;
			i++;
		}
		else if(s[i]!=c){
			i++;
		}
	}
	printf("%d\n",conta);
}
int main(){
	char *s=malloc(sizeof(char));
	fgets(s,40,stdin); //legge al piu' 40 caratteri o comunque fino a \n compreso, compresi gli spazi tra le parole
	char c;
	scanf("%c",&c);
	contaoccorrenze(s,c);	
	return 0;
}
