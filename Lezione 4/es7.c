/*RETTANGOLI: Scrivere un programma che legga da tatiera 2 interi h e l e stampi un rettangolo fatto da asterischi, con altezza h e lunghezza l.
Input:	5	10	Output:	**********		
				*	 *						
				*	 *						
				*	 *						
				**********	*/

#include<stdio.h>

int main(){
	int altezza, base, i, j;
	scanf("%d", &altezza);
	scanf("%d", &base);
	for(j=0; j<altezza; j++){
		if(j==0 && altezza>1){
			for(i=0; i<base; i++)
				printf("*");
			printf("\n");
		}if(j>0 && j<altezza-1){
			for(i=0; i<base; i++){
				if(i==0)	printf("*");
				if(i==base-2)	printf("*");
				else printf(" ");
			}printf("\n");
		}if(j==altezza-1){
			for(i=0; i<base; i++)
				printf("*");
			printf("\n");
		}
	}
	return 0;
}					
