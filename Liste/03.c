/* eliminare l'ultimo elemento di una lista se non e' vuota	*/

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
void deleteultimo(Lista *head){
	if((*head)!=NULL){
		Lista corr=*head, prec=NULL;
		while(corr->next!=NULL){
			prec=corr;
			corr=corr->next;
		}
		if(prec==NULL)	(*head)=NULL;	//caso di un solo elemento
		else if(prec!=NULL){
			prec->next=NULL;
			free(corr);
		}
	}
}
void deleteultimoo(Lista *head){		//oppure
	if((*head)!=NULL){
		if((*head)->next==NULL){
			free(*head);
			(*head)=NULL;
		}else if((*head)->next!=NULL){
			Lista corr=(*head)->next, prec=(*head); //prec punta inzialmente al primo elemento e corr al secondo
			while(corr->next!=NULL){
				corr=corr->next;
				prec=prec->next;
			}
			free(corr);
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
	int n;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
//	deleteultimo(&head);
	deleteultimoo(&head);
	print(head);
	return 0;
}
