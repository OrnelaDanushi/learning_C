/* Scrivere una procedura che, dati in ingresso, una lista di interi e un intero x, 
sposta in prima posizione l'ultima occorrenza dell'elemento x. N.B.: non e' consentito utilizzare assegnamenti sui campi info degli elementi della lista.	*/

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
int contaocc(Lista head, int x){
	int count=0;
	while(head!=NULL){
		if(head->info==x)	count++;
		head=head->next;
	}		
	return count;
}
void sposta(Lista *head, int x){
	if((*head)!=NULL){
	//per assicurarci che abbia almeno due elementi perche' se ne ha uno non facciamo niente
		if((*head)->next!=NULL && contaocc((*head), x)>0){
			int v=0;
			Lista corr=*head, prec=NULL, prev=*head;
			while(v<contaocc(*head, x) && corr->next!=NULL){
				if(corr->next->info==x)	v++;
				prec=corr;
				corr=corr->next;
			}
			(*head)=prec->next;
			prec->next=corr->next;
			corr->next=prev;
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
