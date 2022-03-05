/*VERIFICA DI CONDIZIONE: Scrivere un programma che legga da tastiera 10 interi, li scriva in un array A e stampi l'indice del primo elemento che verifica la seguente condizione: A[i]=A[i+1]-A[i-1] oppure stampi -1 nel caso in cui nessun elemento verifichi la suddetta condizione.
input	9	5	-2	3	5	50	4	-7	0	-7
output	2
input	9	5	-1	3	6	8	1	0	-7	5
output	-1	*/
#include <stdio.h>
int main(){
	int a[10],i,trovato=0;
	for(i=0; i<10; i++) 
		scanf("%d",&a[i]); /*oppure .. scanf("%d",&n);	a[i]=n;*/
	i=1;
	while(i<9 && !trovato){ /*oppure ..trovato==0)*/
		if(a[i]==a[i+1]-a[i-1]){
			printf("%d\n",i);
			trovato=1;
		}
		i++;	/*else lo posso anche omettere*/
	}
	if(!trovato)
		printf("%d\n",-1);
	return 0;
}
