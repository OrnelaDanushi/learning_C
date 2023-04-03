/* Scrivere una procedura che, date due liste di interi, elimina dalla seconda lista tutti gli elementi che non occorrono anche nella prima. */
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
int member(Lista head, int val){
	int trovato=0;
	while(head!=NULL && trovato==0){
		if(head->info==val)	trovato=1;
		else	head=head->next;
	}
	return trovato;
}
void elimina(Lista *head, Lista *head1){
	if(head1!=NULL){
		Lista prec=NULL, corr=*head1;
		while(corr!=NULL){
			if(member(*head, corr->info)==1){
				prec=corr;
				corr=corr->next;
			}else{
				if(prec==NULL){
					(*head1)=(*head1)->next;
					free(corr);
					corr=(*head1);
				}else{
					prec->next=corr->next;
					free(corr);
					corr=prec->next;
				}
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
	elimina(&head, &head1);
	//print(head);
	print(head1);
	printf("\n");
	return 0;
}
