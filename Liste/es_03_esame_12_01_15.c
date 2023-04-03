/* Scrivere una procedura che, data una lista di interi in cui tutti gli elementi con valore pari precedono tutti gli elementi con valore dispari, e dato un intero n, inserisce n nella lista in modo che anche nella lista risultante tutti gli elementi con valore pari precedano tutti gli elementi con valore dispari. HINT: Inserire l'elemento in testa alla lista se e' pari oppure la lista e' vuota, altrimenti inserirlo in fondo.	*/
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
void inserisci(Lista *head, int n){	//soluzione del prof.
	Lista new=(Lista)malloc(sizeof(struct el)), prec=NULL, corr=*head;
	new->info=n;
	new->next=NULL;
	if(n%2==0 || (*head)==NULL){
		new->next=(*head);
		(*head)=new;
	}else if(n%2!=0 || (*head)!=NULL){
		while(corr!=NULL){
			prec=corr;
			corr=corr->next;
		}//all'uscita dal ciclo corr=NULL e prec e' l'ultimo elemento
		prec->next=new;
/* //oppure	
		while(corr->next!=NULL)		//si esce dal ciclo con corr che e' l'ultimo elemento
			corr=corr->next;
		corr->next=new;
*/
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
	inserisci(&head, m);
	print(head);
	printf("\n");
	return 0;
}
