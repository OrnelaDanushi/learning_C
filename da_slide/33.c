/*Questo programma legge interi da terminale finche' la somma non supera 100, quindi stampa la somma. 
A priori e' impossibile sapere quanti numeri saranno letti, quindi si usa while*/
#include<stdio.h>
int main(){
	int somma=0, n;
	while(somma<100){
		scanf("%d",&n);
		somma=somma+n;
	}
	printf("%d\n",somma);
	return 0;		
}
