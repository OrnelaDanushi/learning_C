/*SEQUENZA INVERTITA: Scrivere un programma che legga da tastiera una sequenza di 10 interi, e stampi la stessa sequenza con ordine invertito, dividendo per 2 gli elementi pari della sequenza.
input	5	4	-2	45	7	9	18	-18	5	5	
output	5	5	-9	9	9	7	45	-1	2	5	*/
#include<stdio.h>
int main(){
	int a[10],n,i;
	for(i=0; i<10; i++){
		scanf("%d",&n);
		a[i]=n;
	}
//	for(i=0; i<10; i++)
//		scanf("%d", &a[i]);
	for(i=9; i>=0; i--){
		if(a[i]%2==0)
			printf("%d\n",(a[i]/2));
		else
			printf("%d\n",a[i]);
	}
	return 0;
}
