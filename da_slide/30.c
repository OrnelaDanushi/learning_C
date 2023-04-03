/*Questo programma legge i valori da tastiera dell'array e li ristampa nell'ordine inverso a come sono stati letti.*/
#include<stdio.h>
int main(){
	int arr[7], i;
	for(i=0; i<7; i++)
		scanf("%d",&arr[i]);
	for(i=6; i>=0; i--)
		printf("%d\n",arr[i]);
	return 0;
}
