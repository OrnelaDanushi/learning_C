//ARITMETICA DEI PUNTATORI
#include<stdio.h>
#include<string.h> //ci sono le funzioni per manipolare le stringhe
#include<stdlib.h> //per array dinamici
int main(){
	int tabella[4]={10,20,30,40}; //e' un array di 4 interi
	
	int *p;
	p=&tabella[0]; //oppure
	p=tabella;	
 //p e' un puntatore al primo elemento dell'array, oppure essendo l'array un puntatore costante, 
  // p e' un puntatore al primo elemento di una sequenza fissata di elementi. Di fatto un'array e' un puntatore particolare: 
  // non possiamo associare ad esempio ad un array il valore di un altro indirizzo
	p=p+1; //se incrementiamo il puntatore 
	printf("%d\n",*p); 
  //il risultato NON e' di incrementare di 1 il valore del puntatore, bensi' di un numero di bytes equivalenti all'ampiezza di un intero, 
  // cioe' 4. In questo modo la variabile puntatore puntera' al secondo elemento dell'array(questo perche' 
  // gli elementi di un array sono memorizzati consecutivamente). Quindi con i puntatori si scorrono gli elementi di un array.
	p=p-1; //se decrementiamo il puntatore 
	printf("%d\n",*p); //analogamente, l'array viene percorso all'indietro
	
	int *puntatore1=&tabella[0];
	int *puntatore2=&tabella[3];
	//la sottrazione tra puntatori conta gli elementi che separano i puntatori,avra' sempre tipo intero
	int i=puntatore2-puntatore1;
	printf("%d\n",i); 
	//analogamente se dovessimo sommare puntatore1 con 3 otterremo puntatore2
	int *a[10]; //array di 10 puntatori a int
	int (*p)[10]; //puntatore ad un array di 10 int
	int *f(int); //	funzione che prende un int e restituisce un puntatore a int
	int (*p)(int); //puntatore a funzione che prende e restituisce un int
	int *a[](int); //array di funzioni che prendono un int e restituiscono un puntatore a int 
	int (*a[])(int); //array di puntatori a funzioni che prendono e restituiscono un int
	int (*p)[](int); //puntatore ad un array di funzioni che prendono e restituiscono un int

	char stringa[7]={'O','r','n','e','l','a','\0'};//specificando la dimensione
	printf("%s\n",stringa);
	char string[]={'L','a','g','o',' ','B','o','r','a','c','i','f','e','r','o','\0'};//non specificando la dimensione
	printf("%s\n",string);
	char *s;
	char *token; //sottostringa
	char *temp="prima|seconda|terza|quarta";
	s=(char *)malloc((strlen(temp)+1)*sizeof(char));
	strcpy(s,temp); //realizza la copia della stringa s nella temp compreso il carattere terminatore
	while((token=strsep(&s,"|"))!=NULL)
		printf("%s\n",token);
	char *p="abc"; 
  //Le costanti di tipo stringa o stringa letterale vengono scritte tra doppi apici e vengono trattate come puntatori, 
  // quest'ultimi sono delle variabili che contengono l'indirizzo di memoria di un'altra variabile, in questo caso il puntatore e' 
  // la variabile p che contiene l'indirizzo di memoria di un carattere, o meglio, di una costante di tipo stringa. 
  // Mentre per conoscere l'indirizzo di una variabile si utilizza l'operatore & tramite il quale accediamo indirettamente alla variabile p. 
  // Per dereferenziare (accedere alla locazione di memoria puntata) si utilizza l'operatore *
	printf("%s %s %s\n",p,p+1,p+2);
	int i=42;
	int *puntatore=&i; //assegnamento della variabile puntatore l'indirizzo di i
	*puntatore=1; //modifica indirettamente il contenuto della variabile i 
	printf("%d\n",i); //al termine il valore di i e' 1 sebbene non sia stato modificato direttamente	
	//questi tre modi seguenti sono equivalenti:
	char arr1[]="abc"; 	
	char arr2[4]="abc";
	char arr3[]={'a','b','c','\0'}; 
  //in questo caso l'array non e' costante per cui e' liberamente modificabile.
  // Una stringa e' un array di caratteri che contiene la sequenza di caratteri che forma la stringa seguita dal carattere speciale di fine 
  // stringa: '\0'. Se quest'ultimo carattere non c'e' e' un array
	char *buffer=(char *)malloc(50*sizeof(char));
	scanf("%s",buffer); 
  // Con questa istruzione vengono letti da input i caratteri in sequenza fino a trovare il primo carattere bianco, 
  // oppure un tab, un interlinea ecc. Questi caratteri vengono messi dentro il vettore buffer, al posto del carattere bianco, 
  // viene posto il carattere'\0'. Il vettore deve essere sufficientemente grande da contenere tutti i caratteri letti. 
  // NON si usa &buffer ma direttamente buffer! perche' buffer essendo di tipo char* e' gia' un indirizzo!!
	printf("%s\n", buffer);	
	return 0;
}
