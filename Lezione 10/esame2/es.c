#include <stdio.h>
#include <stdlib.h>

//Functions to be implemented:
float *readArray(int *len);
float **computeMatrixZero(float a1[], float a2[], int len1, int len2);
float **transposeMatrix(float **A, int nrow, int ncol);

int prova(float num); //funzione creata per sapere se il numero non è dell'insieme dei naturali

int main() {
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
	for(i=0; i<len1; i++) {
		float *row=A[i];
		for(j=0; j<len2-1; j++)	printf("%.1f ", row[j]);
		printf("%.1f\n", row[len2-1]);
	}

	//Deletes element out of order in the list
	A1=transposeMatrix(A, len1, len2);

	//Print the cleaned list:
	printf("Transposed Matrix:\n");
	for(i=0; i<len2; i++) {
		float *row=A1[i];
		for(j=0; j<len1-1; j++)	printf("%.1f ", row[j]);
		printf("%.1f\n", row[len1-1]);
	}
	return 0;
}

float *readArray(int *len){
      float num, *A=NULL;
      int i=0, real=0;
      scanf("%f", &num);
      while(prova(num)){
            real++;  
            A=(float *)realloc(A,real*sizeof(float));
            A[i]=num;
            i++;
            scanf("%f",&num);            
      }
      *len=i;
      return A;
}

int prova(float num){
      int x=num, verita;       //per capire se il numero ha numeri a destra della virgola
                              //"casto" il numero a int e lo uguaglio a il numero float 
      if(x == num) verita=1;  //se sono uguali allora non ha numeri dopo la virgola
      else verita=0;          //devo uscire dal ciclo
 
      return verita;          
}

float **computeMatrixZero(float a1[], float a2[], int len1, int len2){
      if(a1==NULL || a2==NULL) return NULL; //utilizzo if per vedere l'esistenza degli array.
            
      float **A,max;
      int i,j,trovato=0;
      
      A=malloc(len1*sizeof(float*));          //assegnamento memoria per la matrice A
      for(i=0;i<len1;i++)
            A[i]=malloc(len2*sizeof(float));  //fine assegnamento
      
      for(i=0;i<len1;i++)                    //outer product e assegnamento nella matrice
            for(j=0;j<len2;j++)
                  A[i][j] = a1[i] * a2[j];
      
      max=A[0][0];                         //imposto il massimo con il primo elemento della matrice
      
      for(i=0;i<len1;i++)                      //ciclo per ricerca del massimo
            for(j=0;j<len2;j++)
                if(A[i][j] > max) max=A[i][j];               
  
      i=0;                                     //ciclo con il while,appena trovo il max esco 
      while(i<len1 && trovato != 1){           //perche' si vuole trovare il massimo con meno 
            j=0;                               //colonne e righe.
            while(j<len2 && trovato != 1 ){
                if(A[i][j] == max){
                       A[i][j]=0;   
                       trovato=1;            
                }
                j++;
            }
            i++;
      }

      return A;   //ritorno la matrice
}

float **transposeMatrix(float **A, int nrow, int ncol){
      if(A==NULL) return NULL;      //se la matrice di partenza non esiste esco dal ciclo
      
      float **T;   
      int i,j;
      
      T=malloc(ncol*sizeof(float*));         //alloco la memoria nella matrice trasposta
      for(i=0;i<ncol;i++)                    //faecendo attenzione perchè le righe e le colonne
            T[i]=malloc(nrow*sizeof(float)); //sono invertite rispetto a quella orginale
             
      for(i=0;i<ncol;i++)                  //operazione della trasposta          
          for(j=0;j<nrow;j++)
              T[i][j]=A[j][i];               //cambiare le righe con le colonne
      
      return T;
}
