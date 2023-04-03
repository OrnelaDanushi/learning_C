//ordinamento di 3 valori
#include<stdio.h>
int main(){
	int n, m, o, i, min, medio, mass;
	printf("Scrivi 3 valori: ");
	scanf("%d %d %d", &n, &m, &o);
	for(i=0; i<3; i++){
		if(n<m && n<o)
			min=n;
		if(m<n && m<o)
			min=m;
		if(o<n && o<m)
			min=o;	
		if((n>m && n<o) || (n<m && n>o))
			medio=n;
		if((m>n && m<o) || (m<n && m>o))
			medio=m;
		if((o>n && o<m) || (o<n && o>m))
			medio=o;
		if(n>m && n>o)
			mass=n;
		if(m>n && m>o)
			mass=m;
		if(o>n && o>m)
			mass=o;	
	}			
	printf("Eccoli in ordine crescente: %d %d %d\n", min, medio, mass);
	printf("Eccoli in ordine decrescente: %d %d %d\n", mass, medio, min);
	return 0;
}
