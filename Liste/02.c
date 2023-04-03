/* eliminare il primo elemento in testa ad una lista	*/
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

//con questa versione si crea garbage, c'e' bisogno di liberare la memoria
void deleteprimo(Lista *head){
	if((*head)!=NULL){
		if((*head)->next==NULL)	(*head)=NULL;
		else if((*head)->next!=NULL){
			(*head)=(*head)->next;
		}
	}
}
//questa versione e' ancora meglio
void deleteprimocorretto(Lista *head){
	if((*head)!=NULL){
		Lista el=*head;
		(*head)=(*head)->next;
		free(el);
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
//	deleteprimo(&head);
	deleteprimocorretto(&head);
	print(head);
	return 0;
}
