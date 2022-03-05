/*AVERAGE: Scrivere un programma che legga da tastiera tre numeri (anche con la virgola) e stampi in uscita la media, riportandola con tre cifre decimali.
Input:	1	2	3		Output:	2.000
Input:	10.5	23.46	31.24		Output:	21.733	*/
#include<stdio.h>
int main(){
	float x, y, z, media;
	scanf("%f",&x);
	scanf("%f",&y);
	scanf("%f",&z);
	media=(float)(x+y+z)/3;
	printf("%.3f\n",media); /*oppure printf("%1.3f\n",media);*/
	return 0;
}

