/* Scrivere una funzione che, dato un array a di dimensione dim, rstituisce il seguente valore di verita': 
la #{j|j appartiene a [0,dim) & a[j]<=0} > #{j|j appartiene [0,dim) & a[j]>0}.	*/

#include<stdio.h>
#include<stdlib.h>

/*int check(int a[], int dim){
	int i=0, contaneg=0, contapos=0;
	for(i=0; i<dim; i++){
		if(a[i]<=0)
			contaneg++;
		else if(a[i]>0)
			contapos++;
	}
	if(contaneg>contapos)
		return 1;
	else if(contaneg<=contapos)
		return 0;
}	*/

int check(int a[],int dim){	//correzione proposta
	int contapos=0, j;
	for(j=0; j<dim; j++)
		if(a[j]>0)
			contapos++;
	return (dim>2*contapos);
}
int main(){
	int *arr=malloc(100*sizeof(int)),dim=1,i=0;
	scanf("%d",&arr[i]);
	while(arr[i]!=0){
		i++;
		scanf("%d",&arr[i]);
		dim++;
	}	
	//for(i=0; i<dim-1; i++)	printf("%d\n",arr[i]);
	printf("%d\n",check(arr,dim-1));
	return 0;
}
