//spiegazione del comportamento comandi break e continue
#include <stdio.h>
int main(){
	int value;
	while(scanf("%d",&value)==1 && value!=0){ 
		if(value<0){
			printf("Illegal value \n");
			break;	/* Abandon the loop */
		}
		if(value>100){
			printf("Invalid value \n");
			continue;	/* Skip to start loop again */
		}
	} /* end while value != 0 */
	return 0;
}
