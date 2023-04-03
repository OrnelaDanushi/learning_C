/*Questo programma legge i numeri interi positivi da tastiera finche' non ne trova uno negativo. A
priori e' impossibile sapere quanti valori saranno letti, ma sappiamo che ne va letto almeno uno, quindi si usa do-while.*/
#include<stdio.h>
int main(){
	int n;
	do{
		scanf("%d",&n);
	}while(n>=0);
	return 0;
}
