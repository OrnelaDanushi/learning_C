/* Scrivere una procedura che sposti in ultima posizione il primo elemento di una lista di interi maggiore di un valore dato, 
supponiamo che esista sempre uno maggiore.	*/

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
void sposta(Lista *head, int x){
	if((*head)!=NULL){	//se la lista e' vuota non si fa nulla
		if((*head)->next!=NULL){	//se c'e' l'elemento successivo
			Lista prec=NULL, corr=*head, succ=corr->next;
			if((*head)->info>x){
				while(corr->next!=NULL)
					corr=corr->next;	//scorro la lista per arrivare fino in fondo
				corr->next=*head; //posiziono il primo nodo maggiore in fondo
				(*head)=(*head)->next; //e il puntatore head diventa il secondo elemento
				corr->next->next=NULL;
			}else if((*head)->info<=x){
				if((*head)->next!=NULL)
					sposta(&(*head)->next, x);	
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
	int n, x;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &x);
	sposta(&head, x);
	print(head);
	return 0;
}
