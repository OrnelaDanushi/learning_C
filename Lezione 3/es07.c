/*SECONDI: 
Scrivere un programma che legga da tastiera un numero che rappresenta 
un numero di secondi, e stampi le ore, i minuti e i secondi compresi.
Input: 5	Output: 0 h 0 min 5 s
Input: 138	Output: 0 h 2 min 18 s
Input: 3685	Output: 1 h 1 min 20 s	*/

#include<stdio.h>
int main(){
	int secondi, ore=0, minuti=0;
	scanf("%d", &secondi);
	while(secondi>=60){
		if(secondi>=3600){
			ore++;
			secondi=secondi-3600;
		}else if(secondi<3600 && secondi>=60){
			minuti++;
			secondi=secondi-60;
		}
	}
	printf("%d h %d min %d s\n", ore, minuti, secondi);
	return 0;
}
