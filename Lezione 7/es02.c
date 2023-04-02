/*STUDENTI: 
Si scriva un programma di gestione studenti che legga dall'input un intero n, quindi per n volte, 
si legga uno studente, definito come:
-una matricola (un intero);
-un'eta' (un intero);
-il sesso (un intero, 0 per maschio, 1 per femmina);
Dopodiche' si legge un intero m. A questo punto:
-Stampare la media e la varianza dell'eta' degli studenti maschi (uno per riga, 2 cifre decimali). 
Stampare media e varianza uguale a 0 se non ci sono studenti maschi.
-Stampare la media e la varianza dell'eta' delle studentesse (uno per riga, 2 cifre decimali). 
Stampare media e varianza uguale a 0 se non ci sono studentesse.
-Stampare le seguenti informazioni, una per riga:
	-eta' dello studente con matricola m
	-sesso dello studente con matricola m. 
	Anziche' stampare l'intero, stampare il carattere 'M' se lo studente e' maschio, 'F' se e' femmina. 
	Se lo studente m non e' presente, stampare -1 sia per l'eta' che per il sesso. 
Ricordiamo che la varianza e' definita come: 
var=((x1 -mu)^2 + (x2 -mu)^2 +...+(xn -mu)^2)/(N-1) 
dove N e' il numero degli studenti maschi, 
x1,x2,...,xn sono le eta' degli studenti maschi, 
e mu e' la media delle eta' degli studenti maschi 
(usare la stessa formula con i dovuti cambiamenti per la varianza delle studentesse). 
N.B: si consiglia di definirsi opportunatamente una struct di nome studente 
ed un enumerazione per definire il sesso dello studente.
Input:	3	112345	19	1	223456	20	0	998724	27	0	223456
Output:	23.50	24.50	19.00	0.00	20	M	*/

#include<stdio.h>
#include<stdlib.h>
#define VALORE 100
int i=0;
typedef enum{
	maschio,
	femmina
}sesso;
typedef struct{
	int matricola;
	int eta;
	sesso specie;
}studente;
int main(){
	float mediam,mediaf,sommam=0,sommaf=0, varianzam=0, varianzaf=0;
	int n, contam=0,contaf=0, *extetam, *extetaf, trovato=0;
	int *etam=(int *)malloc(100*sizeof(int));
	int *etaf=(int *)malloc(100*sizeof(int));
	scanf("%d",&n);
	studente *universitario=(studente *)malloc(n*sizeof(studente));
	for(i=0; i<n; i++){
		scanf("%d",&(universitario[i].matricola));
		scanf("%d",&(universitario[i].eta));
		scanf("%u",&(universitario[i].specie));
		if((universitario[i].specie)==0){
			etam[contam]=universitario[i].eta;
			contam++;
			extetam=realloc(etam,(contam+1)*sizeof(int));
			etam=extetam;
			sommam=sommam+universitario[i].eta;
		}
		else if((universitario[i].specie)==1){
			etaf[contaf]=universitario[i].eta;
			contaf++;
			extetaf=realloc(etaf,(contaf+1)*sizeof(int));
			sommaf=sommaf+universitario[i].eta;
		}
	}
	int m;
	scanf("%d",&m);
	if(contam==0){
		printf("%.2f\n",0.00);
		printf("%.2f\n",0.00);
	}
	else if(contam!=0){
		mediam=(float)sommam/contam;
		printf("%.2f\n",mediam);
		if(contam==1){
			printf("%.2f\n",0.00);
		}
		else if(contam!=1){
			for(i=0; i<contam; i++){
				varianzam+=((etam[i]-mediam)*(etam[i]-mediam))/(contam-1);
			}
			printf("%.2f\n",varianzam);
		}
	}
	if(contaf==0){
		printf("%.2f\n",0.00);
		printf("%.2f\n",0.00);
	}
	else if(contaf!=0){
		mediaf=(float)sommaf/contaf;
		printf("%.2f\n",mediaf);
		if(contaf==1){
			printf("%.2f\n",0.00);
		}
		else if(contaf!=1){
			for(i=0; i<contaf; i++){
				varianzaf+=((etaf[i]-mediaf)*(etaf[i]-mediaf))/(contaf-1);
			}
			printf("%.2f\n",varianzaf);
		}
	}
	i=0;
	while(i<n && trovato==0){
		if((m==universitario[i].matricola)&&(universitario[i].specie==0)){
			printf("%d\n",universitario[i].eta);
			printf("M\n");
			trovato=1;
		}
		else if((m==universitario[i].matricola)&&(universitario[i].specie==1)){
			printf("%d\n",universitario[i].eta);
			printf("F\n");
			trovato=1;
		}			
		i++;
	}	
	if(trovato==0){
		printf("-1\n");
		printf("-1\n");
	}
	return 0;
}

/* oppure
#include<stdio.h>
#include<stdlib.h>

typedef enum _sesso{
	maschio, femmina
}sesso;

typedef struct _studente{
	int matricola;
	int eta;
	sesso genere;
}studente;

int main(){
	int n, i, m, contam=0, contaf=0, j, trovato=0;
	float sommam=0, sommaf=0, media=0, varianza;
	scanf("%d", &n);
	studente *universitario=(studente *)malloc(n*sizeof(studente));
	for(i=0; i<n; i++){
		scanf("%d", &(universitario[i].matricola));
		scanf("%d", &(universitario[i].eta));
		scanf("%u", &(universitario[i].genere));
		if(universitario[i].genere==0){
			sommam=sommam+universitario[i].eta;
			contam++;
		}else if(universitario[i].genere==1){
			sommaf=sommaf+universitario[i].eta;
			contaf++;
		}
	}
	scanf("%d", &m);
	if(contam==0)
		printf("0.00\n0.00\n");
	else if(contam!=0){
		media=(float)sommam/contam;
		printf("%.2f\n", media);
		j=0, i=0;
		if(contam==1)
			printf("0.00\n");
		else if(contam>1){
			while(i<contam){
				if(universitario[j].genere==0){
					varianza+=((universitario[j].eta-media)*(universitario[j].eta-media))/(contam-1);
					i++;
				}
				j++;
			}
			printf("%.2f\n", varianza);
		}
	}

	if(contaf==0)
		printf("0.00\n0.00\n");
	else if(contaf!=0){
		media=0, varianza=0;
		media=(float)sommaf/contaf;
		printf("%.2f\n", media);
		j=0, i=0;
		if(contaf==1)
			printf("0.00\n");
		else if(contaf>1){
			while(i<contaf){
				if(universitario[j].genere==1){
					varianza+=((universitario[j].eta-media)*(universitario[j].eta-media))/(contaf-1);
					i++;
				}
				j++;
			}
			printf("%.2f\n", varianza);
		}
	}

	i=0;
	while(i<n && trovato==0){
		if(universitario[i].matricola==m){
			printf("%d\n", universitario[i].eta);
			if(universitario[i].genere==0)	printf("M\n");
			else if(universitario[i].genere==1)	printf("F\n");
			trovato=1;
		}i++;
	}
	if(trovato==0)	printf("-1\n-1\n");
		
	return 0;
}	*/
