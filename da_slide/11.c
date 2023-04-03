//Il programma stampa su schermo il numero digitato sommato con il numero di Nepero, 
// inoltre quando si compila con gcc si deve usare: nome.c -o nome.o -lm perché in uso la funzione di libreria math.h
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	float somma=0;
	somma=n+M_E; //sommo con il numero di nepero
	printf("Il risultato e':%f\n",somma);
	return 0;
}
