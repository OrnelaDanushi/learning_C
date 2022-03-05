#include<stdio.h>
#include<stdlib.h>

//Functions to be implemented:
float *readArray(int *len){
	(*len)=0;
	int i=0;
	float *a=(float *)malloc((*len)*sizeof(float)), el;
	scanf("%f", &el);
	while(((int)(el*10))%10==0){
		(*len)++;
		a=(float *)realloc(a, (*len)*sizeof(float));
		a[i]=el;
		i++;
		scanf("%f", &el);
	}return a;
}
float **computeMatrixZero(float a1[], float a2[], int len1, int len2){
	float **a=(float **)malloc(len1*sizeof(float *)), max=0;
	int i, j, trovato=0;
	for(i=0; i<len1; i++)	a[i]=(float *)malloc(len2*sizeof(float));	//FONDAMENTALE.
/*	for(i=0; i<len1; i++){	//non e' necessario
		for(j=0; j<len2; j++){
			a[i][j]=0.0;
		}
	}	*/
	for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){
			a[i][j]=a1[i]*a2[j];
		}
	}
	for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){
			if(a[i][j]>max)
				max=a[i][j];
		}
	}
	i=0, j=0;
	while(i<len1 && trovato==0){
		if(a[i][j]==max){
			a[i][j]=0;
			trovato=1;
		}else{
			j++;
			if(j==len2-1)	j=0;
			i++;
		}
	}		
	return a;
}

void swap(float *a, float *b){
	float tmp=*a;
	*a=*b;
	*b=tmp;
}

float **transposeMatrix(float **A, int nrow, int ncol){
	float **b=(float **)malloc(ncol*sizeof(float *));
	int i, j;
	for(i=0; i<ncol; i++)	b[i]=(float *)malloc(nrow*sizeof(float));	//FONDAMENTALE.

	for(i=0; i<nrow; i++){
		for(j=0; j<ncol; j++){
			b[j][i]=A[i][j];
		}
	}
	return b;
}
int main(){
	float *V1, *V2, **A, **A1;
	int len1, len2, i, j;

	//Reads and prints the two arrays:
	V1=readArray(&len1);
	printf("Array:\n");
	for(i=0; i<len1; i++)	printf("%.1f ", V1[i]);
	printf("\n");
	V2=readArray(&len2);
	printf("Array:\n");
	for(i=0; i<len2; i++)	printf("%.1f ", V2[i]);
	printf("\n");

	//Multiply the two arrays to obtain a matrix:
	A=computeMatrixZero(V1, V2, len1, len2);

	//Print the concatenated list:
	printf("Product Matrix:\n");
	for(i=0; i<len1; i++){
		float *row=A[i];
		for(j=0; j<len2-1; j++)	printf("%.1f ", row[j]);
		printf("%.1f\n", row[len2-1]);
	}

	//Deletes element out of order in the list
	A1=transposeMatrix(A, len1, len2);

	//Print the cleaned list:
	printf("Transposed Matrix:\n");
	for(i=0; i<len2; i++){
		float *row=A1[i];
		for(j=0; j<len1-1; j++)
			printf("%.1f ", row[j]);
		printf("%.1f\n", row[len1-1]);
	}	
	return 0;
}
