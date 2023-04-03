/*Questo programma permette di inserire i valori di un'array dinamico, quindi da tastiera si immette la dimensione e si completa con i rispettivi valori dell'array.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int N,i;
	int *ptr;
	printf("Immettere la dimensione dell'array ");
	scanf("%d",&N);
	ptr=malloc(N*sizeof(int));
	if(ptr!=NULL){
		for(i=0; i<N; i++){
			printf("Immettere il valore della posizione %d nell'array ",i+1);
			scanf("%d",(ptr+i));
		}
		printf("Hai inserito i valori: ");
		for(i=0; i<N; i++){
			printf("%d ", ptr[i]);
		}
		printf("\n");
	}
	return 0;
}
