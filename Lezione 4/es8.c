/*TABELLINE: Scrivere un programma che, preso in ingresso un numero intero x, stampi (con un numero per riga) la tabellina di x (partendo da x*1 e terminando con x*10)
Input:	2		Output:	2	4	6	8	10	12	14	16	18	20	*/

#include<stdio.h>
int main(){
	int x, i;
	scanf("%d", &x);
	for(i=1; i<11; i++)
		printf("%d\n", x*i);
	return 0;
}
