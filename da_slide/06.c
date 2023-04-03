//come funziona la strlen()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strlengg(char s[]){	//no strlen perche' gia' presente in libreria -> deve avere nome diverso
	char *p = s;
	while(*p!='\0')
		p++;	//usa un puntatore per restituire il numero di caratteri, poteva usare
	return p-s;		//anche un intero
}
/*int strlengg(char s[]){
	int i=0, conta=0;
	while(s[i]!='\0'){
		conta++;
		s[i++];
	}
	return conta;
}
int main(){
	char *str=malloc(sizeof(char));
	fgets(str,20,stdin);
	int risultato=strlengg(str)-1;	//togliendo lo spazio finale di chiusura
	printf("%d\n",risultato);
	return 0;
}
