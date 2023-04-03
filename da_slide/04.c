//stampa i numeri da 0 a 4 tabulati per 5 volte
#include <stdio.h>
int main(){
	int x,y,table[5][5];
	for(x=0; x<5; x++){ 
		for(y=0; y<5; y++)
			printf("%d\t",y);
		printf("\n");
	}
	return 0;
}
