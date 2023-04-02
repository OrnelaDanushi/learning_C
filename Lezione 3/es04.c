/*MAX:
Scrivere un programma che legga da tastiera tre numeri interi e ne stampi il massimo.
Input:	15	7	12	Output:	15*/

#include<stdio.h>
int main(){
	int x, y, z, max=0;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);

	if(x>max)		max=x;
	if(y>max)		max=y;
	if(z>max)		max=z;

	/*oppure
	int max=0, max1=0;
	if(x<y)		max1=y;
	else 		max1=x;
	if(max1<z)	max=z;
	else 		max=max1;
	*/
	
	/*oppure
	if (x>=y && x>=z) max=x;
	if (y>=x && y>=z) max=y;
	if (z>=x && z>=y) max=z;
	
	*/

	printf("%d\n",max);	
	return 0;
}
