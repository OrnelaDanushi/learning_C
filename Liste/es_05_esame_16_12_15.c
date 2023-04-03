/* Scrivere una procedura che, data in ingresso una lista di interi, porta in ultima posizione il primo elemento negativo che compare nella lista. 
La procedura lascia la lista inalterata se in essa non occorre alcun elemento negativo.	*/

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
void spostaneg(Lista *head){
	if((*head)!=NULL){
		Lista prec=NULL, corr=*head, prev=*head;
		int trovato=0;
		while(corr!=NULL && corr->next!=NULL && trovato==0){
			if(corr->info<0)	trovato=1;
			else if(corr->info>=0){
				prec=corr;
				corr=corr->next;
			}
		}
		if(trovato==1){
			while(prev->next!=NULL){
				prev=prev->next;
			}
			if(prec==NULL){
				(*head)=(*head)->next;
				prev->next=corr;
				corr->next=NULL;
			}else if(prec!=NULL){
				prec->next=corr->next;
				prev->next=corr;
				corr->next=NULL;
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
	int n;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	spostaneg(&head);
	print(head);	
	return 0;
}
