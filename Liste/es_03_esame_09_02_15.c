/* (perche’ funziona la prima procedura?)
Scrivere una procedura che, data una lista di interi ed un intero n, cancella dalla lista, se c'e', l'ultimo elemento che contiene n.*/
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
void canc(Lista *head, int n){
	Lista prec=NULL, corr=*head, save=NULL;
	int trovato=0;
	if((*head)!=NULL){
		while(corr!=NULL){
			if(corr->info==n){
				save=prec;
				trovato=1;
			}	
			prec=corr; 
			corr=corr->next;
		}
		if(trovato==1){
			if(save==NULL){
				corr=(*head);
				(*head)=(*head)->next;
			}else if(save!=NULL){
				corr=save->next;
				save->next=save->next->next;									
			}
			free(corr);
		}
	}
}
/*	//oppure
int contaocc(Lista head, int n){
	int count=0;
	while(head!=NULL){
		if(head->info==n)	count++;
		head=head->next;
	}
	return count;
}
void canc(Lista *head, int n){
	if((*head)!=NULL){
		int v=0;
//se non mettessi l'if comprendente l'if-else dopo il while eliminereri in ogni caso il primo elemento della lista
		if(contaocc(*head, n)>0){	
			Lista prec=NULL, preprec=NULL, corr=*head;
			while(v<contaocc(*head, n)){
				if(corr->info==n)	v++;
				preprec=prec;
				prec=corr;
				corr=corr->next;
			}
			if(preprec==NULL){
				(*head)=(*head)->next;
				free(prec);
			}else if(preprec!=NULL){
				preprec->next=preprec->next->next;
				free(preprec);
			}
		}
	}
}	*/
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
	while(n!=0){
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
