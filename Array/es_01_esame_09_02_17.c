/* Scrivere una funzione che, dato un array a di dimensione dim, restituisce il seguente valore di verita': 
Per ogni i appartenente a [2,dim).a[i]=(sommatoria j:j appartiene a [1,i-1].a[j])+(sommatoria k:k appartiene a [0,i-2].a[k])	*/

#include<stdio.h>

int check(int a[], int dim){
	if(dim<3)	return 0;
	if(dim==3){
		if(a[0]+a[1]==a[2])	return 1;
		else return 0;
	}else if(dim>3){
		int i=2, contak=a[0], contaj=a[1], trovato=0;
		while(i<dim && trovato==0){
			if(a[i]==contak+contaj){
				i++;
				contak=contak+a[i-2];
				contaj=contaj+a[i-1];
			}
			else trovato=1;
		}		
		return !trovato;
	}
}
int main(){
	int a[6], i;
	for(i=0; i<6; i++)	scanf("%d", &a[i]);
	printf("%d\n", check(a, 6));
	return 0;
}
