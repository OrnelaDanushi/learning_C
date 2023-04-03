/* Scrivere una funzione che, dato un array di interi a e la sua dimensione dim, restituisce il seguente valore di verita': 
esiste i, j appartenenti a [0,dim) tale che a[i]!=a[j] & #{k|k appartiene a [0,dim) & a[k]=a[i]}=#{h|h appartiene a [0,dim) & a[h]=a[j]}. */

#include<stdio.h>

/*int contaocc(int a[], int dim, int val){	//funzione ausiliaria che conta quante volte e' presente un elemento nell'array
	int i, count=0;
	for(i=0; i<dim; i++)	if(a[i]==val)	count++;
	return count;
}
int check(int a[], int dim){
	int i=0, j=1;
	while(j<dim){
		if(a[i]!=a[j]){
			if(contaocc(a,dim,a[i])==contaocc(a,dim,a[j]))	return 1;
		}
		j++;
	}
	return 0;
}	*/

/*int check(int a[], int dim){
	int i=0, j=0;
	for(i=0; i<dim; i++){
		for(j=i+1; j<dim; j++){
			if(a[i]!=a[j]){
				if(conta(a,dim,a[i])==conta(a,dim,a[j]))
					return 1;
			}
		}
	}
	return 0;
}*/
int check(int a[], int dim){	//soluzione proposta dal prof
	int i=0, trovato=0, j=i+1, conta=0, k=0;
	while(i<dim && trovato==0){
		while(j<dim && trovato==0){
			if(a[i]==a[j])
				j++;
			else if(a[i]!=a[j])
				trovato=1;
			if(trovato==1){	
				for(k=0; k<dim; k++)
					if(a[k]==a[i])
						conta++;
					else if(a[k]==a[j])
						conta--;
				if(conta!=0){
					trovato=0;
					j++;
				}
			}
		}
		i++;	
	}
	return trovato;
}	
int main(){
	int a[100], i=0, dim=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d", &a[i]);
	}
	dim=i;
	for(i=0; i<dim; i++)	printf("%d ", a[i]);
	printf("\n");
	printf("%d\n",check(a,dim));
	return 0;
}
