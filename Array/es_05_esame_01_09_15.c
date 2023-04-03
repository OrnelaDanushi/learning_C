/* Scrivere una funzione che, dato un array di interi a, la sua dimensione dima ed un intero r, restituisce il seguente valore di verita': 
(per ogni i, j appartenente a [0, dima) vale che j>i & a[i]=a[j] allora j-i=r).	*/

#include<stdio.h>

/*int check(int a[], int dima, int r){
	int i=0, j=0, trovato=0;
	while(i<dima-1){
		j=i+1;
		while(j<dima){
			if(a[i]==a[j] && j-i==r)	return 1;
			else if(a[i]!=a[j]) j++;
		}
		i++;
	}
	return 0;
}	*/	
int check(int a[], int dima, int r){	//soluzione del prof
	int i=0, trovato=0, j=0;
	while(i<dima && trovato==0){
		j=i+1;
		while(j<dima && trovato==0){
			if(a[i]==a[j] && (j-i)!=r)
				trovato=1;
			else
				j++;
		}
		i++;
	}
	return (!trovato);
}	
int main(){
	int a[100], i=0, dima=0, r;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}
	dima=i;
	scanf("%d",&r);
	for(i=0; i<dima; i++)	printf("%d ", a[i]);
	printf("\n");
	printf("%d\n",check(a,dima,r));
	return 0;
}
