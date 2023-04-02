/*VETTORI: 
Scrivere un programma che legga da tastiera due vettori interi di dimensione 5 
(10 numeri interi in totale) e stampi prima i due vettori, poi la loro somma.
Input:	5	12	34	67	89	13	25	38	62	10
Output:	[5,12,34,67,89]	[13,25,38,62,10]	[18,37,72,129,99]
Input:	-1	1	1	-1	1	1	-1	-1	1	1
Output:	[-1,1,1,-1,1]	[1,-1,-1,1,1]	[0,0,0,0,2]	*/

#include<stdio.h>

int main(){
	int a[5], b[5], i;
	for(i=0; i<5; i++)	scanf("%d", &a[i]);
	for(i=0; i<5; i++)	scanf("%d", &b[i]);
	printf("[");
	for(i=0; i<5; i++){
		if(i==4)
			printf("%d", a[i]);
		else printf("%d,", a[i]);
	}
	printf("]\n");
	printf("[");
	for(i=0; i<5; i++){
		if(i==4)
			printf("%d", b[i]);
		else printf("%d,", b[i]);
	}
	printf("]\n");
	printf("[");
	for(i=0; i<5; i++){
		if(i==4)
			printf("%d", a[i]+b[i]);
		else printf("%d,", a[i]+b[i]);
	}
	printf("]\n");
	return 0;
}
