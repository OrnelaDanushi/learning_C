//elevamento a potenza
#include<stdio.h>
int power(int n, int m){
	if(n==0)
		return 1; //qualsiasi elemento elevato alla 0 restituisce 1
	else
		return m*power(n-1,m);
}
int main(){
	int x, y;
	scanf("%d %d",&x,&y);
	printf("%d\n",power(y,x)); //stampa x^y
	return 0;
}
