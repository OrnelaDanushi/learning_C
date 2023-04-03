#include<stdio.h>
int main(){
	printf("Immettere un anno: ");
	int n;
	scanf("%d",&n);
	if(n%400==0 ||(n%100!=0 && n%4==0)){
		printf("Bisestile si!\n");
	}
	else 
		printf("No bisestile!\n");
	return 0;
}
