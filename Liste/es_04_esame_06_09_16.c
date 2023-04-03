/* Scrivere una procedura che, presa attraverso un opportuno parametro una lista di almeno 3 elementi, 
scambia le posizioni del primo e del penultimo elemento, senza utilizzare assegnamenti sui campi info delle strutture che compongono la lista. */
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int e){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=e;
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
/*
void scambia(Lista *head){
	if((*head)!=NULL && (*head)->next!=NULL && (*head)->next->next!=NULL){
		Lista primo=*head, corr=*head, prec=NULL;
		while(corr->next->next!=NULL){
			prec=corr;
			corr=corr->next;
		}
		if(prec==(*head)){
			primo=corr;
			(*head)->next=corr->next;
			corr->next=(*head);
			(*head)=primo;
		}
		else if(prec!=(*head)){
		//mossa poco corretta
			int a=(*head)->info, b=corr->info;
			(*head)->info=b;
			corr->info=a;
		}
	}	
}	*/
void scambia(Lista *head){
	if((*head)!=NULL && (*head)->next!=NULL && (*head)->next->next!=NULL){
		Lista terzultimo=*head, penultimo=(*head)->next, ultimo=(*head)->next->next;
		while(ultimo->next!=NULL){
			terzultimo=penultimo;
			penultimo=ultimo;
			ultimo=ultimo->next;
		}
	//	printf("terzultimo%+d",terzultimo->info);
	//	printf("penultimo%+d",penultimo->info);
	//	printf("ultimo%+d",ultimo->info);
		terzultimo->next=(*head);
		penultimo->next=(*head)->next;
		(*head)->next=ultimo;
		(*head)=penultimo;
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
	int i;
	scanf("%d", &i);
	while(i!=0){
		add(&head, i);
		scanf("%d", &i);
	}
	print(head);
	printf("\n");
	scambia(&head);
	print(head);
	printf("\n");
	return 0;
}
