//Il Crivello di Erastotene trova tutti i numeri primi in un intervallo da 0 fino a un massimo
#include<stdio.h>
#define MAXVALORE 101
int main(){
	int tabella[MAXVALORE],i,j; //devo usare due indici
	for(i=2; i<MAXVALORE; i++)
		tabella[i]=1;	//assegno 1 a tutti i valori da 2 in poi
	for(i=2; i<MAXVALORE; i++){		
		if(tabella[i]==1){
			printf("%d\n",i); //cosi li stampo uno sotto l'altro 
			for(j=2; i*j<MAXVALORE; j++) //se il secondo indice e' multiplo del primo ritorna 0
				tabella[i*j]=0;	
		}
	}
	printf("\n"); 	
	return 1; //cosi mi restituisce solo i numeri che non sono multipli di una altro numero
}

//oppure 
/*Questo programma stampa 0 se n e' primo altrimenti 1, (esiste un numero i appartenente a [2,n/1] tale che n e' divisibile per i).
A priori e' impossibile sapere quanti valori di i saranno testati quindi si usa while*/
#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	i=2;
	while(n%2 && i<n){
		i++;
	}
	printf("%d\n",i<n);
	return 0;
}
//oppure
/*Questo programma legge 10 interi e per ognuno stampa 0 se n e' primo altrimenti 1.*/
#include<stdio.h> 
int main(){
	int n,i,j;
	for(j=0; j<10; j++){
		scanf("%d",&n);
		i=2;
		while(n%i && i<n){
			i++;
		}
		printf("%d\n",i<n);
	}
	return 0;
}
