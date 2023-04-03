/* Scrivere una funzione che, dati due array di interi a e b e le loro dimensioni dima e dimb, 
restituice il seguente valore di verita': 
esiste i appartenente a [0, dima) tale che #{j|j appartiene a [0, dimb) & a[i]=b[j]}>#{k|k appartiene a [0, dima) & a[i]=a[k]}. 	*/

#include<stdio.h>
#include<stdlib.h>

/*int check(int a[], int b[], int dima, int dimb){
	int i=0, j=0, conta=0, comune=0, max=0, max1=0, *arr=malloc(dima*sizeof(int)), *arr1=malloc(dima*sizeof(int));
	for(i=0; i<dima; i++){
		for(j=0; j<dimb; j++){
			if(a[i]==b[j])
				conta++;
		}
		arr[i]=conta;
		conta=0;
	}
	for(i=0; i<dima; i++){
		if(arr[i]>max)
			max=arr[i];
	}
	for(i=0; i<dima; i++){
		for(j=0; j<dima; j++){
			if(a[i]==a[j])
				comune++;
		}
		arr1[i]=comune;
		comune=0;	
	}
	for(i=0; i<dima; i++){
		if(arr1[i]>max1)
			max1=arr1[i];
	}	
	if(max1>max)
		return 0;
	else 
		return 1;
}	*/
int check(int a[], int b[], int dima, int dimb){	//soluzione del prof.
	int i=0, trovato=0, conta_a=0, conta_b=0, j=0, k=0;
	while(i<dima && trovato==0){
		for(j=0; j<dimb; j++){
			if(a[i]==b[j])
				conta_b++;
		}
		for(k=0; k<dima; k++){
			if(a[i]==a[k])
				conta_a++;
		}
		trovato=conta_b>conta_a;
		i++;
	}
	return trovato;
}
int main(){
	int *a=malloc(100*sizeof(int)), *b=malloc(100*sizeof(int)), i=0, j=0, dima=0, dimb=0;
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
	//for(i=0; i<dima; i++)	printf("%d\n",a[i]);
	//for(j=0; j<dimb; j++)	printf("%d\n",b[j]);
	printf("%d\n",check(a,b,dima,dimb));
	return 0;
}
