/* Si definisca una funzione int check(int a[], int dim) che restituisce il valore di verit`a della seguente formula:
∃j ∈ [1, dim − 1).(∀i ∈ [0, j). a[j] < a[i]) ∨ (∀i ∈ [j + 1, dim). a[j] > a[i])	*/

#include<stdio.h>

int check(int a[], int dima){
//oppure se cerco il massimo poi devo confrontare che gli elementi che vengono dopo di esso fino alla fine siano minori
	int i=0, minimo=a[1], posmin=1, conta=0;
	for(i=1; i<dima-1; i++){
		if(a[i]<minimo){
			minimo=a[i];
			posmin=i;
		}
	}
	i=0;
	while(i<posmin){
		if(a[i]>minimo){
			conta++;
			i++;
		}
	}
	if(conta==i)	return 1;
	return 0;
}
int check1(int a[], int dim){	//soluzione del prof
	int trovato=0, j=1, i=0, ok=1;
	while(j<dim-1 && !trovato){
		i=0;
		ok=1;
		while(i<j && ok)
			if(a[i]<=a[j]) ok=0; 
			else i++;
		if(!ok){
			i=j+1;
			ok=1;
			while(i<dim && ok)
				if(a[i]>=a[j]) ok=0; 
				else i++;
		}
		trovato=ok; 
		j++;
	}
	return trovato;
}
int main(){
	int a[100], i=0, dima=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}
	dima=i;
	for(i=0; i<dima; i++)	printf("%d ", a[i]);
	printf("\n");
	printf("%d\n",check(a,dima));
	printf("%d\n",check1(a,dima));
	return 0;
}
