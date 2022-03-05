/*MOLTIPLICAZIONE MATRICI: Si legga dall'input 3 interi n, m, t, poi una matrice di interi di dimensione n*m (n righe, m colonne) e una seconda matrice di dimensione m*t. Per ogni matrice i valori dati in input sono ordinati per riga (per la prima matrice i primi m interi sono i valori della prima riga della matrice, e cosi via). Si usi una funzione per leggere le matrici. Si scrivi una seconda funzione che moltiplichi le due matrici e restituisca la matrice risultato (n*t). Si stampi il risultato nella funzione main.
Input:	4//n	2//m	3//t	5	3	5	6	5	21	5	6	1	0	2	2	1	1
Matrice A:	5 3		Matrice b:	1 0 2		Output:	11 3 13
		5 6				2 1 1			17 6 16
		5 21							47 21 31
		5 6							17 6 16			*/

#include<stdio.h>

int main(){
	int n, m, t, i=0, j=0, k=0, l=0, p=0, q=0, somma=0;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &t);
	int a[n][m], b[m][t], ris[n][t];
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	for(i=0; i<m; i++)
		for(j=0; j<t; j++)
			scanf("%d", &b[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<t; j++)
			ris[i][j]=0;

	i=0; j=0;
	while(p<t){
		j=0;
		somma=0;
		while(j<m){
			somma=somma+a[i][j]*b[j][p];
			j++;
		}
		ris[i][p]=somma;
		if(i==n){
			i=0;
			p++;
		}else
			i++;
	}
	for(i=0; i<n; i++){
		for(j=0; j<t; j++)
			printf("%d ", ris[i][j]);
		printf("\n");
	}


	return 0;
}	
