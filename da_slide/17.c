/*SOTTOARRAY DI SOMMA MASSIMA
Dato un array a di n interi (positivi e negativi) individuare il sottoarray di somma massima.
-input = array a di interi
-output = la somma del sottoarray di somma massima	
Realizzare la soluzione ottima sapendo che:
-la somma dei valori in ogni prefisso dl sottoarray ottimo e' positiva, se cosi' 
non fosse potremmo eliminare tale prefisso ottenendo un sottoarray di somma maggiore (assurdo)
-il valore immediatamente precedente al primo valore del sottoarray ottimo e' negativo, 
se cosi' non fosse potremmo aggiungere tale valore ottenendo un sottoarray di somma maggiore (assurdo)
*/
#include<stdio.h>
#include<stdlib.h>
//soluzione cubica
/*
int sommamassima(int a[], int dim){
	int max=a[0], i, j, k, somma=0;
	for(i=0; i<dim; i++){
		for(j=i+1; j<dim; j++){
			somma=0;
			for(k=i; k<=j; k++)
				somma=somma+a[k];
			if(somma>max)
				max=somma;
		}	
	}
	return max;
}
*/

//soluzione cubica
/*
int sommamassima(int a[], int dim){
	int max=a[0], i, j, somma=0;
	for(i=0; i<dim; i++){
		somma=0;
		for(j=1; j<dim; j++){
			somma=somma+a[j];
			if(somma>max)
				max=somma;
		}
	}
	return max;
}
*/
//soluzione lineare
int sommamassima(int a[], int dim){
	int max=a[0], i, somma=0;
	for(i=0; i<dim; i++){
		if(somma>0)
			somma=somma+a[i];
		else
			somma=a[i];
		if(somma>max)
			max=somma;
	}
	return max;
}
int main(){
	int n, i;
	scanf("%d", &n);
	int *a=malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("%d\n",sommamassima(a,n));	
	return 0;
}
