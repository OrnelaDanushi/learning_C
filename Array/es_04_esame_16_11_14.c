/* Scrivere una funzione int check(int a[], int b[], int dima, int dimb) che, 
dati due array di interi a e b, di dimensione dima e dimb rispettivamente, 
restituisce il seguente valore di verita': per ogni i appartenente a [0,dima) tale che 
(#{j|j appartiene a [0,dimb) & a[i]=b[j]}=0 oppure #{j|j appartiene a [0,dimb) & a[i]=b[j]}>=2.	*/

#include<stdio.h>

int check(int a[], int b[], int dima, int dimb){
	int i=0, j=0, conta=0;
	for(i=0; i<dima; i++)
		for(j=0; j<dimb; j++)
			if(a[i]==b[j])
				conta++;
	if(conta==1)	return 0;
	else if(conta!=1)	return 1;
}

int main(){
	int a[100], b[100], i=0, j=0, dima=0, dimb=0;
	scanf("%d",&a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
		dima++;
	}
	scanf("%d",&b[j]);
	while(b[j]!=0){
		j++;
		scanf("%d",&b[j]);
		dimb++;
	}
	for(i=0; i<dima; i++)	printf("%d\n",a[i]);
	for(j=0; j<dimb; j++)	printf("%d\n",b[j]);
	printf("%d\n",check(a,b,dima,dimb));
	return 0;
}
