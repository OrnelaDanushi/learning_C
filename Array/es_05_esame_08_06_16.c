/* Scrivere una funzione che, dato un array di interi a e la sua dimensione dim restituisce il seguente valore di verita': 
esiste i tale che i appartiene a [0,dim) & per ogni j apprtenente [0,i) vale che a[j]>a[i] & #{k|k appartiene a [i+1, dim) & a[k]>[i]}=1.	*/

#include<stdio.h>
#include<stdlib.h>

/*int cerca(int a[], int dim){
	int j=0, i=j+1, k=dim, conta=0, trovato=0, ifin=0;
	while(i<dim && trovato==0){
		if(a[i]<a[j]){
			i++;
			j++;
		}
		else if(a[i]>=a[j]){
			ifin=i-1;
			trovato=1;
		}
	}
	if(trovato==0)
		return 0;
	else if(trovato==1){
		while(a[ifin]<k){
			if(a[ifin]<a[k-1]){
				conta++;
				k--;
			}
			else if(a[ifin]>=a[k-1])
				k--;
		}
		if(conta==1)
			return 1;
		else 
			return 0;
	}
}	*/
int cerca(int a[], int dima){	//soluzione proposta dal prof
	int true=1, false=0;	//se non le dichiaro cosi' crede che non siano mai dichiarate poi 
	int i=0, trovato=0, j=0, tuttimaggiori=true, k=i+1, conta=0;	
	while(i<dima && trovato==0){
		while(j<i && tuttimaggiori){
			if(a[j]>a[i])
				j++;
			else
				tuttimaggiori=false;
		}
		if(tuttimaggiori){	//if(tuttimaggiori=true)
			while(k<dima && conta<2){
				if(a[k]>a[i])
					conta++;
				k++;
			}
			if(conta==1)
				trovato=1;
		}
		i++;	
	}
	return trovato;
}
int main(){
	int *a=(int *)malloc(100*sizeof(int)), i=0,dim=0;
	scanf("%d",&a[i]);
	while(a[i]!=-1){
		i++;
		scanf("%d",&a[i]);
		dim++;	
	}
	for(i=0; i<dim; i++)
		printf("%d\n",a[i]);
	printf("%d\n",cerca(a,dim));
	return 0;
}
