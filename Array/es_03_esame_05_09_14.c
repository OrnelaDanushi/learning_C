/* Si definisca una funzione int check(int a[], int dim) che, dato un array di interi e la sua dimensione, 
controlla che ogni valore dell’array, tranne l’ultimo, sia seguito nell’array da almeno un elemento strettamente minore. Si giochi d’astuzia!.	*/

#include<stdio.h>

/*	//questa non va bene perche' controlla che tutti i successori siano minori
int check(int a[], int dim){
	int i=0, trovato=0;
	while(i<dim-1 && trovato==0){
		if(a[i]<=a[i+1])	trovato=1;
		else if(a[i]>a[i+1])	i++;
	}
	return !trovato;
}	*/

int check(int a[], int dim){
	int i=0, j=0, found=0, trovato=0, conta=0;
	while(i<dim-1 && j<dim && found==0){
		j=i+1;
		if(a[i]>a[j])	i++;
		else if(a[i]<=a[j]){
			if(j==dim-1)
				found=1;
			else{
				while(j<dim && trovato==0){
					if(a[i]>a[j])	trovato=1;
					else if(a[i]<=a[j]){
						conta++;
						j++;
					}
				}
				if(trovato==1){
					trovato=0;
					i++;
				}
				else if(trovato==0 && conta==j-i-1)	found=1;
			}
		}
	}
	return !found;
}
//giocando d'astuzia 
int check1(int a[], int dim){
	int i, index_min=0;
	for(i=1; i<dim; i++)
		if(a[i]<a[index_min])
			index_min=i;
	return (index_min==dim-1);
}
int main(){
	int a[10], i;
	for(i=0; i<10; i++)	scanf("%d", &a[i]);
	printf("%d\n", check(a, 10));
	printf("%d\n", check1(a, 10));
	return 0;
}
