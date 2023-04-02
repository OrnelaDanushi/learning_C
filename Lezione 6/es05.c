/*MATRICI: 
Si legga dall'input una matrice di interi di dimensione 4*3 (4 righe, 3 colonne). 
I valori dati in input sono ordinati per riga (i primi 3 interi sono i valori della prima riga della matrice, 
e cosi via). Si stampi l'indice dell'ultima colonna che contiene solo multipli di 3, 
o si stampi -1 nel caso che nessuna colonna rispetti questa proprieta'. 
Input:	5	3	12	5	6	6	5	21	3	5	6	24
Output:	2	*/

#include<stdio.h>
int main(){
	int a[4][3], i, j, colonna=-1, trovato=0, conta=0;
	for(i=0; i<4; i++)
		for(j=0; j<3; j++)
			scanf("%d",&a[i][j]);
	i=0, j=2;
	while(j>=0 && trovato==0){
		if(a[i][j]%3==0){
			conta=j;
			trovato=1;
		}else	j--;
	}
	if(trovato!=0){
		i=1; j=conta;
		while(i<4)
			if(a[i][conta]%3!=0)	colonna=-1;
			else if(a[i][conta]%3==0){
				i++;
				colonna=conta;
			}
	}
	printf("%d\n",colonna);
	return 0;
}

/*oppure
int main(){
	int a[4][3], i, j, conta=0, trovato=0, ris=0;
	for(i=0; i<4; i++)
		for(j=0; j<3; j++)
			scanf("%d", &a[i][j]);
//	for(i=0; i<4; i++){
//		for(j=0; j<3; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
	i=0, j=2;
	while(j>=0){
		trovato=0;
		for(i=0; i<4; i++){
			if(a[i][j]%3==0)
				trovato++;
		}if(trovato==4){
			ris=j;
			break;
		}else if(trovato!=4){
			j--;
		}
	}
	if(trovato!=4)		printf("-1\n");
	else if(trovato==4)	printf("%d\n", ris);
	return 0;
}
