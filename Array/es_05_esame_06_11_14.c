/* 
Scrivere una funzione int foo(int a[], int dima) che, dato un array di interi a, di dimensione dima, 
restituisce il numero di elementi in a che precedono la seconda occorrenza del primo elemento ripetuto piu' volte in a. 
La funzione restituisce 0 se ogni elemento occorre in a esattamente una volta. 
es a={60,20,30,10,20,10,20,30}=4, a={60,20,30,10,50,70,40,80}=0. */

#include<stdio.h>

int foo(int a[], int dim){
	int i, j, conta=0, max=0, el=0, ris=0;
	for(i=0; i<dim; i++){
		for(j=i; j<dim; j++)
			if(a[i]==a[j])
				conta++;
		if(conta>max){
			max=conta;
			el=a[i];
		}
		conta=0;
	}
//	printf("%d\n",max);
//	printf("%d\n",el);
	if(max==1 || max==0)	return 0;
	i=0, j=1;
	while(j<=2){
		if(a[i]==el)
			j++;
		ris++;		
		i++;
	}
	ris--;
	return ris;
}
int main(){
	int a[100], i=0, dima=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}
	dima=i;
	for(i=0; i<dima; i++)	printf("%d ", a[i]);
	printf("\n");
	printf("%d\n",foo(a,dima));
	return 0;
}
