/*Dato lo scheletro di codice qui riportato, lo si completi aggiungendo l'implementazione delle funzioni richieste.
#include<stdio.h>
#include<stdlib.h>
int *leggiInput(int *dim);	//funzioni da implementare
int *eliminaNeg(int *vect, int dim, int *newdim);
float *mediaEstremi(int *vect, int dim);
int main(){
	int *input, *noneg, dim, dimnoneg, i;
	float *results;
	input=leggiInput(&dim);	//legge l'input
	printf("Stampa dei valori in input: (%d valori)\n",dim);
	for(i=0; i<dim; i++)	printf("%d\n", input[i]);
	noneg=eliminaNeg(input, dim, &dimnoneg);	//elimina i negativi
	printf("Stampa dei valori senza negativi: (%d valori)\n", dimnoneg);
	for(i=0; i<dimnoneg; i++)	printf("%d\n",noneg[i]);
	results=mediaEstremi(noneg,dimnoneg);	//esegue media degli estremi
	dim=dimnoneg%2==0? dimnoneg/2: dimnoneg/2+1;	//calcolo dimensione dell'array results
	printf("Risultato di mediaEstremi:\n");
	for(i=0; i<dim; i++)	printf("%3.2f\n,results[i]");
	return 0;
}
Le funzioni devono implementare le seguenti operazioni:
-leggiInput: legge una sequenza di interi (positivi e negativi) terminata da uno 0 e li inserisce in un array nell'ordine in cui vengono letti. Lo 0 comparira' solo come terminatore della sequenza e non dovra' essere inserito nell'array. Si puo' assumere che la sequenza possa prevedere al massimo 20 elementi, escluso lo 0. La funzione restituisce l'array e scrive, nell'indirizzo puntato da dim, la dimensione dell'arrau letto (ovvero il numero di elementi letti da tastiera diversi da 0);
-eliminaNeg: la funzione accetta come parametri un array di interi vect, la sua dimensione dim, e un puntatore ad interi new_dim. La funzione modifica l'array vect sostituendo ogni occorrenza di un numero negativo con il suo valore assoluto ed aggiungendo in fondo all'array un elemento contenente, come il precedente, il valore assoluto del numero negativo. Supponendo che il primo numero negativo si trovi in posizione i nell'array vect, ne consegue che il valore di vect[i] verra' trasformato in positivo, mentre verra' aggiunto un ulteriore elemento abs(vect[i])in coda all'array. L'inserimento degli elementi in coda all'array deve avvenire rispettando l'ordine dei corrispondenti numeri negativi nel vettore vect iniziale. Ad esempio, dato l'array {4, -1, 2, -3}, questo verra' trasformato nell'array {4, 1, 2, 3, 1, 3}. La funzione restituisce il nuovo array dopo il ridimensionamento e scrive, nell'indirizzo puntato da new_dim, la dimensione del nuovo array.
-mediaEstremi: la funzione accetta come parametri un array di interi vect e la sua dimensione dim. Restituisce un array di float, il cui elemento i-esimo contiene la media tra gli elementi di vect in posizione i a partire dall'inizio e dalla fine dell'array. Ad esempio, in posizione i a partire dall'inizio e dalla fine dell'array. Ad esempio, in posizione 0 sara' contenuta la media tra il primo e l'ultimo elemento di vect, in posizione 1 tra il secondo e il penultimo, in posizione 2 tra il terzo e il terz'ultimo, etc. In caso l'array vect sia di dimensione dispari, ricopiare l'elemento centrale come ultimo valore dell'array delle medie.
input:	2	-1	4	7	-8	1	3	0	
output:	Stampa dei valori in input: (7 valori)	2	-1	4	7	-8	1	3	Stampa dei valori senza negativi: (9 valori)	2	1	4	7	8	1	3	1	8	Risultato di mediaEstremi:	5.00	1.00	3.50	4.00	8.00	*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *leggiInput(int *dim){
	int *a=malloc(20*sizeof(int)), i=0, dim2=0, n;
	scanf("%d", &n);
	while(n!=0){
		a[i]=n;
		i++;
		scanf("%d",&n);
		dim2++;
	}
	*dim=dim2;
	return a;

/*	//oppure
	*dim=0;
	int n, *a=(int *)malloc((*dim)*sizeof(int)), i=0;
	scanf("%d", &n);
	while(n!=0){
		(*dim)++;
		a=realloc(a,(*dim)*sizeof(int));
		a[i]=n;
		scanf("%d", &n);
		i++;
	}
	return a;
*/

}
int *eliminaNeg(int *vect, int dim, int *newdim){
	int i=0, valore=0;
	for(i=0; i<dim; i++){
		if(vect[i]<0){
			dim++;
			vect=realloc(vect,(dim)*sizeof(int));
			vect[i]=abs(vect[i]);
			vect[dim-1]=abs(vect[i]);				
		}
	}
	*newdim=dim;
	return vect;

/*	//oppure
	(*newdim)=dim;
	int i;
	for(i=0; i<(*newdim); i++){
		if(vect[i]<0){
			vect[i]=vect[i]*(-1);
			(*newdim)++;
			vect=realloc(vect, (*newdim)*sizeof(int));
			vect[(*newdim)-1]=vect[i];
		}
	}return vect;
*/

}
float *mediaEstremi(int *vect, int dim){
 	float *c=realloc(vect,dim*sizeof(float));
  	int i=0, j=dim-1, n=0;
  	while(n<dim){
    		float a=vect[i], b=vect[j], media=(a+b)/2; //se eseguo solo media=(vect[i]+vect[j])/2 restituisce solo interi come risultati.
    		c[n]=media;
    		n++;
    		j--;
   		if(j==i)
      			break;
    		i++;
    		if(j==i){
     			c[n]=vect[j];
     			 break;
		}
  	}
  	return c;
/*	//oppure
	int newdim=0, i=0, j=0, k=0;
	if(dim%2==0)	newdim=dim/2;
	else if(dim%2!=0)	newdim=(dim/2)+1;
	float *v=(float *)malloc(newdim*sizeof(float));
	j=dim-1;
	while(i<=j){
		v[i]=(float)(vect[i]+vect[j])/2;
		i++;
		j--;
	}
	return v;
*/

}

int main(){
	int *input, *noneg, dim, dimnoneg, i;
	float *results;

	//Legge l’input
	input=leggiInput(&dim);
	printf("Stampa dei valori in input: (%d valori)\n", dim);
	for(i=0; i<dim; i++)	printf("%d\n", input[i]);

	//Elimina i negativi
	noneg=eliminaNeg(input, dim, &dimnoneg);
	printf("Stampa dei valori senza negativi: (%d valori)\n", dimnoneg);
	for(i=0; i<dimnoneg; i++)	printf("%d\n", noneg[i]);

	//Esegue media degli estremi
	results=mediaEstremi(noneg, dimnoneg);
	//Calcolo dimensione dell’array results
	dim=dimnoneg%2==0?dimnoneg/2:dimnoneg/2+1;
	printf("Risultato di mediaEstremi:\n");
	for(i=0; i<dim; i++)	printf("%3.2f\n", results[i]);	
	return  0;
}
