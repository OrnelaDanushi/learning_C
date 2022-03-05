/*GESTORE CORSA 1000 METRI: Si implementi un gestore di gare di corsa. La gara, a cui partecipa un numero variabile di atleti, consiste in una corsa lunga 1000 metri. Gli atleti partono tutti insieme e i loro tempi parziali vengono misurati ogni 100 metri. Per ogni atleta vi saranno dunque 10 misurazioni, l'ultima delle quali e' il tempo di raggiungimento del traguardo. Il programma prende in input le informazioni sugli atleti e i loro tempi parziali misurati durante una gara, ed elabora delle statistiche. Dato lo scheletro di codice qui riportato (e che puo' essere scaricato dagli allegati), lo si completi aggiungendo l'implementazione delle funzioni richieste.
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int tempi[10]; //Tempi misurati ogni 100 metri
	char nome[20]; //Nome dell'atleta
}corridore;
corridore *leggiInput(int *dim);	//funzioni da implementare
int trovavincitore(corridore *vect, int dim);
int *tempitointevalli(corridore c);
int *trovasprint(corridore c);
int main(){
	corridore *input;
	int dim, dimsprint, vincitore, i, j, *intervalli, *sprint;
	input=leggiInput(&dim);	//legge l'input
	printf("Stampa dei valori in input: (%d atleti)\n",dim);
	for(i=0; i<dim; i++){
		printf("Tempi per l'atleta %s:",input[i].nome);
		for(j=0; j<10; j++)	printf("%d",input[i].tempi[j]);
		printf("\n");
	}
	vincitore=trovavincitore(input, dim);	//trova il vincitore
	printf("Nome del vincitore: %s (migliore tempo: %d secondi)\n",input[vincitore].nome,input[vincitore].tempi[9]);
	for(i=0; i<dim; i++){	//converti da tempi ad intervalli
		intervalli=tempitointervalli(input[i]);
		printf("Intervalli per l'atleta %s:",input[i].nome);
		for(j=0; j<10; j++)	printf("%d",intervalli[j]);
		printf("\n");
		free(intervalli);
	}
	for(i=0; i<dim; i++){	//trova gli sprint
		sprint=trovasprint(input[i]);
		printf("Sprint per l'atleta %s:",input[i].nome);
		for(j=0; j<10; j++)	printf("%d",sprint[j]);
		printf("\n");
		free(sprint);
	}
	return 0;
}
Le funzioni devono implementare le seguenti operazioni:
-leggiInput: legge un numero n e successivamente le informazioni riguardanti n atleti, inserendoli in un array nell'ordine in cui vengono letti. Per ogni atleta, vengono letti prima il suo nome (una parola che consiste solo di caratteri senza spazi, lunga in tutto meno di 20 caratteri), quindi 10 interi, corrispondenti alle misurazioni dei tempi parziali, in secondi. La funzione retituisce l'array che contiene, per ogni atleta, una struttura corridore, contenente le informazioni lette. Inoltre, la funzione scrive, nell'indirizzo puntato da dim, il valore n, ovvero il numero di elementi dell'array restituito.
-trovavincitore: la funzione accetta come parametri un array di strutture corridore e la sua dimensione dim, e restituisce l'indice (posizione nell'array) dell'atleta che ha vinto la gara.
-tempitointervalli: la funzione accetta come parametri un corridore c. A partire dai tempi parziali del corridore, la funzione genera e restituisce un array contenente i tempi di percorrenza di ogni tratto. Ad esempio, se i tempi di percorrenza del corridore sono T=[10,20,30,40,49,61,72,82,92,102], l'array risultante sara' I=[10,10,10,10,9,12,11,10,10,10].
-trovasprint: la funzione accetta come parametro una struttura corridore. A partire dai tempi parziali, restituisce un array A contenente 10 interi di valore 0 o 1. L'elemento i-esimo di A avra' valore 1 se nel tratto i l'atleta ha fatto uno sprint, ovvero ha percorso il tratto in meno della meta' del tempo rispetto alla media degli altri intervalli. Varra' 0 altrimenti.
input:	3							output:	Stampa dei valori in input: (3 atleti)	
	mohammed_ali 12 24 32 45 50 60 70 81 92 97			Tempi per l'atleta mohammed_ali: 12 24 32 45 50 60 70 81 92 97	
	salvio_berluschini 12 22 30 43 48 55 60 71 82 86		Tempi per l'atleta salvio_berluschini: 12 22 30 43 48 55 60 71 82 86
	renzo_mattei 7 15 22 32 43 54 63 76 85 110			Tempi per l'atleta renzo_mattei: 7 15 22 32 43 54 63 76 85 110	
									Nome del vincitore: salvio_berluschini (miglior tempo: 86 secondi)
									Intervalli per l'atleta mohammed_ali: 12 12 8 13 5 10 10 11 11 5
									Intervalli per l'atleta salvio_berluschini: 12 10 8 13 5 7 5 11 11 4
									Intervalli per l'atleta renzo_mattei: 7 8 7 10 11 11 9 13 9 25	
									Sprint per l'atleta mohammed_ali: 0 0 0 0 1 0 0 0 0 1	
									Sprint per l'atleta salvio_berluschini: 0 0 0 0 0 0 0 0 0 1	
									Sprint per l'atleta renzo_mattei: 0 0 0 0 0 0 0 0 0 0	*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int tempi[10]; //Tempi misurati ogni 100 metri
	char nome[20]; //Nome dell'atleta
}corridore;

corridore *leggiInput(int *dim){	
	int i, j;
	scanf("%d", dim);
	corridore *sportivi=(corridore *)malloc((*dim)*sizeof(corridore));
	for(i=0; i<*dim; i++){
		scanf("%s", sportivi[i].nome);
		for(j=0; j<10; j++)	scanf("%d", &sportivi[i].tempi[j]);
	}
	return sportivi;
}
int trovavincitore(corridore *vect, int dim){
	int menotempo=1000, i, s=0;
	for(i=0; i<dim; i++){
		if(vect[i].tempi[9]<menotempo){
			menotempo=vect[i].tempi[9];
			s=i;
		}
	}
	return s;

/*	//in modo piu' complicato
	int i=0,j=0, *max=malloc(dim*sizeof(int)), min=0;
	if(dim==1)	return 0;
	else if(dim>1){
		for(i=0; i<dim; i++)	max[i]=vect[i].tempi[9];
		for(i=0; i<dim; i++)	if(max[i]>max[i+1])	min=max[i+1];
		i=0;
		while(i<dim){
			if(max[i]==min)	return i;
			else if(max[i]!=min)	i++;
		}
	}
	return i;
*/
}
int *tempitointervalli(corridore c){
//time lo devo per forza dichiarare cosi, e non time[10] altrimenti la considera una variabile
	int j, *time=calloc(1000,10*sizeof(int));
//	oppure
//	int *time=calloc(10,sizeof(int);

//	int *time=(int *)malloc(10*sizeof(int)); 
//	for(i=0; i<10; i++)	time[i]=0;	//non e' necessario
	
	time[0]=c.tempi[0];
	for(j=1; j<10; j++)	time[j]=c.tempi[j]-c.tempi[j-1];
	return time;
}
int *trovasprint(corridore c){
	int i, *a=malloc(10*sizeof(int)), *time=tempitointervalli(c), somma=0, media=0;
	for(i=0; i<10; i++)	somma=somma+time[i];
	media=somma/18;
	//printf("%d ",media);
//	for(i=0; i<10; i++)	a[i]=0; //non necessario
	for(i=0; i<10; i++){
		if(time[i]>media)	a[i]=0;
		else a[i]=1;
	}
	return a;
}

