/*FUNZIONE MODULO DIFFERENZA: Si realizzi un programma C che contenga una funzione diff_abs che prenda come parametri 2 float (a e b) e la cui esecuzione faccia si che la variabile corrispondente al primo argomento contenga il valore di a-b, mentre la seconda variabile corrispondente al secondo argomento contenga b-a. Si stampi a video il contenuto delle 2 variabili all'uscita dall'esecuzione della funzione, con precisione alla seconda cifra decimale.
Input:	3.14	-2.71	Output:	5.85	-5.85	*/
#include<stdio.h>
float diffabs1(float x, float y){
	return x-y;
}
float diffabs2(float x, float y){
	return y-x;
}
int main(){
	float a, b;
	scanf("%f",&a);
	scanf("%f",&b);
	printf("%.2f\n",diffabs1(a,b));
	printf("%.2f\n",diffabs2(a,b));
	return 0;
}
/*oppure
void diff_abs(float *a,float *b){
	float temp1=0, temp2=0;
	temp1=*a-*b;
	temp2=*b-*a;
	*a=temp1;
	*b=temp2;
}
int main(){
	float num1, num2;
	scanf("%f", &num1);
	scanf("%f", &num2);
	diff_abs(&num1, &num2);
	printf("%.2f\n%.2f\n", num1, num2);
	return 0;
}

oppure
void diff_abs(float *a,float *b){
	float temp1=0;
	temp1=*a-*b;
	*a=temp1;
	*b=-*a;
}

oppure
void diffabs(float *a, float *b){
	float v=*a;
	*a=*a-*b;
	*b=*b-v;
}

int main(){
	float num1, num2;
	scanf("%f", &num1);
	scanf("%f", &num2);
	diff_abs(&num1, &num2);
	printf("%.2f\n%.2f\n", num1, num2);
	return 0;
}	*/
