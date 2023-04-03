//il programma stampa su schermo usando argomenti nel main
#include<stdio.h>
//il terzo argomento e' un array di stringhe che contiene i valori delle variabili d'ambiente.
int main(int argc, char *argv[], char *env[]){
	argc=6; 
	int i;
	argv[0]="Nel mio programma\0";
	argv[1]="la stringa\0";
	argv[2]="e' passata\0";
	argv[3]="al\0";
	argv[4]="programma\0";
	argv[5]="\0";
	printf("Ho ricevuto %d argomenti\n",argc-1);
	printf("Questi argomenti sono: \n");
	for(i=0; i<=argc-1; i++)
		printf("%s\n",argv[i]);	
	printf("Questi argomenti sono al contrario: ");
	for(i=5; i>=0; i--)
		printf("%s\n",argv[i]);
	//stampa a video la lista delle variabili ambiente
	//for(i=0; env[i]!=NULL; i++)
		//printf("%s\n",env[i]); 
	return 0;
}

//oppure
#include<stdio.h>
int main(int argc, char *argv[]){
	argc=1; 
	int i, j;
	argv[0]="Ornela\0";
	for(i=0; i<=argc-1; i++)
		printf("%s\n",argv[i]);	
	return 0;	
}
