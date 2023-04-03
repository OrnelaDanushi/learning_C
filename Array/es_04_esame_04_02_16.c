/* Scrivere una funzione int check(int a[], int dima, int b[], int dimb) che, dati due array di interi a, b e le loro dimensioni dima, dimb, 
restituisce il seguente valore di verita': esiste i appartenente all'intervallo [0,dima) per cui vale che 
((per ogni j appartenente a [0,dimb).a[i]!=b[j]) & #{k|k appartiene a [0,dima) & a[i]=a[k]}=1).	*/

#include<stdio.h>

int contadiversi(int a[], int init, int dim, int elem){	//funzione che verifica la presenza di un valore in un array
	int i=init, trovato=0;
	while(i<dim && trovato==0){
		if(a[i]==elem)	trovato=1;
		i++;
	}
	return trovato;
}
int check(int a[], int dima, int b[], int dimb){
	int i;
	for(i=0; i<dima; i++){
		if(contadiversi(a, i+1, dima, a[i])==0){
			if(contadiversi(b, 0, dimb, a[i])==0)	return 1;
		}
	}
	return 0;
}	
/* // oppure soluzione proposta dal prof
int check(int a[], int dima, int b[], int dimb){
	int i=0, trovato=0, contaocc=0, j=0;
	while(i<dima && trovato==0){
		if(contadiversi(b,0,dimb,a[i])==0){	//oppure if(!contadiversi(..));
			while(j<dima && contaocc<2){
				if(a[j]==a[i])	contaocc++;
				j++;
			}		
			trovato=(contaocc==1);	
		}
		i++;
	}
	return trovato;			
}	*/	
int main(){
	int a[100], b[100], dima=0, dimb=0, n=0;
	scanf("%d", &a[n]);
	while(a[n]!=0){
		n++;
		scanf("%d", &a[n]);		
	}
	dima=n;
	n=0;
	scanf("%d", &b[n]);
	while(b[n]!=0){
		n++;
		scanf("%d", &b[n]);
	}	
	dimb=n;
	for(n=0; n<dima; n++)	printf("%d ", a[n]);
	printf("\n");
	for(n=0; n<dimb; n++)	printf("%d ", b[n]);
	printf("\n");
	printf("%d\n",check(a,dima,b,dimb));
	return 0;
}
