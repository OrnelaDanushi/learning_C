/* Scrivere una procedura che cambia l'ordine degli ultimi 2 elementi di una lista data	*/
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int v){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=v;
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
void cambia(Lista *head){
	if((*head)!=NULL){	//se la lista non e' vuota
		if((*head)->next!=NULL){	//se esiste il campo next della lista
			if((*head)->next->next==NULL){	//se la lista ha solo 2 elementi
				Lista el=*head;
				(*head)->next->next=el;
				(*head)=(*head)->next;
				(*head)->next->next=NULL; 
			}else if((*head)->next->next!=NULL){	//se la lista non ha solo 2 elementi
				Lista prec=*head, corr=prec->next;
				while(corr->next->next!=NULL){
					prec=corr;
					corr=corr->next;
				}
				corr->next->next=corr;
				prec->next=corr->next;
				corr->next=NULL;
			}
		}
	}
}
void print(Lista head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}
}
int main(){
	Lista head=NULL;
	int n;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	cambia(&head);
	print(head);
	return 0;
}

