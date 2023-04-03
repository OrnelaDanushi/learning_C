//matrice
#include<stdio.h>
#include<stdlib.h>
int main(){
	int N, M, i, j, **A;
	printf("Immettere numero colonne della matrice ");	
	scanf("%d",&N);
	A=malloc(N*sizeof(int*));
	printf("Immettere numero righe della matrice ");
	scanf("%d",&M);
	for(i=0; i<N; i++){	
		A[i]=malloc(M*sizeof(int));
		printf("Completare colonna %d dell'array \n", i+1);
		for(j=0; j<M; j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("La matrice e'\n");
	for(j=0; j<M; j++){	
		for(i=0; i<N; i++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
