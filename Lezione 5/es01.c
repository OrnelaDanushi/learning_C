/*FUNZIONE MEDIA: Si realizzi un programma nel linguaggio C che, data una sequenza di 10 interi da standard input, facendo uso di una funzione di nome media, calcoli la media aritmetica (reale) di tutti i valori diversi da zero e di segno uguale all'ultimo valore della sequenza. La media deve essere stampata con esattamente due cifre decimali. Assunzione: l'ultimo elemento della sequenza e' sempre diverso da zero.
input:	-2	5	3	-1	6	-4	-9	2	12	1	
output:	4.83	*/
#include<stdio.h>
float media(int somma, int conta){
	return ((float)somma)/conta;
}
int main(){
	int a[10], i, contap=0, contan=0;
	float sommap=0, somman=0;
	for(i=0; i<10; i++)	scanf("%d",&a[i]);
	for(i=0; i<10; i++){
		if(a[i]>0 && a[i]!=0){
			sommap+=a[i];
			contap++;
		}else if(a[i]<0 && a[i]!=0){
			somman+=a[i];
			contan++;
		}
	}if(a[9]>0){
		printf("%.2f\n",media(sommap,contap));
	}else if(a[9]<0){
		printf("%.2f\n",media(somman,contan));
	}
	return 0;
}
/* oppure
float media(int a[],int dim){
	int somma=0;	//oppure int somma; somma=0;
	int quantita=0;
	float med=1;
	int i;
	if(a[dim-1]>0) 
		for(i=0; i<dim; i=i+1)
			if(a[i]>0){
				somma=somma+a[i];
				quantita=quantita+1;
			}
	if(a[dim-1]<0)
		for(i=0; i<dim; i=i+1)
			if(a[i]<0){
				somma=somma+a[i];
				quantita=quantita+1;
			}
	med=(float)somma/quantita;
	return med;
}
int main(){
	int a[10]; float med; int i;
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);
	med=media(a,10);
	printf("%.2f\n",med);
	return 0;
}	*/

/*oppure
float media(int a[], int dim){
	int i, sommap=0, somman=0, contap=0, contan=0;
	for(i=0; i<dim; i++){
		if(a[dim-1]>0 && a[i]>0){
			sommap=sommap+a[i];
			contap++;
		}else if(a[dim-1]<0 && a[i]<0){
			somman=somman+a[i];
			contan++;
		}
	}
	if(sommap!=0)
		return (float)sommap/contap;
	else if(somman!=0)
		return (float)somman/contan;

}

int main(){
	int i,a[10];
	for(i=0; i<10; i++)	scanf("%d", &a[i]);
	printf("%.2f\n",media(a, 10));
	return 0;
}	*/
