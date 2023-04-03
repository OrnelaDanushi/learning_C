//il programma calcola l’area di un rettangolo
#include<stdio.h>
#include<math.h>
int main(){
	double base, height, area;
	printf("Enter the sides of rectangle: \n");
	scanf("%lf %lf", &base, &height);
	area=base*height;
	printf("Area of Rectangle=%.2lf\n", area);
	return 0;
}

/*
//il programma calcola l’area di un cerchio
#include<stdio.h>
#define PI (3.1415f)
int main(){
	float r; //raggio del cerchio
	float a; //area del cerchio
	scanf("%f",&r);
	a=PI*r*r;
	printf("%.2f\n",a);
	return 0;
}
*/
