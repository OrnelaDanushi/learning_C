// stampa le cifre da 0 fino a 9

#include<stdio.h>
#define CIFRE 9

int main(){
	int i;
	for(i=0; i<=CIFRE; i++)
		printf("%d\n",i);
	return 0;
}

/*
Programma 2
#include<stdio.h>
#define PRODOTTO(x,y) ((x)*(y)) //se fosse stato (x*y), restituiva un risultato sbagliato

int main()
{
	int i,j=2;
	i=PRODOTTO(j+1,3);
	printf("%d\n",i);
	int b,c=0;
	b=(c++,c*2);
	printf("%d\n",b);
	int d,e=0;
	d=e++,e*2; //qui l'assegnamento ha precedenza rispetto alla virgola
	printf("%d\n",d);	
	return 0;
}

*/
