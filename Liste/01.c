/* Scrivere una procedura che data in ingresso una lista di interi cancelli il primo elemento che e' preceduto e seguito da 2 elementi uguali tra loro, 
altrimenti rimane invariata.	*/

#include<stdio.h>
#include<stdlib.h>

/* //Questo modo di definire la lista non e’ del tutto corretto
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *add(Il_node *head, int v){	//inserisco l'elemento in coda, ovvero in ordine di scrittura
	Il_node *corr=head;
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else if(head!=NULL){
		while(corr->next!=NULL){ //se mettessi while(corr!=NULL) e' sbagliato perche' lo considera come while(head!=NULL)
			corr=corr->next;
		}
		corr->next=new_node;
	}
	return head;
}
void canc(Il_node *head){
	Il_node *prec=head, *corr=prec->next, *succ=corr->next; //le variabili che scandiscono la lista devono andare avanti di pari passo
	int trovato=0;
	if(head!=NULL){ //se la lista e' vuota non devo fare niente
		if(head->next!=NULL){ //controllo quando sono sicuro che esista il campo next
			while(succ!=NULL && trovato==0){
				if(prec->info==succ->info){
					trovato=1;					
					prec->next=succ; 
					free(corr); //cosi corr che non indica piu' niente viene tolto
					//oppure
/*
					trovato=1;
					prec->next=corr->next;
					prec=prec->next;
					free(corr); //se non viene tolto non e' errore ma crea garbage	
*/				
				}
				else if(prec->info!=succ->info){ //devo continuare ad andare avanti con i puntatori
					prec=corr;
					corr=succ;
					succ=corr->next;
				}
			}
		}	
	}
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%d ",head->info);
		head=head->next;
	}
}
int main(){
	Il_node *head=NULL;
	int n;
	scanf("%d",&n);
	while(n!=0){
		head=add(head,n);
		scanf("%d",&n);
	}
	canc(head);
	print(head);
	printf("\n");
	return 0;
}
*/
//Quest’altro modo di definire la lista e’ piu’ corretto
#include<stdio.h>
#include<stdlib.h>
struct Ilnode{
	int info;
	struct Ilnode *next;
}Ilnode;
typedef struct Ilnode *ListaElementi;

void add(ListaElementi *head, int v){	//inserisco l'elemento in coda, ovvero in ordine di scrittura
	ListaElementi new_node=(ListaElementi)malloc(sizeof(struct Ilnode));
	new_node->info=v;
	new_node->next=NULL;
	if((*head)==NULL){	//*head va sempre tra parentesi!!!
		new_node->next=*head;
		(*head)=new_node;
	}
	else if((*head)!=NULL){
		ListaElementi corr=*head;
		while(corr->next!=NULL){ //se mettessi while(corr!=NULL) e' sbagliato perche' lo considera come while(head!=NULL)
			corr=corr->next;
		}
		corr->next=new_node;
	}
}
void canc(ListaElementi *head){
	ListaElementi prec=*head, corr=prec->next, succ=corr->next; //le variabili che scandiscono la lista devono andare avanti di pari passo
	int trovato=0;
	if((*head)!=NULL){ //se la lista e' vuota non devo fare niente
		if((*head)->next!=NULL){ //controllo quando sono sicuro che esista il campo next
			while(succ!=NULL && trovato==0){
				if(prec->info==succ->info){
					trovato=1;					
					prec->next=succ; 
					free(corr); //cosi corr che non indica piu' niente viene tolto
					//oppure
/*
					trovato=1;
					prec->next=corr->next;
					prec=prec->next;
					free(corr); //se non viene tolto non e' errore ma crea garbage	
*/				
				}
				else if(prec->info!=succ->info){ //devo continuare ad andare avanti con i puntatori
					prec=corr;
					corr=succ;
					succ=corr->next;
				}
			}
		}	
	}
}


void print(ListaElementi head){
	while(head!=NULL){
		printf("%d ",head->info);
		head=head->next;
	}
}
int main(){
	ListaElementi head=NULL;
	int n;
	scanf("%d",&n);
	while(n!=0){
		add(&head, n);
		scanf("%d",&n);
	}
	canc(&head);
	print(head);
	printf("\n");
	return 0;
}
