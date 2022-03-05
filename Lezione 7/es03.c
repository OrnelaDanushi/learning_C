/*GESTIONE PRL: Si scriva un programma per la gestione degli esercizi del corso di PRL. Si legga da tastiera un intero n, dopodiche' per n volte si legga:
-il numero della lezione (un intero);
-l'identificatore dell'esercizio (un intero);
-il numero di studenti che hanno svolto l'esercizio (un intero);
-le matricole degli studenti che hanno svolto l'esercizio (una per riga, ogni matricola e' un intero).
A questo punto si legga un intero m. Si stampino quindi il numero della lezione e l'identificatore di tutti igli esercizi svolti dallo studente con matricola m, uno per riga, nel formato [NumeroLezione].[Identificatore]. Ad es. per indicare che lo studente con matricola m ha risolto soltanto il secondo esercizio della terza lezione, si stampera' la stringa 3.2. Se lo studente non ha risolto nessun esercizio, non bisogna stampare niente.
Input:	2	1	1	3	452341	998721	998124	1	2	1	998721	998721	
Output:	1.1	1.2	*/
#include<stdio.h>
#include<stdlib.h>
int i=0;
typedef struct{
	int lezione;
	int esercizio;
	int studenti; //numero studenti che hanno svolto l'esercizio
	int *matricola;
}prl;
int main(){
	int n, contas=0, j, m;
	scanf("%d", &n);
	prl *laboratorio=(prl *)malloc(n*sizeof(prl));
	for(i=0; i<n; i++){
		scanf("%d",&laboratorio[i].lezione);
		scanf("%d",&laboratorio[i].esercizio);
		scanf("%d",&laboratorio[i].studenti);
		if(laboratorio[i].studenti!=0){
			laboratorio[i].matricola=malloc((laboratorio[i].studenti)*sizeof(int));
			for(j=0; j<laboratorio[i].studenti; j++){
				scanf("%d",&laboratorio[i].matricola[j]);
			}
		}
	}
	scanf("%d",&m);
	for(i=0; i<n; i++){
		for(j=0; j<laboratorio[i].studenti; j++){
			if(m==laboratorio[i].matricola[j]){
				printf("%d",laboratorio[i].lezione);
				printf(".");
				printf("%d\n",laboratorio[i].esercizio);
			}
		}
	}
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>

typedef struct _esercizio{
	int lezione;
	int ide;
	int num;
	int matricola[100];
}esercizio;

int main(){
	int n, i, m, trovato=0, j;
	scanf("%d", &n);
	esercizio *prl=(esercizio *)malloc(n*sizeof(esercizio));
	for(i=0; i<n; i++){
		scanf("%d", &(prl[i].lezione));
		scanf("%d", &(prl[i].ide));
		scanf("%d", &(prl[i].num));
		for(j=0; j<prl[i].num; j++)
			scanf("%d", &(prl[i].matricola[j]));
	}
	scanf("%d", &m);
	i=0; 
	while(i<n && trovato==0){
		for(j=0; j<prl[i].num; j++){
			if(prl[i].matricola[j]==m)
				printf("%d.%d\n", prl[i].lezione, prl[i].ide);
		}
		i++;
	}
	return 0;
}	*/
