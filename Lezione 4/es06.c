/*ASTERISCHI: 
Scrivere un programma che legga da tastiera un numero intero n e stampi 
n asterischi sulla prima linea, 
n-2 asterischi sulla seconda linea, 
n-4 sulla terza e cosi via, 
fino ad arrivare a stampare uno o due asterischi sull'ultima linea.
Input:	5	Output:	*****	***	*
Input:	8	Output:	********	******	****	**	*/

#include<stdio.h>
int main(){
	int n, i, ast;
	scanf("%d", &n);
	for(i=n; i>0; i=i-2){
		for(ast=1; ast<=i; ast++)
			printf("*");
		printf("\n");
	}
	return 0;
}

/*	oppure
int main(){
	int n, i, j;
	char x;
	scanf("%d", &n);
	for(i=n; i>=1; i=i-2){
		for(j=0; j<i; j++)
			printf("%c",42);
		printf("\n");
	}
	return 0;
}	*/
