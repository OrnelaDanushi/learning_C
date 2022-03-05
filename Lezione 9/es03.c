/*Si realizzi un programma C che prenda in ingresso una stringa S (di al piu' 40 caratteri e contenente anche spazi) e stampi la stessa stringa invertita. BONUS(no extra punti): farlo in place, ossia senza allocare/utilizzare spazio aggiuntivo per la stringa invertita ma modificando direttamente la stringa letta.
input:	Stringa invertita	output:	atitrevni agnirtS	*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void invertita(char *s){
	int i=0, lunghezza=0; 
	while(s[i]!='\0'){
		lunghezza++;
		i++;
	}
	for(i=lunghezza-2; i>=0; i--){
		printf("%c",s[i]);
	}
	printf("\n");
}
int main(){
	char *s=malloc(sizeof(char));
	fgets(s,40,stdin);
	invertita(s);
	return 0;
}
