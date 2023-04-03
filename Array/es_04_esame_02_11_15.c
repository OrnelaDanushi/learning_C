/* Scrivere una funzione con intestazione int check(int a[], int dim, int n, int m) che, dati un array, la sua dimensione dim e due interi n e m, 
restituisce 1 se il valore massimo in a occorre nell'array piu' di n volte e meno di m volte, 0 altrimenti. 
N.B.: Non e' consentito utilizzare comandi come break e goto, ne' utilizzare il comando return all'interno di un ciclo while e for.

#include<stdio.h>
/*int check(int a[], int dim, int n, int m){
	int max=a[0],i,conta=0;
	for(i=1; i<dim; i++){
		if(a[i]>=max){
			max=a[i];
		}
	}
	for(i=0; i<dim; i++){
		if(a[i]==max){
			conta++;
		}
	}	
	if(conta>n && conta<m)	return 1;
	else	return 0;
}	*/
int check(int a[], int dim, int n, int m){ 	//soluzione proposta dal prof
	int i, massimo=a[0], occ_massimo=1;
	for(i=1; i<dim; i++){
		if(a[i]>massimo){
			massimo=a[i];
			occ_massimo=1;
		}
		else if(massimo==a[i])
			occ_massimo=occ_massimo+1;
	}
	return (occ_massimo>n && occ_massimo<m);
}
int main(){
	int arr[100],i=0,dima=1,valmin,valmax;
	scanf("%d",&arr[i]);
	while(arr[i]!=0){
		i++;
		scanf("%d",&arr[i]);
	}
dima=i;	
	for(i=0; i<dima; i++)		printf("%d\n",arr[i]);
	printf("Leggi il valore minimo di occorrenza: \n");
	scanf("%d",&valmin);
	printf("Leggi il valore massimo di occorrenza: \n");
	scanf("%d",&valmax);
	printf("%d\n",check(arr,dima-1,valmin,valmax));
	return 0;
}
