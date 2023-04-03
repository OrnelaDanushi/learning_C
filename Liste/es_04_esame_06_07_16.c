/* opp ES 4 ESAME 3/06/15: 
Scrivere una procedura che, data una lista di interi a ed un intero n, cancella dalla lista i primi n elementi maggiori di 0.	*/
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
void canc(Lista *head, int n){
	if((*head)!=NULL){
		Lista prec=NULL, corr=*head;
		while(corr!=NULL && n>0){
			if(corr->info>0){
				if(prec==NULL){
					(*head)=(*head)->next;
					free(corr);
					corr=(*head);
				}else if(prec!=NULL){
					prec->next=corr->next;
					free(corr);
					corr=prec->next;
				}
				n--;
			}else if(corr->info<0){
				prec=corr;
				corr=corr->next;
			}
		}
	}
}
void print(Lista head){
	while(head!=NULL){
		printf("%d ",head->info);
		head=head->next;
	}
}
int main(){
	Lista head=NULL;
	int n, m;
	scanf("%d", &n);
	while(n!=-100){
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
