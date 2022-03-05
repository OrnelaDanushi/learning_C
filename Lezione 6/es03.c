/*ALLOCAZIONE DINAMICA ARRAY: Si realizzi un programma che legga un intero N da tastiera e lo passi ad una funzione che alloca un array di dimensione N e lo riempie con i valori dei primi N multipli di 5. Nel main si stampi a video il contenuto dell'array restituito dalla funzione. Assunzione: N e' un intero strettamente maggiore di 0.
Input:	5		Output:	5	10	15	20	25	*/
#include<stdio.h>
#include<stdlib.h>
void allocazione(int n, int *a){
	int i;
	a=(int *)malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		*a=5*(i+1); 
		printf("%d\n",*a);
	}
}
int main(){
	int x, *v, i;
	scanf("%d",&x);
	allocazione(x,v);
	return 0;
}
/* oppure
void funzione(int n){
	int *a=(int *)malloc(n*sizeof(int)), i;
	for(i=0; i<n; i++)	a[i]=(i+1)*5;
	for(i=0; i<n; i++)	printf("%d\n", a[i]);
}
int main(){
	int n;
	scanf("%d", &n);
	funzione(n);
	return 0;
}
