/*Si realizzi una funzione str3cat che accetta come input 3 stringhe (ciascuna lunga al piu' 40 caratteri) 
e ritorni una nuova stringa ottenuta come la concatenazione, separata da spazi, delle tre. 
Il programma deve leggere 3 stringhe e stampare in uscita le 3 stringhe seguite dal risultato dell'invocazione di str3cat sulle stesse.
input:	ciao	a	tutti
output:	ciao	a	tutti	ciao a tutti	*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 1000

void str3cat(char *str1, char *str2, char *str3){
	printf("%s\n",str1);
	printf("%s\n",str2);
	printf("%s\n",str3);
	printf("%s %s %s\n",str1,str2,str3);
}
int main(){
	char s1[MAXLEN],s2[MAXLEN],s3[MAXLEN];
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	str3cat(s1,s2,s3);
	return 0;
}
