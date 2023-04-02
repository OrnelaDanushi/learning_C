/*
$ gcc helloworld.c -o hello.out
$ ./hello.out
*/

// il più semplice programma è costituito da un
// unico file con la sola funzione main

// direttive per il pre-processore
#include <stdio.h> // libreria standard per funzioni di tipo IO

/*
main() definisce il punto di partenza del programma
void -> non prende parametri in ingresso (in questo caso)
int -> restituisce un intero
*/
int main(void){
    // stampa a schermo la stringa di formattazione
    // passata come argomento
    int age=10;
    printf("Ciao mondo, ho %d anni!\n", age);

    // analisi dei tipi
    printf("%lu\n", sizeof(int)); // 4

    char a = 'a'; // i caratteri si indicano tra apici
    int aa = 'a'; // caratteri visti come interi    
    printf("%c\t\t%d\n",a ,aa); // a, 97 = codifica ASCII

    // f=float rappresentato con 4 bit, lf=double con 8 bit
    printf("%f\t%lf\n",123.34 ,100.1e5); // notazione scientifica
    
    // const è applicato alla dichiarazione di qualsiasi variabilie
    // con l'effetto di affermare che il valore non cambierà
    const double pi=3.145;
    printf("%2.2f\n",pi); 


    /*
    #define = direttiva del preprocessore e
    sostituita all'interno del codice prima della compilazione
    
    const = variabile maneggiata dal compilatore,
    ha un tipo e un indirizzo
    */

    return 0; // valore restituito dal main al SO (0 -> OK) 
}
