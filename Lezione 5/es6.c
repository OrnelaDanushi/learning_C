/*CALCOLO PI GRECO: Il numero PiGreco puo' essere calcolato in modo approssimato tramite la serie Gregory Leibniz che utilizza la seguente relazione: PiGreco=4/1 -4/3 +4/5 -4/7 +4/9 -... Scrivere un programma che acquisisca da tastiera un intero non negativo n e restituisca l'approssimazione di PiGreco usando la serie di Gregory Leibniz con n termini, implementata tramite una funzione approx_pi. Il risultato deve essere stampato con esattamente 6 cifre decimali.
Input:1	Output:	4.000000	Input:10 Output: 3.041840	Input:100 Output: 3.131593	*/

#include<stdio.h>

float GregoryL(int n){
	int i, j;
	float ris=0;
	for(i=0; i<n; i++){
		j=i+1;
		if(i%2==0)
			ris=ris+(float)4/(i+j);
		else if(i%2!=0)
			ris=ris-(float)4/(i+j);
	}
	return ris;
}

int main(){
	int n;
	scanf("%d", &n);
	if(n>0){
		printf("%.6f\n", GregoryL(n));
	}
	return 0;
}
