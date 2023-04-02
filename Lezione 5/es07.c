/*NUMERI MAGGIORI: 
Scrivere un programma che acquisisca da tastiera un intero x e un array di 5 altri interi 
e restituisca il numero di elementi maggiori di x presenti nell'array. 
Il programma deve usare una funzione count_larger che prende come parametri x, 
l'array e la lunghezza dell'array e restituisce il numero di elementi maggiori di x.
Input:	0	12	34	-2	56	2	Output:	4	*/

#include<stdio.h>

int countlarger(int x, int a[], int dima){
	int i, conta=0;
	for(i=0; i<dima; i++){
		if(a[i]>=x)
			conta++;
	}
	return conta;
}

int main(){
	int x, a[5], i;
	scanf("%d", &x);
	for(i=0; i<5; i++)	scanf("%d", &a[i]);
	printf("%d\n", countlarger(x, a, 5));
	return 0;
}
