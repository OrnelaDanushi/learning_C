/* Scrivere una funzione con intestazione int maxocc(int a[], int dim) che restituisce il valore che occorre nell'array il maggior numero di volte. 
Nel caso siano piu' di uno i valori che occorrono il maggior numero di volte, la funzione restituisce quello che occorre per primo. 
Ad esempio se dato l'array {60,20,30,10,20,40,50,80} la funzione deve restituire il valore 20. 
Dato invece l'array {60,20,30,10,20,40,60,80} la funzione deve restituire il valore 60. 
N.B.: Non e' consentito utilizzare comandi come break e goto, ne' utilizzare il comando return all'interno di un ciclo while e for.

#include<stdio.h>

int maxocc(int a[], int dim){
	int *ar=calloc(dim,sizeof(int)),i=0,j=0,conta=0,max,trovato=0,risultato=0;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			if(a[i]==a[j]){
				conta++;
			}
		}
		ar[i]=conta;
		conta=0;
	}
	//for(i=0; i<dim; i++)	printf("%d\n",ar[i]);	
	i=0, max=ar[0];
	for(i=1; i<dim; i++){
		if(ar[i]>max){
			max=ar[i];
		}
	}
	conta=0;
	for(i=0; i<dim; i++){
		if(ar[i]==max)
			conta++;
	}
	if(conta!=1){
		i=0;
		while(i<dim && trovato==0){
			if(ar[i]==max){
				trovato=1;
				risultato=i;			
			}
			else
				i++;	
		}
		//if(trovato==1)
			//printf("%d\n",a[risultato]);	
	}
	return risultato;
}	
int main(){
	int arr[100],i=0,dima=1;
	scanf("%d",&arr[i]);
	while(arr[i]!=0){
		i++;
		scanf("%d",&arr[i]);
	}
	dima=i;
	//for(i=0; i<dima; i++)	printf("%d\n",arr[i]);
	printf("%d\n",arr[maxocc(arr,dima-1)]);
	return 0;
}
