/* Scrivere una funzione int contaUnico(int a[], int b[], int dima, int dimb) che, dati due array a e b di dimensioni rispettivamente dima e dimb, 
restituisce il numero di elementi diversi di a che sono contenuti in b.
Input: 8//dima 60 20 30 10 20 40 60 80		6//dimb 60 30 30 10 20 60	
Output:4//valori 60 20 30 10 di b appartenenti ad a */

#include<stdio.h>
#include<stdlib.h>

int conta(int elem, int a[], int start, int end){
	int i, conta=0;
	for(i=start; i<end; i++)
		if(a[i]==elem)	conta++;
	return conta;
}
int contaUnico(int a[], int b[], int dima, int dimb){
	int i, j=0, temp=0;
	for(j=0; j<dimb; j++){
		if(conta(b[j], b, j, dimb)==1){
			if(conta(b[j], a, 0, dima)>0)
				temp++;
		}
	}
	return temp;
}
int main(){
	int dima, *a, i, dimb, *b;
	scanf("%d", &dima);
	a=(int *)malloc(dima*sizeof(int));
	for(i=0; i<dima; i++)	scanf("%d", &a[i]);
	scanf("%d", &dimb);
	b=(int *)malloc(dimb*sizeof(int));
	for(i=0; i<dimb; i++)	scanf("%d", &b[i]);
	printf("%d\n", contaUnico(a, b, dima, dimb));
	return 0;
}
