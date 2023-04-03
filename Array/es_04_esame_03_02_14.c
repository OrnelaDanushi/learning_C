/* Si definisca una funzione int check(int a[], int dim) che restituisce il valore di verita' della seguente formula:
∃j ∈ [1, dim − 1).#{i|i ∈ [0, j) ∧ a[j] < a[i]} = #{i|i ∈ [j + 1, dim) ∧ a[j] > a[i]}	*/

#include<stdio.h>
int check(int a[], int dim){
	int i, j=1, conta1=0, conta2=0, trovato=0;
	while(j<dim-1 && trovato==0){
		for(i=0; i<j; i++){
			if(a[i]>a[j])	conta1++;
		}
		for(i=j+1; i<dim; i++){
			if(a[i]<a[j])	conta2++;
		}
		if(conta1==conta2)	trovato=1;
		else{
			conta1=0; 
			conta2=0;
			j++;
		}
	}
	return trovato;
}

int check1(int a[], int dim){	//soluzione del prof
	int trovato=0, j=1, i, conta_prec, conta_succ;
	while(j<dim-1 && !trovato){
		conta_prec=0;
		for(i=0; i<j; i++)
			if(a[j]<a[i]) conta_prec++;
		conta_succ=0;
		for (i=j+1; i<dim; i++)
			if(a[j]>a[i]) conta_succ++;
		trovato=conta_prec==conta_succ;
		j++;
	}
	return trovato;
}

int main(){
	int a[100], i=0, dima=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d", &a[i]);
	}
	dima=i;
	for(i=0; i<dima; i++)	printf("%d ", a[i]);
	printf("\n");
	printf("%d\n",check(a,dima));
	printf("%d\n",check1(a,dima));
	return 0;
}
