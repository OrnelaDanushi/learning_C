/*Si realizzi un programma che legga da tastiera un intero n e successivamente n parole (una per riga). Il programma deve poi stampare prima tutte le parole palindrome (nell'ordine in cui sono state lette) e successivamente tutte le restanti parole (sempre in ordine di apparizione). N.B Ogni singola parola e' lunga al piu' 40 caratteri, e per allocare dinamicamente un array di stringhe dobbiamo prima allocare un array di char*, e per ciascuna posizione dell'array, dobbiamo allocare lo spazio sufficiente per mantenere una stringa.
input:	5	anna	prova	otto	ingegni	ciao
output:	anna	otto	ingegni	prova	ciao	*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
#define MAXLEN 1000
typedef struct Il_node_struct{		//non funziona se fatto con le liste
	char *info;
	struct Il_node_struct *next;
}Il_node;
Il_node *insert(Il_node *head, char v[]){ //per inserire un el. in coda scorriamo l’intera lista
	Il_node *corr=head;
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL) //se la lista e’ vuota, gestire sempre con attenzione il caso della 
		return new_node;	//lista vuota
	while(corr->next!=NULL) //scorriamo la lista fino a trovarne il nodo con il campo next
		corr=corr->next; //cosi vado avanti con i nodi
	corr->next=new_node; //alla fine l’ultimo nodo a cui arrivo e’ l’ultimo
	return head; //ritorna il puntatore al nodo head che restituisce la nuova lista
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%s\n",head->info);
		head=head->next;
	}
}	*/
int palindroma(char str[]){
	int i=0, j=0, trovato=0;
	char str2[strlen(str)];
	i=strlen(str)-2;
	do{
		for(j=0; j<strlen(str); j++){
			str2[j]=str[i];
			i--;
		}
		
	}while(i>=0);
	i=0;
	while(i<=strlen(str)-2 && trovato==0){
		if(str[i]!=str2[i])
			trovato=1;
		else
			i++;
	}	
	return trovato;		
}
/*
void **Make_Array(int space){	//Crea un'array di puntatori, che puntano a delle stringhe
	Il_node *head1=NULL,*head2=NULL;
	int i;
	char **array=(char**)malloc(space*sizeof(char*));
	for(i=0; i<space+1; i++){
      		array[i]=(char*)malloc(40*sizeof(char));
      		fgets(array[i],40,stdin);
		if(palindroma(array[i])==0){	
			head1=insert(head1,array[i]);
		}
		else if(palindroma(array[i])==1){
			head2=insert(head2,array[i]);
		}
   	}
	print(head1);
	print(head2);
}	*/	
int main(){
	int space,i=0,j=1,ctr,z,c;
	scanf("%d\n",&space);
	char **array;
	//Make_Array(space);
	/*int i=0, j=0;
	for(i=0; i<space+1; i++){
		printf("%s",array[i]);
	}*/
	//First_Palindrome(array,space);
	//Destroy_Array(space,array);
	array=(char**)malloc(space*sizeof(char*));
	while(i<space){
		array[i]=malloc(40*sizeof(char));
		fgets(array[i], 40, stdin);
		i++;
	}
	i=0;
	char *sup;
	while(j<space){
		//se al posto di 0 metto 1 e al posto di 1 metto 0 stampa prima le non palindrome e poi le palindrome
		if(palindroma(array[i])==0){
			i++;
			j++;
		}
		else{
			if(palindroma(array[i])==1 && palindroma(array[j])==1)
				j++;
			else if(palindroma(array[i])==1 && palindroma(array[j])==0){
				z=j-i;
				c=j;
				while(z>0){
					sup=array[c];
					array[c]=array[c-1];
					array[c-1]=sup;
					c--;
					z--;
				}
				j++;
				i++;
			}
		}
	}
	i=0;
	while(i<space){
		printf("%s",array[i]);
		i++;
	}
	return 0;
}
