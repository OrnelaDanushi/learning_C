/* Scrivere una procedura che, prese due liste di interi cancella dalla prima tutti gli elementi che non compaiono nella seconda.	*/
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int v){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
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
int member(Lista head1, int val){
	int trovato=0;	
	while(head1!=NULL && trovato==0){
		if(head1->info==val)	trovato=1;
		else if(head1->info!=val)	head1=head1->next;
	}
	return trovato;
}
void canc(Lista *head, Lista *head1){
	if((*head)!=NULL || (*head1)!=NULL){
		Lista prec=NULL, corr=*head;
		while(corr!=NULL){
			if(member(*head1, corr->info)==0){
				if(prec==NULL){
					(*head)=(*head)->next;
					free(corr);
					corr=(*head);
				}else if(prec!=NULL){
					prec->next=corr->next;
					free(corr);
					corr=prec->next;	
				}
			}else if(member(*head1, corr->info)==1){
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
	Lista head=NULL, head1=NULL;
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}	
	scanf("%d", &m);
	while(m!=0){
		add(&head1, m);
		scanf("%d", &m);
	}
	print(head);
	printf("\n");
	print(head1);
	printf("\n");
	canc(&head, &head1);
	print(head);
	printf("\n");
	return 0;
}
