/* Scrivere una funzione int check(int a[], int dima) che restituisca il valore di verita' della seguente formula: 
Esiste j appartenente all'intervallo (0,dim-1) per cui valga che la # {di k appartenente all'intervallo [0,j) & a[k]=a[j]}=1 & 
la # {di k appartenente a (j,dim) & a[k]=a[j]}=1.	*/

#include<stdio.h>
#include<stdlib.h>

/*int check(int a[], int dima){
	int trovato=0, j=1;
	while(j<dima-1 && trovato==0){
		int k=0, conta=0;
		while(k<j && conta<2){
			if(a[k]==a[j]){
				conta++;
			}
			k++;
		}
		if(conta==1){
			conta=0, k=j+1;
			while(k<dima && conta<2){
				if(a[k]==a[j]){
					conta++;
				}
				k++;
			}
			if(conta==1)
				trovato=1;
			else if(conta!=1) 
				j++;
		}
		else if(conta!=1)
			j++;
	}
	printf("%d\n",trovato);
	return trovato;
}*/ //oppure invece di usare i 2 while che si ripetono definiamo una funzione d'ausilio 
int conta(int n, int a[], int inizio, int fine){
	int conta=0;
	while(inizio<=fine && conta<2){
		if(a[inizio]==n)
			conta++;
		inizio++;
	}
	return conta;
}
int check(int a[], int dima){
	int trovato=0, j=1;
	while(j<dima-1 && trovato==0){
		int c=conta(a[j],a,0,j-1);
		if(c==1){
			c=conta(a[j],a,j+1,dima-1);
			if(c==1)
				trovato=1;
			else
				j++;
		}
		else 
			j++;
	}
	printf("%d\n",trovato);
	return trovato;
}
int main(){
	int *arr=malloc(sizeof(int)),i=0,dim=1;
	scanf("%d",&arr[i]);
	while(arr[i]!=0){
		i++;
		scanf("%d",&arr[i]);
		dim++;
	}
	//for(i=0; i<dim-1; i++)	printf("%d\n",arr[i]);
	check(arr,dim-1);
	return 0;
}
