/* Scrivere una procedura che, dati in ingresso attraverso opportuni parametri una lista di interi e un intero n, 
aggiunge n in fondo alla lista se n non `e gi`a presente in essa, lascia la lista inalterata altrimenti. */

#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int n){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=n;
	new->next=NULL;
	if((*head)==NULL){
		new->next=(*head);
		(*head)=new;
	}else if((*head)!=NULL){
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=new;
	}
}
int member(Lista head, int m){
	int trovato=0;
	while(head!=NULL && trovato==0){
		if(head->info==m)	trovato=1;
		head=head->next;
	}
	return trovato;
}
void copia(Lista *head, int m){
	if(member(*head, m)==0)	add(&(*head),m);
}
void copia1(Lista *l, int n){
	Lista prec=NULL, corr=*l;
	int trovato=0;
	while(corr!=NULL && !trovato){
		if(corr->info==n) trovato=1;
		else{
			prec=corr;
			corr=corr->next;
		}
	}
	if(!trovato){
		Lista new=(Lista)malloc(sizeof(struct el));
		new->info=n;
		new->next=NULL;
		if(prec==NULL)	*l=new;
		else	prec->next=new;
	}
}
void print(Lista head){
	while(head!=NULL){
		printf("%d ", head->info);
		head=head->next;
	}
}
int main(){
	Lista head=NULL;
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &m);
	print(head);
	printf("\n");
//	copia(&head, m);
	copia1(&head, m);
	print(head);
	printf("\n");
	return 0;
}
