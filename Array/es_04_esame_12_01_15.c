/* Scrivere una funzione int check(int a[], int dim) che, dato un array a di interi e la sua dimensione dim, 
restituisce il seguente valore di verita': 
per ogni i appartenente [0,dim-1) per cui vale che esiste j appartenente [i+1,dim) e a[i]>a[j]. 
HINT: La proprieta' e' soddisfatta solo se il valore minimo dell'array occorre una sola volta e in ultima posizione.	*/

#include<stdio.h>
/*int check(int a[], int dim){	
	int i, j, trovato=0;
	for(i=0; i<dim-1; i++){
		trovato=0;
		j=i+1;
		while(j<dim && trovato==0){
			if(a[i]>=a[j])
				trovato=1;
			else if(a[i]<a[j])
				j++;
		}
		if(trovato==0)	return 0;
	}
	return 1;
}	*/
/* //oppure
int check(int a[], int dim){
	int i=0, trovato=0, conta=0;
	while(i<dim && trovato==0){
		if(a[i]<a[dim-1])
			trovato=1;
		else{
			if(a[i]==a[dim-1]){
				conta++;
				i++;
			}else if(a[i]>a[dim-1])
				i++;
		}
	}
	if(trovato==1)	return 0;
	else{
		if(trovato==0 && conta==1)
			return 1;
		else if(trovato==1 && conta!=1)
			return 0;
	}
}	*/
int check(int a[], int dim){	//soluzione proposta dal prof
	int posmin=0, occmin=1, j;
	for(j=1; j<dim; j++){
		if(a[j]==a[posmin])
			occmin++;
		else if(a[j]<a[posmin]){
			posmin=j;
			occmin=1;
		}
	}
//	printf("%d\n", posmin);
//	printf("%d\n", occmin);	
//	if(posmin==dim-1 && occmin==1)	return 1;
//	return 0;
	return (posmin==dim-1 && occmin==1);
}	
int main(){
	int arr[100], i=0, dim=0;
	scanf("%d", &arr[i]);
	while(arr[i]!=0){
		i++;
		scanf("%d", &arr[i]);
	}
	dim=i;	
	for(i=0; i<dim; i++)	printf("%d ", arr[i]);
	printf("\n");
	printf("%d\n",check(arr,dim));
	return 0;
}
