/*SOMMA DI POTENZE: 
Si realizzi un programma che legga da input un intero n ed un floating point x>0 e, 
utilizzando una funzione sumpow calcoli la somma delle potenze di x, 
da 0 ad n (ovvero, il valore s=x^0 +x^1 +x^2 +.. +x^n. 
Il valore restituito dalla funzione deve essere stampato sullo standard output. 
Il risultato deve essere stampato con esattamente due cifre decimali.
input:	5	2
output:	63.00	*/

#include<stdio.h>
float sumpow(float x,int n){
	if(n==0)	return 1;
	if(n==1)	return x;
	if(n%2==0)	return sumpow(x,n/2)*sumpow(x,n/2);
	else if(n%2!=0)	return x*sumpow(x,n/2)*sumpow(x,n/2);
}
int main(){
	int a,i;
	scanf("%d",&a);
	float b,risultato=0;
	scanf("%f",&b);
	for(i=a; i>=0; i--)
		risultato+=sumpow(b,i);	
	//oppure
	// for(i=0; i<=n; i++)
	//	ris=ris+sumpow(i,x);

	printf("%.2f\n",risultato);
	return 0;
}
/*oppure
void sum_pow(int n, float x){
	int i;
	float somma=1, potenza=1;
	for(i=1; i<=n; i++){ 
		potenza=potenza*x;
		somma=somma+potenza;
	}
	printf("%.2f\n",somma);
}
int main(){
	int n; float x;
	scanf("%d",&n);
	scanf("%f",&x);
	sum_pow(n,x);
	return 0;
}	*/
