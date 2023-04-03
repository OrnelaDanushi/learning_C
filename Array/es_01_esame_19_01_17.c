/* Si scriva una funzione c che, dato un array a di dimensione dim e un numero naturale n tale che 1<=n<=dim, 
restituisce il seguente valore di verita': per ogni j appartenente a [n,dim) vale che a[j]=sommatoria di a[i] per i che va da (j-n) a j. 
Il testo chiede in sostanza di scrivere una procedura che verifica se ogni elemento dell'array a dall'indice n in poi ha un valore pari alla somma 
degli n elementi precedenti.
Input: 7//dim 1 2 3 6 11 20 37 3//n	Output:1	*/

#include<stdio.h>
#include<stdlib.h>

/* //seguendo la struttura della formula logica, una prima soluzione corretta prevede l'uso di 2 cicli annidati
int somma(int a[], int dim, int n){
	int i, j=n, somma, trovato=0;
	while(j<dim && trovato==0){
		somma=0;
		for(i=j-n; i<j; i++)	somma+=a[i];
		if(somma==a[j])	j++;
		else trovato=1;
	}
//	if(trovato==1)	return 0;
//	else return 1;
	return !trovato;
}	*/

/* //oppure in maniera piu' modulare, mediante l'uso di una funzione ausiliaria
int somma(int a[], int init, int end){
	int somma=0, k;
	for(k=init; k<end; k++)	somma+=a[k];
	return somma;
}
int check(int a[], int dim, int n){
	if(n<1 || n>dim)	return 0;
	int i;
	for(i=n; i<dim; i++)	if(a[i]!=somma(a,i-n,i))	return 0;
	return 1;
}	*/

//oppure ancora, osservando che ad ogni iterazione del ciclo i valori da sommare sono quasi gli e stessi rispetto a quelli sommati nell'iterazione precedente, 
// una soluzione alternativa piu' efficiente e' la seguente
int check(int a[], int dim, int n){
	int i, somma=0;
	for(i=0; i<n; i++)	somma+=a[i];
	for(i=n; i<dim; i++){
		if(somma!=a[i])	return 0;
		somma=somma-a[i-n]+a[i];
	}
	return 1;
}

int main(){
	int dim, i, *a, n;
	scanf("%d", &dim);
	a=(int *)malloc(dim*sizeof(int));
	for(i=0; i<dim; i++)	scanf("%d", &a[i]);
	scanf("%d", &n);
//	printf("%d\n", somma(a,dim,n));
	printf("%d\n", check(a,dim,n));
	return 0;
}

