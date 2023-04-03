/*Scrivere un programma che legga da tastiera un numero N e stampi l'N-esimo numero di Fibonacci 
calcolato con la formula di Binet. Secondo questa formula, l'N-esimo numero di Fibonacci puo' 
essere espresso come: F(N)=(fi^N -(-fi)^-N)/(5)^(1/2) con fi=(1+5^(1/2))/2. N.B. Arrotondare all'intero piu' vicino.
input:	10	output:	55	*/

#include<stdio.h>
#include<math.h>
void binet(int v){
	double fi=(1+sqrt(5))/2;
	double ris=(pow(fi,v)-pow(fi*-1,v*-1))/(sqrt(5));
	printf("%.0f\n",ris);
}
/*
void fib(int valore){		//senza binet
	int risultato;
	if(valore==0)
		risultato=0;
	if(valore==1)
		risultato=1;
	else{
		int indice=1;
		int prec=0;
		int corr=1;
		while(indice<valore){
			int t=prec+corr;
			prec=corr;
			corr=t;
			indice++;
		}
		risultato=corr;
	}
	printf("%d\n",risultato);
}*/
int main(){
	int n;
	scanf("%d",&n);
	binet(n);
	return 0;
}
