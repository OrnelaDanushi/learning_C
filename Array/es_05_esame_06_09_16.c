/* Scrivere una funzione che, dato un array a di dimensione dim e un intero m appartenente a [2,dim], 
restituisce il valore di verita' della seguente formula: esiste i,j appartenente a [0,dim) tale che i<j && per ogni k appartenente a [i,j] tale che          
a[k]=a[i] && j-i+1>=m.	*/

#include<stdio.h>

int funzione(int a[], int dim, int m){
	if(m>=2 && m<=dim){
		int i=0, j=i+1, k=i, trovato=0;
		while(i<dim && j<dim && trovato==0){
			k=i;
			a[k]=a[i];
			if(j-i+1>=m)	trovato=1;
			if(a[k]==a[j])	j++;
			else if(a[k]!=a[j]){
				i++;
				j=i+1;
			}
		}
		return trovato;
	}
	else	return 0;
}
int check(int a[], int dim, int m){
	int i=0, trovato=0;
	while(i<=dim-m && !trovato){ 
		int j=m+i-2;
		int k=i+1;
		while(k<=j && !trovato){
			if(a[k]!=a[i])	trovato=1;
			else	k++;
		}
		trovato=!trovato;
		i++;
	}
	return trovato;
}
int main(){
	int a[10], i, m;
	for(i=0; i<10; i++)	scanf("%d", &a[i]);	
	scanf("%d", &m);
	printf("fun%d\n",funzione(a, 10, m));
	printf("che%d\n",check(a, 10, m));
	return 0;
}	

