/*CALCOLATORE: Scrivere un programma che legga da tastiera due numeri a e b (anche con virgola) e un operatore tra + - / % e stampi il risultato ottenuto applicando l'operatore ai due numeri inseriti. Per l'operazione % gli operandi sono |a| e |b|.
Input:	5	7	+		Output:	12.0
Input:	5	7	-		Output:	-2.0
Input:	6.2	2	/		Output:	3.1	*/

#include<stdio.h>
#include<math.h>

int main(){
	float a, b;
	char x; //l'operatore lo dichiaro come carattere
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%s", &x);	//qui devo usare l'identificatore per una stringa anche se e' un carattere
	//in base al loro codice decimale della tabella ASCII faccio le rispettive operazioni
	if(x==43)
		printf("%.1f\n", a+b);
	if(x==45)
		printf("%.1f\n", a-b);
	if(x==42)
		printf("%.1f\n", a*b);
	if(x==47)
		printf("%.1f\n", a/b);
	if(x==37)
		printf("%d.0\n", (int)a%(int)b);
	return 0;
}
