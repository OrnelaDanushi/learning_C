/*Si realizzi un programma che legga una parola da tastiera e stampi 1 se la parola e' palindroma, 0 altrimenti. 
Ricordiamo che una parola e' palindroma se letta a rovescio rimane identica. N.B. la parola e' lunga al piu' 40 caratteri. 
input:	ingegni	output:	1	*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void palindroma(char *str){
	int i=0, j=0, trovato=0;
	char str2[strlen(str)];
	i=strlen(str)-2;
	do{
		for(j=0; j<strlen(str); j++){
			str2[j]=str[i];
			i--;
		}
		
	}while(i>=0);
	i=0;
	while(i<=strlen(str)-2 && trovato==0){
		if(str[i]!=str2[i])
			trovato=1;
		else
			i++;
	}	
	if(trovato==1)
		printf("0\n");
	else if(trovato==0)
		printf("1\n");
	
}
int main(){
	char *s=malloc(sizeof(char)), *s2=malloc(sizeof(char));
	int i=0;
	fgets(s,40,stdin);
	palindroma(s);	
	return 0;
}
