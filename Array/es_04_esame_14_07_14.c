/* Si definisca una funzione int check(int a[], int b[], int dima, int dimb) che, 
dati due array di interi e le loro dimensioni, restituisce il valore di verit`a della seguente formula:	
∃j ∈[0, dima).(#{i|i ∈[0, dimb) ∧ a[j]=b[i]}=3).	*/

#include<stdio.h>
int check(int a[], int b[], int dima, int dimb){
	int j=0, i=0, trovato=0, conta;
	while(j<dima && trovato==0){
		conta=0;
		for(i=0; i<dimb; i++){
			if(a[j]==b[i])	conta++;
		}
		if(conta==3)	trovato=1;
		else j++;
	}
	return trovato;
}
int main(){
	int a[100], b[100], i=0, dima=0, dimb=0;
	scanf("%d", &a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}
	dima=i, i=0;
	scanf("%d", &b[i]);
	while(b[i]!=0){
		i++;
		scanf("%d",&b[i]);
	}
	dimb=i;
	for(i=0; i<dima; i++)	printf("%d ",a[i]);
	printf("\n");
	for(i=0; i<dimb; i++)	printf("%d ",b[i]);
	printf("\n");
	printf("%d\n",check(a,b,dima,dimb));
	return 0;
}
