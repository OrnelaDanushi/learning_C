/*Esempio di richiamo di una funzione. Le direttive del preprocessore possono essere scritte in qualsiasi 
parte del programma anche se e' buon uso metterle all'inizio. 
La dichiarazione di una funzione avviene prima della sua definizione, quest'ultima puo' avvenire anche dopo 
il main anche se e' buon uso farle insieme. Non dimenticarsi il return in una funzione.*/

#include<stdio.h>
int somma(int x, int y){
	return (x+y);
}
int main(){
	printf("%d\n",somma(40,2));
	return 0;
}
