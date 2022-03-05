/*SOTTOSUCCESSIONE: Scrivere un programma che legga da tastiera una sequenza di 10 interi scrivendola in un array, quindi stampi (uno per linea, e nello stesso ordine in cui sono stati immessi) i valori della sequenza che rispettano una di queste due proprieta': siano positivi e pari, oppure siano negativi e succeduti da un valore positivo. NB: Lo 0 e' considerato un valore positivo
input	13	-3	-5	5	0	2	-3	-6	3	-8
output	-5	0	2	-6 */
#include<stdio.h>
int main(){
	int a[10], i;
	for(i=0; i<10; i++)	scanf("%d",&a[i]);
	for(i=0; i<10; i++)
		if((a[i]>=0 && a[i]%2==0)||(i<9 && a[i]<0 && a[i+1]>=0))
			printf("%d\n",a[i]);
	
	return 0;
}

/*oppure
int main(){
	int a[10], i=0;
	for(i=0; i<10; i++)	scanf("%d", &a[i]);
	if(a[9]>=0){
		for(i=0; i<10; i++){
			if((a[i]>=0 && a[i]%2==0) || (a[i]<0 && a[i+1]>=0))
				printf("%d\n", a[i]);
		}
	}else if(a[9]<0){
		for(i=0; i<9; i++){
			if((a[i]>=0 && a[i]%2==0) || (a[i]<0 && a[i+1]>=0))
				printf("%d\n", a[i]);
		}
	}
	return 0;
}	*/
