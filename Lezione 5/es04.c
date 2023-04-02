/*MCD & MCM: 
Si realizzi un programma che acquisisca da tastiera 2 numeri interi N ed M 
e utilizzi 2 funzioni per calcolare il minimo comune multiplo 
e il massimo comune divisore tra N ed M. Il programma stampa sullo standard output 
prima il mcd(n,m) e poi il mcm(n,m).
input:	2	5	output:	1	10	*/

#include<stdio.h>
int mcd(int x, int y){
	if(x==y)	return x;
	if(x<y)		return mcd(x,y-x);
	else		return mcd(x-y,y);
}
int mcm(int x, int y){
	int prodotto=x*y;
	return prodotto/mcd(x,y);	
}
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	printf("%d\n",mcd(n,m));
	printf("%d\n",mcm(n,m));
	return 0;
}
/* oppure
int mcd(int n, int m){
	while(n!=m){
		if(n>m) n=n-m;
		if(n<m)	m=m-n;
	}	
	return n;
}
void mcm(int n, int m){
	printf("%d\n",(n*m)/mcd(n,m));	
}
int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	mcd(n,m);	
	printf("%d\n",mcd(n,m));
	mcm(n,m);
	return 0;
}	*/
