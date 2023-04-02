/*MAX:
Scrivere un programma che legga da tastiera tre numeri interi e ne stampi il massimo.
Input:	15	7	12	Output:	15*/

#include<stdio.h>
int main(){
	int x, y, z, max=0;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	if(x>max)
		max=x;
	if(y>max)
		max=y;
	if(z>max)
		max=z;
	printf("%d\n",max);
	return 0;
}

/*oppure
int main(){
	int a, b, c, max=0, max1=0;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);	
	if(a<b)
		max1=b;
	else 
		max1=a;
	if(max1<c)
		max=c;
	else 
		max=max1;
	printf("%d\n", max);
	return 0;
}	*/
