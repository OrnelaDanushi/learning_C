/*FUNZIONE MULTIPLI: Si realizzi un programma nel linguaggio C che, dati due interi N e M da standard input, facendo uso di una funzione di nome multipli, calcoli l'insieme degli interi appartenenti all'intervallo [1,N] che sono multipli di M. La chiamata a funzione dovra' stampare tutti gli elementi dell'insieme ordinati in ordine crescente.
Input:	10	3		Output:	3	6	9	*/
#include<stdio.h>
int multipli(int n, int m){
	int a[n],i;
	for(i=1; i<n+1; i++){
		a[i]=i;
		if(a[i]%m==0)
			printf("%d\n",i);
	}
	return;
}
int main(){
	int x, y;
	scanf("%d",&x);
	scanf("%d",&y);
	int mul=multipli(x,y);
	return 0;
}
/*oppure
void multipli(int n, int m){
	int i;
	for(i=1; i<n+1; i++)
		if(i%m==0) 
			printf("%d\n",i);
}
int main(){	
	int m,n;
	scanf("%d",&n);
	scanf("%d",&m);
	multipli(n,m);
	return 0;
}	*/


