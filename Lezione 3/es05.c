/*PARI:
Scrivere un programma che legga da tastiera un numero e stabilisca se pari o meno, 
stampando in uscita rispettivamente 1 o 0.
Input:	15	Output: 0		
Input:	4	Output: 1 	*/

#include <stdio.h>
int main(){
	int x;
	scanf("%d",&x);
	if(x%2==0) 		x=1;
	else x=0;	
	printf("%d\n",x);

	/*oppure
	if(x%2==0)	printf("1\n");
	else		printf("0\n");
	*/
	
	return 0;
}
