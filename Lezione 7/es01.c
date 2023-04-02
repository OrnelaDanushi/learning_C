/*GESTORE DEL GATTILE: 
Si scriva un programma di gestione di un gattile che legga dall'input un intero n, quindi per n volte, legga:
-un codice identificativo del gatto (un intero);
-l'eta' del gatto in anni (un intero);
-il peso del gatto in kg (un float);
-il tipo di cibo assunto dal gatto, espresso come 
0 per le crocchette, 1 per le scatolette, 2 per il tonno in scatola.
Nello stesso ordine in cui sono stati immessi i dati dei gatti si stampino, uno per linea, 
i codici identificativi e il tipo di cibo di tutti i gatti che hanno problemi di dieta in giovane eta', 
ovvero abbiano meno di 4 anni e pesino piu' della media dei gatti. 
A fianco del codice identificativo, si stampi, separato da uno spazio, il tipo di cibo assunto dal gatto, 
ovvero crocchette, scatolette oppure tonno. 
N.B: Si consiglia di definirsi opportunamente una struct di nome gatto, e rappresentare il tipo di cibo come una enum. 
Input:	5//n				Output:	6 crocchette	
2	13	5.0	1			12 tonno
6	3	6.0	0	
9	2	3.0	2	
1	13	4.0	2	
12	1	4.6	2		*/

#include<stdio.h>
#include<stdlib.h>

typedef enum{ 
	/*e' implicito che crocchette=0, scatolette=1 e tonno=2 
	e cosi se ci dovessero essere altri ancora, possono anche essere scritti crocchette, scatolette, tonno*/
	crocchette, 
	scatolette, 
	tonno
}cibo;

typedef struct{
	int codice;
	int eta;
	float peso;
	cibo svedese;
}gatto;

int main(){
	int n, i=0;
	float media=0, somma=0;
	scanf("%d",&n);
	gatto *persiano=malloc(n*sizeof(gatto)); //va allocata memoria per tutti gli n gatti
	//cibo *svedese=malloc(n*sizeof(cibo));	quest'allocazione di memoria non serve perche' e' gia' inclusa in gatto!!
	for(i=0; i<n; i++){
		scanf("%d",&(persiano[i].codice)); //una struct e' come un array!! quindi si usa l'indice se no rimani sempre li'.
		scanf("%d",&(persiano[i].eta));  //oppure ..(persiano+i->codice));
		scanf("%f",&(persiano[i].peso));
		somma=somma+(persiano[i].peso);
		scanf("%u",&(persiano[i].svedese));
	}
	media=(float)somma/n;
	i=0;
	do{	
		if(persiano[i].eta<4 && persiano[i].peso>media){
			printf("%d ",persiano[i].codice);	
			if(persiano[i].svedese==0)
				printf("crocchette\n"); //la parola gli va scritta! se lascio ...printf("%d\n",persiano[i].svedese)
			else{						//stampa il numero ma non lo trasforma 
				if(persiano[i].svedese==1)
					printf("scatolette\n");
				else{
					if(persiano[i].svedese==2)
						printf("tonno\n");
				}
			}
		}
		i++;
	}while(i<n);		
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>
typedef enum _cibo{
	crocchette, scatolette, tonno
}cibo;
typedef struct _gatto{
	int codice;
	int anni;
	float peso;
	cibo gustoso;
}gatto;
int main(){
	int n,i;
	float somma=0, media=0;
	scanf("%d", &n);
	gatto *miao=(gatto *)malloc(n*sizeof(gatto));
	for(i=0; i<n; i++){
		scanf("%d", &(miao[i].codice));
		scanf("%d", &(miao[i].anni));
		scanf("%f", &(miao[i].peso));
		somma=somma+miao[i].peso;
		scanf("%u", &(miao[i].gustoso));
	}	
	media=(float)somma/n;
	for(i=0; i<n; i++){
		//printf("%d %d %.2f %d\n", miao[i].codice, miao[i].anni, miao[i].peso, miao[i].gustoso);
		if(miao[i].anni<4 && miao[i].peso>media){
			printf("%d ", miao[i].codice);
			if(miao[i].gustoso==0)
				printf("crocchette\n");
			if(miao[i].gustoso==1)
				printf("scatolette\n");
			else if(miao[i].gustoso==2)
				printf("tonno\n");
		}
	}
	return 0;
}	*/
