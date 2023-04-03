/* Scrivere una procedura che, date due liste di interi, aggiunge alla seconda lista tutti gli elementi della prima che non appartengono anche alla seconda.	*/
#include<stdio.h>
#include<stdlib.h>
struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int val){	
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
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
void agg(Lista *head, int x){
	Lista new=(Lista)malloc(sizeof(struct el));
	new->info=x;
	new->next=(*head);
	(*head)=new;
}	
int member(Lista head, int v){
	int trovato=0;
	while(head!=NULL && trovato==0){
		if(head->info==v)	trovato=1;
		else if(head->info!=v)	head=head->next;
	}
	return trovato;
}
void aggiungi(Lista *head, Lista *head1){
	if((*head)!=NULL){
		Lista corr=*head;
		while(corr!=NULL){
			if(member(*head1, corr->info)==1)
				corr=corr->next;
			else if(member(*head1, corr->info)==0){
				//add(&(*head1), corr->info);	//aggiunge in coda i nuovi elementi
				agg(&(*head1), corr->info);	//aggiunge in testa
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
	aggiungi(&head, &head1);
	print(head1);
	printf("\n");
	return 0;
}
