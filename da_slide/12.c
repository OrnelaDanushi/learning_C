//Questo programma genera un numero casuale da 0 a 100 (in un intervallo)
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	int i;
	//La funzione time con argomento NULL restituisce i secondi trascorsi dal 1.1.1970 (epoch). Ad ogni esecuzione (purche' non troppo vicine) otterremo un seme diverso.
	srand(time(NULL)); 
	i=rand()%100+1;
	printf("Il numero casuale generato e':%d\n",i);
	return 0;
}

//oppure
//Questo programma genera un numero casuale molto grande
#include<stdio.h>
#include<stdlib.h>
int main(){
	int numero=0;
	//inizializzando il seme della funzione srand() ad un valore diverso da NULL non serve la funzione #include<time.h>
	srand(42); 
	//il numero casuale cosi generato assume valori molto grandi, se vogliamo invece un numero compreso tra un intervallo tra 0 e L dobbiamo usare l'operatore modulo %L.
	numero=rand(); 
	printf("Il numero casuale e' %d\n",numero);
	return 0;	
}

//oppure
//Questo programma genera un numero casuale molto grande
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	int numero=0;
	srand(time(NULL));
	numero=rand();
	printf("Il numero casuale generato e':%d\n",numero);
	return 0;
}
