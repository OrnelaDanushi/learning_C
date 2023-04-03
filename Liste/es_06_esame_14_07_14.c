/*
Scrivere una procedura che, data una lista di interi e un valore intero positivo n, sposta in fondo alla lista i primi n elementi. Se n e' maggiore o uguale alla lunghezza della lista, essa rimane inalterata.	*/
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int v){	//inserisco l'elemento in coda, ovvero in ordine di scrittura
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=v;
	new->next=NULL;
	if((*head)==NULL){
		new->next=*head;
		(*head)=new;
	}else if((*head)!=NULL){
		while(corr->next!=NULL) //se mettessi while(corr!=NULL) e' sbagliato perche' lo considera come while(head!=NULL)
			corr=corr->next;
		corr->next=new;
	}
}
int lunghezza(Lista head){
	int conta=0;
	while(head!=NULL){
		conta++;
		head=head->next;
	}
	return conta;
}
void sposta(Lista *head, int n){
	if(n<lunghezza(*head)){
		int conta=lunghezza(*head), contael=0;
		Lista corr=*head, prec=NULL, succ=*head, prev=*head;
		while(contael<n){
			prec=corr;
			corr=corr->next;
			contael++;
		}
		if(prec!=NULL){
			while(succ->next!=NULL)
				succ=succ->next;
			succ->next=prev;
	//		printf("%+d\n", prec->info);
	//		printf("%+d\n", corr->info);
			(*head)=corr;
			prec->next=NULL;
		}
	}
}
void print(Lista head){
	while(head!=NULL){
		printf("%d\n", head->info);
		head=head->next;
	}
}
int main(){
	Lista head=NULL;
	int n, val;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &val);
	sposta(&head, val);
	print(head);
	return 0;
}
