/*FUNZIONE SWAP ORDINATO: 
Si realizzi un programma che legga 3 interi da standard input ed applichi 
la funzione a 3 argomenti ordered_swap(-,-,-) alle 3 variabili in cui sono stati memorizzati i 3 valori. 
I valori letti devono essere passati alla funzione nell'ordine in cui vengono acquisiti da tastiera. 
Si implementi la funzione ordered_swap, che scambia il contenuto delle 3 variabili di input in modo che 
la variabile corrispondente al primo argomento contenga l'intero minore, 
la seconda variabile contenga l'intero mediano e la terza contenga l'intero di valore maggiore. 
Si stampi a video il contenuto delle 3 variabili all'uscita dall'esecuzione della funzione.
Input:	14	-1	7	Output:	-1	7	14	*/

#include<stdio.h>
int ordered1(int x, int y, int z){
	int min=x;
	if(y<x)		min=y;
	else if(z<min)	min=z;
	return min;
}
int ordered2(int x, int y, int z){
	int max=z;
	if(y>z)		max=y;
	else if(x>max)	max=x;
	return max;
}
int ordered(int x, int y, int z){
	int minimum=ordered1(x,y,z);
	int maximum=ordered2(x,y,z);	
	if(x!=minimum && x!=maximum)		return x;
	else if(y!=minimum && y!=maximum)	return y;
	else if(z!=minimum && z!=maximum)	return z;
}
int main(){
	int a, b, c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	printf("%d\n",ordered1(a,b,c));
	printf("%d\n",ordered(a,b,c));
	printf("%d\n",ordered2(a,b,c));
	return 0;
}
