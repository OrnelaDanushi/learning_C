/*FATTORIALE: 
Scrivere un programma che legga da tastiera un numero intero x e stampi il valore di x! 
dove con x! si intende x fattoriale, ovvero x*(x-1)*(x-2)...*1.
Input:	5	Output:	120	*/

#include<stdio.h>
int fact(int x){
	if(x==0 || x==1)	return 1;
	return x*(fact(x-1));
}

int main(){
	int x;
	scanf("%d",&x);	
	printf("%d\n",fact(x));
	return 0;
}

/*oppure
int main(){
	int x, fact=1, y;
	scanf("%d",&x);	
	if(x!=0 && x>=0); 
	y=x*(x-1);
	fact=x*y*(x-1);
	printf("%d\n",fact);
	return 0;
}
*/
