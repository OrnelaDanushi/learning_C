#include <stdio.h> 
void stat(){
	int auto_var=0;
	static int static_var = 0;	//dichiarazione variabile statica
	printf("auto = %d, static = %d \n",auto_var, static_var);
	++auto_var;	//Clearly the auto_var variable is created each time. 
	++static_var;	//The static_var is created once and remembers its value.
}
int main(){
	int i;
	for(i=0; i<5; ++i)
		stat();
	return 0;
}
