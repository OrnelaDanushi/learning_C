/* Scrivere una procedura che, dati attraverso opportuni parametri una lista di interi ed un intero n, sposta in testa alla lista tutti gli elementi maggiori di n.	*/
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int val){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
	new->info=val;
	new->next=NULL;
	if((*head)==NULL){
		new->next=*head;
		(*head)=new;
	}else if((*head)!=NULL){
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=new;
	}
}
void sposta(Lista *head, int n){
	if((*head)!=NULL){
		if((*head)->next!=NULL){
			Lista prec=*head, corr=(*head)->next;
			while(corr!=NULL){
				if(corr->info>n){
					prec->next=corr->next;	
					corr->next=*head;
					(*head)=corr;
					corr=prec->next;
				}else if(corr->info<=n){
					prec=corr;
					corr=corr->next;
				}
			}
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
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &m);
	sposta(&head, m);
	print(head);
	return 0;
}
