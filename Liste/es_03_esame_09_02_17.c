/* Scrivere una procedura che, presi una lista e un numero naturale n, elimina gli ultimi n elementi della lista 
e inserisce in coda (al loro posto) un nuovo elemento il cui valore e' pari alla somma dei valori contenuti negli elementi rimossi. 
Se la lista contiene meno di n elementi, l'operazione viene eseguita usando tutti gli elementi contenuti nella lista. 
Se nessun elemento viene rimosso (perche' n=0 o perche' la lista e' vuota) si dovra' comunque inserire in coda un nuovo elemento contenente il valore 0.	*/

#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int x){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
	new->info=x;
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
int length(Lista head){
	int conta=0;
	while(head!=NULL){
		conta++;
		head=head->next;
	}
	return conta;
}
void delete(Lista *head, int n){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head, prev=NULL, corrcopia=NULL;
	new->info=0;
	new->next=NULL;
	if((*head)==NULL)	(*head)=new;
	else if((*head)!=NULL){
		if(n==0){
			while(corr->next!=NULL)
				corr=corr->next;
			corr->next=new;
		}else if(n!=0){
			if(n>=length(*head)){
				while(corr!=NULL){
					new->info=new->info+corr->info;
					corr=corr->next;
				}
				free(*head);
				(*head)=new;
			}else if(n<length(*head)){
				int diff=length(*head)-n, i=0;
				while(i<diff){
					prev=corr;
					corr=corr->next;
					i++;
				}corrcopia=corr;
				while(corr!=NULL){
					new->info=new->info+corr->info;
					corr=corr->next;
				}prev->next=new;
				free(corrcopia);
			}
		}
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
	delete(&head, m);
	print(head);
	printf("\n");
	return 0;
}