int main(){
	corridore *input;
	int dim, dimsprint, vincitore, i, j, *intervalli, *sprint;

	//Legge l’input
	input=leggiInput(&dim);
	printf("Stampa dei valori in input: (%d atleti)\n", dim);
	for(i=0; i<dim; i++){
		printf("Tempi per l'atleta %s: ", input[i].nome);
		for(j=0; j<10; j++)	printf("%d ", input[i].tempi[j]);
		printf("\n");
	}

	//Trova il vincitore
	vincitore=trovavincitore(input, dim);
	printf("Nome del vincitore: %s (miglior tempo: %d secondi)\n", input[vincitore].nome, input[vincitore].tempi[9]);

	//Converti da tempi ad intervalli
	for(i=0; i<dim; i++){
		intervalli=tempitointervalli(input[i]);
		printf("Intervalli per l'atleta %s: ", input[i].nome);
		for(j=0; j<10; j++)
			printf("%d ", intervalli[j]);
		printf("\n");
		free(intervalli);
	}

	//Trova gli sprint
	for(i=0; i<dim; i++){
		sprint=trovasprint(input[i]);
		printf("Sprint per l'atleta %s: ", input[i].nome);
		for(j=0; j<10; j++)
			printf("%d ", sprint[j]);
		printf("\n");
		free(sprint);
	}
	return 0;
}
