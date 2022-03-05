/*Dato lo scheletro di codice qui riportato (e che puo' essere scaricare dagli allegati), lo si completi aggiungendo l'implementazione delle funzioni richieste.
#include<stdio.h>
#include<stdlib.h>
int *leggiInput(int *dim);	//funzioni da implementare:
int *eliminaDup(int *vect, int dim, int *dim_nodup);
int ugualeASomma(int *vect, int dim);
int *maggioreDeiSuccessivi(int *vect, int dim);
int main(){
	int *input, *nodup, *results, dim, dim_nodup, i;
	input=leggiInput(&dim);	//legge l'input
	printf("Stampa dei valori in input: (%d valori)\n",dim);
	for(i=0; i<dim; i++)
		printf("%d\n",input[i]);
	nodup=eliminaDup(input,dim,&dim_nodup);	//elimina i duplicati
	printf("Stampa dei valori senza duplicati: (%d valori)\n",dim_nodup);
	for(i=0; i<dim_nodup; i++)
		printf("%d\n",nodup[i]);
	printf("Risultato di ugualeASomma: %d\n", ugualeASomma(nodup,dim_nodup));	//esegue ugualeASomma
	results=maggioreDeiSuccessivi(nodup,dim_nodup);	//esegue maggioreDeiSuccessivi
	printf("Risultato maggioreDeiSuccessivi:\n");
	for(i=0; i<dim_nodup; i++)
		printf("%d\n", results[i]);
	return 0;
}
Le funzioni devono implementare le seguenti operazioni:
-leggiInput: legge un numero n e successivamente n interi, inserendoli in un array nell'ordine in cui vengono letti. La funzione restituisce l'array e scrive, nell'indirizzo puntato da dim, il valore n, ovvero la dimensione dell'array;
-eliminaDup: la funzione accetta come parametri un array di interi vect e la sua dimensione dim. Deve creare e restituire un nuovo array di interi contenente solo la prima occorrenza degli elementi contenuti nell'array iniziale (mantenendo il loro ordine). Nell'indirizzo puntato da dim_nodup viene memorizzata la dimensione del nuovo array;
-ugualeASomma: la funzione accetta come parametri un array di interi vect e la sua dimensione dim. Restituisce 1 se viene soddisfatta la proprieta': esiste i appartenente a [0,dim) tale che vect[i]=alla sommatoria per j appartenente a [0,dim) e j!=i del vect[j] oppure 0 in caso contrario;
-maggioreDeiSuccessivi: la funzione accetta come parametri un array di interi vect e la sua dimensione dim. Ritorna un array di interi, dove ciascuna posizione i assume valore 1 se vale la seguente proprieta': per ogni j appartenente a [i+1,dim) tale che vect[i]>vect[j] mentre assume valore 0 in caso contrario. Si noti che per l'ultimo elemento dell'array la condizione e' sempre soddisfatta.
input:	6	2	2	3	10	4	1
output:	Stampa dei valori in input: (6 valori)	2	2	3	10	4	1	Stampa dei valori senza duplicati: (5 valori)	2	3	10	4	1	Risultato di ugualeASomma: 1	Risultato maggioreDeiSuccessivi:	0	0	1	1	1	*/ 

#include<stdio.h>
#include<stdlib.h>

// Funzioni  da implementare
int *leggiInput(int *dim){
	scanf("%d", &(*dim));	//oppure 	scanf("%d", dim);	
	int *a=(int *)malloc((*dim)*sizeof(int)), i;
	for(i=0; i<*dim; i++)	scanf("%d", &a[i]);
	return a;
}
int *eliminaDup(int *vect, int dim, int *dimnodup){
	if(dim!=0){
		*dimnodup=1;
		int *a=(int *)malloc((*dimnodup)*sizeof(int)), i, j, conta=0;
		a[0]=vect[0];
		for(i=1; i<dim; i++){
			for(j=0; j<*dimnodup; j++)	if(vect[i]==a[j])	conta++;	
			if(conta==0){
				(*dimnodup)++;
				a=realloc(a,(*dimnodup)*sizeof(int));
				a[(*dimnodup)-1]=vect[i];
			}
			conta=0;
		}
		return a;
	}
}
int ugualeASomma(int *vect, int dim){	
//per calcolare questa funzione non posso ordinare l'array
	int i=0, somma=0, j, trovato=0;
	while(i<dim && trovato==0){
		for(j=0; j<dim; j++)	if(i!=j)	somma=somma+vect[j];
		if(vect[i]==somma)	trovato=1;
		else{ 
			somma=0;
			i++;
		}
	}
	return trovato;
}
int *maggioreDeiSuccessivi(int *vect, int dim){
	int i, j, *a=(int *)malloc(dim*sizeof(int)), trovato=0;
	for(i=0; i<dim-1; i++){
		j=i+1;
		while(j<dim && trovato==0){
			if(vect[i]>vect[j])	j++;
			else trovato=1;	
		}
		if(trovato==1) a[i]=0;
		else a[i]=1;
		trovato=0;
	}
	a[dim-1]=1;
	return a;
}
int main(){
	int *input, *nodup, *results, dim, dimnodup, i;
	
	//Legge l’input
	input=leggiInput(&dim);
	printf("Stampa dei valori in input: (%d valori)\n", dim);
	for(i=0; i<dim; i++)	printf("%d\n", input[i]);
	
	//Elimina i duplicati
	nodup=eliminaDup(input, dim, &dimnodup);
	printf("Stampa dei valori senza duplicati: (%d valori)\n", dimnodup);
	for(i=0; i<dimnodup; i++) printf("%d\n", nodup[i]);

	//Esegue ugualeASomma
	printf("Risultato di ugualeASomma: %d\n", ugualeASomma(nodup, dimnodup));

	//Esegue maggioreDeiSuccessivi
	results=maggioreDeiSuccessivi(nodup, dimnodup);
	printf("Risultato maggioreDeiSuccessivi:\n");
	for(i=0; i<dimnodup; i++)	printf("%d\n", results[i]);
	return 0;
}
