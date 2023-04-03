/*ELEMENTO MAGGIORITARIO: Un array A contiene n interi, uno di essi e' detto elemento maggioritario se occorre in A almeno (n/2+ 1) volte. 
Si vuole un algoritmo che identifichi l’elemento maggioritario, se presente, in tempo O(n) utilizzando O(1) spazio aggiuntivo. 
L’algoritmo deve stampare N se non e' presente alcun elemento maggioritario.
-Caso particolare: si assuma che tutti gli elementi, ad esclusione eventualmente del maggioritario, occorrano una sola volta in A.
-Caso generale: gli elementi possono avere un numero arbitrario di occorrenze.
Input	5		1 10 22 11 2          Output	N
Input	5		22 10 22 11 22        Output	22	*/

#include<stdio.h>
#include<stdlib.h>

int *CountingSort(int a[], int dim){
	int i, max=a[0], k=0;
	for(i=0; i<dim; i++){	//ricerca del massimo
		if(a[i]>max)
			max=a[i];
	}
	k=max+1;
	int *c=(int *)calloc(k,sizeof(int));	//gli elementi di c sono cosi' tutti inizializzati a 0
	int *b=(int *)malloc((dim+1)*sizeof(int));
	for(i=0; i<dim; i++){
		c[a[i]]++;
	}
	for(i=1; i<k; i++){
		c[i]=c[i]+c[i-1];
	}
	for(i=dim-1; i>=0; i--){
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}
	for(i=0; i<dim+1; i++){
		a[i]=b[i+1];
	}
	return a;
}
void cercaelemento(int a[], int dim){
	a=CountingSort(a,dim);	
	int i=0, cx=0, contaprimo=1, contaultimo=0, trovato=0, risultato=0;
	cx=dim/2;
	i=cx;
	while(i>=0 && trovato==0){
		if(a[i]!=a[i-1])
			trovato=1;
		else if(a[i]==a[i-1]){
			contaprimo++;			
			i--;
		}	
	}
	i=cx;
	trovato=0;
	while(i<dim && trovato==0){
		if(a[i]!=a[i+1])
			trovato=1;
		else if(a[i]==a[i+1]){
			contaultimo++;			
			i++;
		}
	}
	risultato=contaprimo+contaultimo;
	if(risultato==cx+1)
		printf("%d\n", a[cx]);
	else if(risultato!=cx+1)
		printf("N \n");
}
int main(){
	int n, i;
	scanf("%d", &n);
	int *a=malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	cercaelemento(a,n);
	return 0;
}
