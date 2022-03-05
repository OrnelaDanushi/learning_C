#include<stdio.h>
#include<stdlib.h>

//funzioni da implementare
float **readgrades(int nstudents, int ncourses){
	int i, j;
	float voti, **mat=(float **)malloc(nstudents*sizeof(float *));
	for(i=0; i<nstudents; i++) mat[i]=(float *)malloc((ncourses+1)*sizeof(float));
	for(i=0; i<nstudents; i++)
		for(j=0; j<ncourses+1; j++)
			scanf("%f", &mat[i][j]);
	
/*	for(i=0; i<nstudents; i++){
		for(j=0; j<ncourses+1; j++)
			printf("%.1f ", mat[i][j]);	
		printf("\n");
	}
*/
	return mat;
}
float **studentmaximums(float **grades, int nstudents, int ncourses){
	int i, j;
	float **max=(float **)malloc(nstudents*sizeof(float *)), maximus=0;
	for(i=0; i<nstudents; i++)	max[i]=(float *)malloc(2*sizeof(float));
	for(i=0; i<nstudents; i++){
		maximus=0;
		for(j=1; j<ncourses+1; j++){
			if(grades[i][j]>maximus)	maximus=grades[i][j];
		}
		max[i][0]=grades[i][0];
		max[i][1]=maximus;
	}

/*	for(i=0; i<nstudents; i++){
		for(j=0; j<2; j++)
			printf("%.2f ", max[i][j]);	
		printf("\n");
	}
*/
	return max;
}
float *courseaverages(float **grades, int nstudents, int ncourses){
	float *avg=(float *)malloc(ncourses*sizeof(float)), somma=0;
	int i, j;
	for(j=1; j<ncourses+1; j++){
		somma=0;
		for(i=0; i<nstudents; i++){
			somma=somma+grades[i][j];
		}
		avg[j-1]=(float)somma/nstudents;
	}
//	for(i=0; i<ncourses; i++)	printf("%.2f", avg[i]);
	return avg;
}

//funzione di stampa voti massimi con header(matricola, voto)
void printstudents(float **M, int rows, int columns){
	int i, j;
	printf("%15s%15s\n", "Matricola", "Voto");
	for(i=0; i<rows; i++){
		float *row=M[i];
		for(j=0; j<columns-1; j++)	printf("%15.2f",row[j]);
		printf("%15.2f\n", row[columns-1]);
	}
}

//funzione di stampa voti, con il nome del corso nel header
void printcourses(float *grades, char **coursenames, int size){
	int i;
	for(i=0; i<size; i++)	printf("%15s ", coursenames[i]);
	printf("\n");
	for(i=0; i<size; i++)	printf("%15.2f ", grades[i]);
	printf("\n");
}	

int main(){
	//numero di studenti
	int nstudents;

	//numero di corsi
	const int ncourses=5;

	//nomi dei corsi gia definiti
	char *coursenames[]={"Mathematics", "Physics", "Programming", "Chemistry", "English"};

	//voti degli studenti: una matrice dove ogni riga rappresenta uno studente, la prima colonna rappresenta la matricola dello studente e il resto delle colonne rapresentano i corsi
	float **studentgrades;

	//voti massimi degli studenti: una matrice con 2 colonne e nstudents righe, la prima colonna contiene la matricola, la seconda il voto massimo, ogni riga corrisponde ad uno studente
	float **studentmax;

	//voti medi per ogni corso
	float *avggrades;

	//leggo il numero di studenti(nstudents>0)
	scanf("%d", &nstudents);
	if(nstudents<=0)	return 0;

	//leggo le matricole e i voti degli studenti
	studentgrades=readgrades(nstudents, ncourses);

	//calcolo i voti massimi degli studenti
	studentmax=studentmaximums(studentgrades, nstudents, ncourses);

	//stampo i voti massimi
	printf("Voti massimi:\n");
	printstudents(studentmax, nstudents, 2);

	//calcolo il voto medio per ogni corso
	avggrades=courseaverages(studentgrades, nstudents, ncourses);

	//stampo voti medi per ogni corso
	printf("Voti medi per corso:\n");
	printcourses(avggrades, coursenames, ncourses);
	
	return 0;
}
