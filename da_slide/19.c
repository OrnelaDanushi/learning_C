/* Viene dato un array di dimensione n contenente non ordinati tutti gli interi compresi tra 1 e n+1 
ad eccezione di uno di essi e si vuole stabilire l'elemento mancante. Sono possibili almeno 4 soluzioni aventi le seguenti complessita':
-in tempo O(n^2) in spazio O(1)
-in tempo O(nlog(n)) in spazio O(n)
-in tempo O(n) in sapzio O(n)
-in tempo O(n) in spazio O(1)	NON RISOLTO
Input: un array di interi il cui primo elemento denota la dimensione	es: 8 3 4 9 2 7 1 8 6
Output: l'elemento mancante	es: 5	*/

#include<stdio.h>
#include<stdlib.h>

//soluzione 1
//essendo tempo quadratico questo permette l'ordinamento con l'Insertion Sort, oppure con Selection Sort, 
// non possiamo qui usare il Counting Sort che seppur sia lineare in tempo, ha pero' costo in spazio non costante
int *InsertionSort(int a[], int dim){
	int i=0, j=0, k=0;
	for(j=1; j<dim; j++){
		k=a[j];
		i=j-1;
		while(i>=0 && a[i]>k){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=k;
	}
	return a;
}
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int *SelectionSort(int a[], int dim){
	int i=0, j=0, minimo=0;
	for(i=0; i<dim-1; i++){
		minimo=i;	//all'INIZIO il minimo e' la posizione del PRIMO elemento, questo per effettuare lo swap
		for(j=i+1; j<dim; j++){
			if(a[j]<a[minimo])
				minimo=j;
		}
		swap(&a[i], &a[minimo]);
	}
	return a;
}
//soluzione 2 
//uso il MergeSort perche' ha i costi su detti
void Merge(int a[], int sx, int cx, int dx){
	int i=sx, j=cx+1, k=0, b[999];
	while(i<=cx && j<=dx){
		if(a[i]<=a[j]){ 
			b[k]=a[i];
			i++; 
		}else{ 
			b[k]=a[j];
			j++;
		}
         	k++;
      	}
   	while(i<=cx){
      		b[k]=a[i]; 
      		i++; 
      		k++;
   	}
   	while(j<=dx){
      		b[k]=a[j]; 
      		j++;
      		k++;
   	}
      	for(k=sx; k<=dx; k++)
         	a[k]=b[k-sx];
}
int *MergeSort(int a[], int sx, int dx){
	int cx=0;
	if(sx<dx){
		cx=(sx+dx)/2;
		MergeSort(a, sx, cx);
		MergeSort(a, cx+1, dx);
		Merge(a, sx, cx, dx);
	}
	return a;
}
//soluzione 3 
//uso CountingSort
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
		//printf("%d ",a[i]);
	}
	//for(i=0; i<dim; i++){
		//printf("%d ",a[i]);
	//}
	return a;
}
void cercaelemento(int a[], int dim){
	//a=InsertionSort(a,dim);
	//a=SelectionSort(a,dim);
	//a=MergeSort(a,0,dim-1);	
	a=CountingSort(a,dim);	
	int i=0, trovato=0, risultato=0;
	//for(i=0; i<dim; i++)
	//	printf("%d ",a[i]);
	//i=0;
	while(i<dim && trovato==0){
		if(a[i]!=i+1){
			risultato=i+1;
			trovato=1;
		}
		else if(a[i]==i+1)
			i++;
	}
	if(trovato==0)
		risultato=dim+1;
	else if(trovato==1)
		risultato=i+1;
	printf("%d\n", risultato);
}
int main(){
	int n, i;
	scanf("%d", &n);
	int *a=malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	cercaelemento(a,n);
	free(a);
	return 0;
}

