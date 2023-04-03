//il programma stampa i numeri pari fino a 10
#include<stdio.h> 
int main(){
	int i;
	for(i=0; i<=10; i++){
		if(i%2==0)
			printf("%d\n",i);
	}
	return 0;
}
