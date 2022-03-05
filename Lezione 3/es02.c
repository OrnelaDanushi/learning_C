/*TEMPCONVERTER: Scrivere un programma che legga da tastiera un valore di temperatura (anche decimale) espresso in gradi Celsius e ne stampi la conversione in gradi Fahrenheit usando due cifre decimali. Per convertire un valore da Celsius a Fahrenheit si ha che F=C*1.8 + 32
Input: 10		Output: 50.00 */
#include<stdio.h>
int main(){
	float c, f;
	scanf("%f",&c);
	f=c*1.8 +32;
	printf("%.2f\n", f);
	return 0;
}
/*oppure
int main(){	
	float c, f, t; 
	scanf("%f",&c);
	if(t=c*1.8) 
		f=t+32; 
	printf("%.2f",f);
	return 0;
}
*/

/*oppure
int main(){
	float c;
	scanf("%f", &c);
	printf("%.2f\n", (c*1.8)+32);
	return 0;
}*/
