/* Scrivere una procedura che, dato una lista di interi e un valore x, elimina, se esiste, il primo elemento della lista seguito da un elemento che contiene x.	*/

#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int val){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=val;
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
void canc(Lista *head, int x){
	if((*head)!=NULL){
		if((*head)->next!=NULL){
			int trovato=0;
			Lista corr=*head;
			while(corr!=NULL && corr->next!=NULL && trovato==0){	
				if(corr->info==x)	trovato=1;
				else if(corr->info!=x)	corr=corr->next;
			}
			if(trovato==1){
				if(corr->next!=NULL){
					Lista prev=corr->next;
					corr->next=corr->next->next;	
					free(prev);		
				}
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
	canc(&head, m);
	print(head);
	printf("\n");
	return 0;
}
