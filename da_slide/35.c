//FUNZIONE COMPARE DEL QSORT
//ordinare un array di interi in modo non decrescente con la funzione qsort
#include<stdio.h>
#include<stdlib.h>
int confrontaInt(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}
int main(){
	int values[]={10, 20, 1, 7, 24, 9}, n=6, i;
	qsort(values, n, sizeof(int), confrontaInt);
	for(i=0; i<n; i++)
		printf("%d ",values[i]);
	printf("\n");
	return 0;
}

//oppure
//ordinare un array di stringhe in ordine lessicografico
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
	char **a1=(char **)a;
	char **a2=(char **)b;	
	return strcmp(*a1, *a2);
}
int main(){
	int n, i;
	scanf("%d",&n);
	char **values=(char **)malloc(n*sizeof(char *));
	for(i=0; i<n; i++){
		values[i]=(char *)malloc(101*sizeof(char));
		scanf("%s", values[i]);
	}
	qsort(values, n, sizeof(char *), compare);
	for(i=0; i<n; i++)
		printf("%s ",values[i]);
	printf("\n");
	for(i=0; i<n; i++)
		free(values[i]);
	free(values);
	return 0;
}
