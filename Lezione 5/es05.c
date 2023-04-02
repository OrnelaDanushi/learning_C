/*METODO BABILONESE: 
La radice quadrata di un numero z intero non negativo puo' essere calcolata 
in modo approssimato tramite il metodo detto Babilonese che utilizza la seguente 
relazione ricorsiva: sqrt(z)=1/2 *(sqrt(z-1) + z/(sqrt(z-1))) 
se z>0 oppure 1 se z=0. 
Scrivere un programma che acquisisca da tastiera un intero non negativo 
e restituisca l'approssimazione della sua radice quadrata calcolata tramite il 
suddetto metodo implementato tramite una funzione approxsqrt. 
Il risultato deve essere stampato con esattamente 4 cifre decimali.
input:	86	output:	9.2738	*/

#include<stdio.h>
float approxsqrt(int z){
	if(z==0)		return 1;
	else if(z>0)		return (approxsqrt(z-1)+(z/approxsqrt(z-1)))/2;
}
int main(){
	int x;
	scanf("%d",&x);
	printf("%.4f\n",approxsqrt(x));
	return 0;
}
