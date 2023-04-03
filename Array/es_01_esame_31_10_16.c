/* Scrivere una funzione che, dato un array a di dimensione dim, restituisce il seguente valore di verita': 
#{j|j appartiene [0,dim-1) && per ogni i|i appartiene a [j+1,dim) allora a[i]!=a[j]}=dim-1, ovvero che TUTTI gli elementi dell'array siano tra loro diversi. */

#include<stdio.h>
#include<stdlib.h>

int funzione(int a[], int dim){
	int i, j=0, conta=0, temp=0;
	for(j=0; j<dim; j++){
		conta=0;
		for(i=0; i<dim; i++){
			if(a[j]!=a[i])	conta++;
		}
		if(conta==dim-1)	temp++;
	}
	if(temp==dim)	return 1;
	else return 0;
}

int main(){
	int dima, *a, i;
	scanf("%d", &dima);
	a=(int *)malloc(dima*sizeof(int));
	for(i=0; i<dima; i++)	scanf("%d", &a[i]);
	printf("%d\n", funzione(a, dima));
	return 0;
}
