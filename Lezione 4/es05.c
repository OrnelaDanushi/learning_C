/*SUCCESSIONE DI FIBONACCI: 
Scrivere un programma che legga da tastiera un numero intero n con n>=0 
e stampi i valori della successione di Fibonacci, uno per riga, 
fino al primo valore della successione strettamente maggiore di n (questo valore non va stampato). 
Si ricorda che la successione di Fibonacci e' definita ricorsivamente come:
f(0)=0	f(1)=1	f(i)=f(i-1)+f(i-2)
input	13
output	0	1	1	2	3	5	8	13*/

#include<stdio.h>
int main(){
	int n, fib1=0, fib2=1, fibcorr;
	scanf("%d",&n);
	do {
		printf("%d\n",fib1);
		fibcorr=fib1+fib2;
		fib1=fib2;
		fib2=fibcorr;
	} while(fib1<=n);
	return 0;	
}

/*oppure meno elegante
void fib(int x){
	int prev=1, cor=0, tcor=0;
	if(x==0 || x==1)
		printf("%d\n", x);
	else if(x>1){
		printf("0\n1\n");
		while(prev<x){
			tcor=cor+prev;
			if(tcor>x)	break;		
			printf("%d\n", tcor);
			cor=prev;
			prev=tcor;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	fib(n);
	return 0;
}	*/
