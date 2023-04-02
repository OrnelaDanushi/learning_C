/*OUTER PRODUCT: 
Si legga dall'input una sequenza di numeri (0 o 1) terminata dal numero -1. 
Si inseriscano tali numeri in un array di interi nell'ordine in cui vengono letti. 
L'ultimo numero letto (-1) non va inserito nell'array in quanto rappresenta unicamente un terminatore 
di sequenza. Si scriva una funzione prodotto_scalare che, dato in input l'array v, 
contenente gli N interi precedentemente letti, restituisca in output la matrice A di N*N interi, 
tale che l'elemento A[i][j] della matrice sia pari a v[i]*v[j]. 
Tale matrice e' il risultato del prodotto esterno tra il vettore v e il proprio trasposto. 
Nel main del programma si stampi il contenuto della matrice A, 
assicurandosi che tutti gli elementi di ciascuna riga della matrice siano stampati su un unica riga 
e separati da un singolo spazio; righe diverse della matrice vanno separate con un "a capo".
Input:	0		Output:	0 0 0 0
	1			0 1 1 1
	1			0 1 1 1
	1			0 1 1 1
	-1	*/

#include<stdio.h>
#include<stdlib.h>
#define VALORE 100

int **prodottoScalare(int *v, int n){
	int i, j, ** mat=(int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++){
		mat[i]=(int *)malloc(n*sizeof(int));
		for(j=0; j<n; j++)
			mat[i][j]=v[i]*v[j];
	}
	return mat;
}
int main(){
	int *v=(int *)malloc(VALORE*sizeof(int)), len=0, n, **mat, i, j, *extv;
	if(v!=NULL){
		do{
			scanf("%d",&n);
			if(n!=-1){
				v[len]=n;
				len++;
				extv=(int *)realloc(v,(len+1)*sizeof(int));	
				/*realloc si usa quando mi accorgo che l'array e' troppo piccolo 
				e voglio ingrandirlo dinamicamente senza perdere le informazioni 
				precedentemente memorizzate. v e' un puntatore ad un'area di memoria p
				recedentemente allocata segue poi dopo la virgola la nuova dimensione 
				dell'area di memoria*/
				v=extv;
			}
		}while(n!=-1);
		mat=prodottoScalare(v, len);
		for(i=0; i<len; i++){
			for(j=0; j<len; j++)
				printf("%d ",mat[i][j]);
			printf("\n");
		}
		free(v);
		free(mat);
	}
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>
int main(){
	int dim=1, *v=(int *)malloc(dim*sizeof(int)), n, i=0, j;
	scanf("%d", &n);
	while(n!=-1){
		v[i]=n;
		i++;
		dim++;
		v=realloc(v, dim*sizeof(int));
		scanf("%d", &n);
	}
	dim--;
//	for(i=0; i<dim; i++)	printf("%d\n", v[i]);
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			printf("%d ",v[i]*v[j]);
		}
		printf("\n");
	}
	return 0;
}	*/
