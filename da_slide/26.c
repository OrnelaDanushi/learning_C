/*programma che legge l'eta da tastiera e stabilisce se sei minorenne oppure maggiorenne*/
#include<stdio.h>
int main(){
	int eta; 
	printf("Inserire la tua eta in anni ");
	scanf("%d",&eta);
	if(eta>=18)
		printf("Birra e alcool per te!!\n");
	else 	
		printf("Sei ancora minorenne.\n");
	return 0;
}
