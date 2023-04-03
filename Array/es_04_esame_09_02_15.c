/* Scrivere una funzione int check(int a[], int dim) che, dato un array a di interi e la sua dimensione dim, 
restituisce il seguente valore di verita': #{i|i appartiene a [0,dim-1) & (esiste j appartenente a [i+1,dim) per cui a[i]=a[j])}>=2.*/

#include<stdio.h>
#include<stdlib.h>

/*int check(int a[], int dim){
	int i=0, j=0, conta=0, trovato=0;
	while(i<dim && trovato==0){
		conta=0;
		for(j=0; j<dim; j++){	
			if(a[i]==a[j])
				conta++;
		}
		if(conta>=2){
			trovato=1;
		}	
		else if(conta==0 || conta==1){
			i++;
		}
	}
	if(trovato==1)
		return 1;
	else if(trovato==0)
		return 0;
}	*/
int check(int a[], int dim){	//soluzione del prof.
	int conta=0, i=0, esiste=0, j=i+1;
	while(i<dim-1 && conta<2){
		while(j<dim && esiste==0){
			if(a[i]==a[j])
				esiste=1;
			else if(a[i]!=a[j])
				j++;
		}
		if(esiste==1)
			conta++;
		i++;
	}
	return conta>=2;
}
int main(){
	int *a=malloc(100*sizeof(int)),i=0, dim=0;
	scanf("%d",&a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
		dim++;
	}
	//for(i=0; i<dim; i++)	printf("%d\n",a[i]);
	printf("%d\n",check(a,dim));
	return 0;
}

