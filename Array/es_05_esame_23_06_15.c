/* Scrivere una funzione che, dati due array di interi a e b e le loro dimensioni dima e dimb, 
restituisce il seguente valore di verita': 
se I non e' vuoto restituisce min I dove I={i|i appartiene a [0,dima) & #{j|j appartiene a [0,dimb) & a[i]=b[j]}mod2=0}, 
altrimenti se I e' vuoto restituisce dima. */

#include<stdio.h>

int check(int a[], int b[], int dima, int dimb){
	int i, j, arr[dima], min=0, conta=0;
	if(dimb==0)	return dima;
	else if(dimb!=0){
		for(i=0; i<dima; i++){
			for(j=0; j<dimb; j++){
				if(a[i]==b[j])
					conta++;
			}
			arr[i]=conta;
			//printf("%d\n",conta);
			conta=0;
		}
		min=a[0];	
		for(i=0; i<dima; i++){
			if(arr[i]%2==0 && a[i]<=min)	//VARIANTE: restituisce min dell'a[i] se la # degli elementi in comune sono dispari
				min=a[i];
		}
		if(arr[i]%2!=0 && a[0]==min)
			return dima;
		else 
			return min;
	}
}	
int main(){
	int a[100], b[100], i=0, dima=0, dimb=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d", &a[i]);
	}
	dima=i;
	i=0;	
	scanf("%d", &b[i]);
	while(b[i]!=0){
		i++;
		scanf("%d", &b[i]);
	}
	dimb=i;
	for(i=0; i<dima; i++)	printf("%d ", a[i]);
	printf("\n");
	for(i=0; i<dimb; i++)	printf("%d ", b[i]);
	printf("\n");
	printf("%d\n",check(a,b,dima,dimb));
	return 0;
}
