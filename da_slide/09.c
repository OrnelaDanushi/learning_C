#include <stdio.h>
int main(){
	int i;
i=1;
	printf("Ciao mondo. Vediamo fino a quanto so contare:\n");
	i=i+1;
	printf("%d\n",i);
	i++;
	printf("%d\n",i);
	i++;
	printf("%d\n",i);
	i+=2;
	printf("%d\n",i);
	printf("temo di non arrivare nemmeno a %d\n",--i);
	return 0;
}
