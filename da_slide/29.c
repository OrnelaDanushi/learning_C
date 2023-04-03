#include<stdio.h>
int main(){
	int n;
	for(n=1; n>-50 && n<150; n*=-2)
		printf("%d\n",n);
	return 0;
}
