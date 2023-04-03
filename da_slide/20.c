/*ARRAY DI STRINGHE: Scrivere un programma che legga da tastiera un array di stringhe. La prima riga dell'input contiene la dimensione n dell'array, 
le righe successive contengono gli elementi dell'array, una stringa per riga, ognuna di lunghezza massima 100 caratteri.	*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, n;
	scanf("%d", &n);
	char **a=(char **)malloc(n*sizeof(char *));
	for(i=0; i<n; i++){
		a[i]=(char *)malloc(101*sizeof(char));
		scanf("%s", a[i]);
	}
	for(i=0; i<n; i++)
		printf("%s ",a[i]);
	printf("\n");
	for(i=0; i<n; i++)
		free(a[i]);	//LIBERARE OGNI SINGOLA STRINGA
	free(a);	//LIBERARE L'ARRAY DI STRINGHE
	return 0;
}
