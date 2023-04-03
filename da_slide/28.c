/*l'esercizio non termina oppure non esegue niente perche' la guardia del for e' sempre verificata, mentre per uscire dal ciclo for la guardia deve diventare falsa*/
#include<stdio.h>
int main(){
	int i;
	for(i=0; i%2==1; i+=2)
		printf("%d\n",i);
	return 0;
}
//oppure
#include<stdio.h>
int main(){
	int i;
	for(i=0; i<=0; i--)
		printf("%d\n",i);
	return 0;
}
