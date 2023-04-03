//Scrivere un programma che genera gli elementi di un array con interi casuali da 0 a 100 (in un intervallo)
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	int i, *a=malloc(10*sizeof(int));
	//Inizializzo il generatore di numeri casuali con seme time(NULL) ovvero la funzione time con argomento NULL
	srand(time(NULL)); 
	for(i=0; i<10; i++){
		a[i]=rand()%100+1;	//se voglio un intero tra 0 e 99: i=rand()%100;
		printf("Il numero casuale generato alla posizione %d e':%d\n",i, a[i]);
	}	
	return 0;
}
