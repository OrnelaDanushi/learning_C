/*RIDIMENSIONAMENTO ARRAY: 
Si realizzi un programma che legga 6 interi da tastiera e assegni i primi 5 valori letti 
ad altrettante posizioni di un array; si assuma di memorizzare il sesto valore in una variabile N. 
Si scriva una funzione che dato l'array inizializzato con i 5 valori letti da tastiera e l'intero N, 
restituisca l'array in input ridimensionato per contenere 5+N elementi, 
tale che ciascuno dei nuovi N elementi corrisponda alla somma dei numeri che lo precedono nell'array 
ad es: arr[i]=sommatoria per j=0 a i-1 di arr[j]. 
Nel main, si stampi a video il contenuto dell'array restituito dalla funzione. 
Input:	-1	2	3	0	4	3	Output:	-1	2	3	0	4	8	16	32	*/

#include<stdio.h>
#include<stdlib.h>
void posizioni(int *v, int f, int somma){
	v=(int *)malloc(f*sizeof(int));
	int i=0;
	v[i]=somma;
	for(i=1; i<f; i++){
		*v=(*v)*2;
		printf("%d\n",*v);
	}
}
int main(){
	int a, b, c, d, e, f, i=0;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	scanf("%d",&f);
	int *arr=(int *)malloc(5*sizeof(int));
	arr[i]=a;
	arr[i+1]=b;
	arr[i+2]=c;
	arr[i+3]=d;
	arr[i+4]=e;
	for(i=0; i<5; i++)
		printf("%d\n",arr[i]);
	int somma=a+b+c+d+e;
	printf("%d\n",somma);
	posizioni(arr,f,somma);
	return 0;
}

/*oppure
int main(){
	int n, *a=(int *)malloc(5*sizeof(int)), i, j=0;
	for(i=0; i<5; i++)	scanf("%d", &a[i]);
	scanf("%d", &n);
	a=realloc(a, (5+n)*sizeof(int));
	for(i=5; i<(5+n); i++){
		for(j=0; j<i; j++)
			a[i]=a[i]+a[j];
	}
	for(i=0; i<5+n; i++)	printf("%d\n", a[i]);
	return 0;
}	*/
