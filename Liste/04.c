/* eliminare l’elemento che precede/segue la prima/ultima occorrenza di un valore	*/
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
//eliminare l'elemento di una lista che precede la prima occorrenza di x se non e' vuota
void deleteprec(Lista *head, int m){
	if((*head)!=NULL){
		Lista corr=*head, prec=NULL;
		int trovato=0;
		while(corr!=NULL && corr->next!=NULL && trovato==0){
			if(corr->next->info==m)	trovato=1;
			else if(corr->next->info!=m){
				prec=corr;
				corr=corr->next;
			}
		}
		if(trovato==1){
			if(prec==NULL){
				Lista el=*head;
				(*head)=(*head)->next;
				free(el);
			}else if(prec!=NULL){
				prec->next=corr->next;
				free(corr);
			}
		}
	}
}
//eliminare l'elemento di una lista che segue la prima occorrenza di x se non e' vuota
void deletesuc(Lista *head, int m){
	if((*head)!=NULL){
		Lista corr=*head;
		int trovato=0;
		while(corr!=NULL && corr->next!=NULL && trovato==0){
			if(corr->info==m)	trovato=1;
			else if(corr->info!=m)	corr=corr->next;
		}
		if(trovato=1 && corr->next!=NULL){
			corr->next=corr->next->next;
		}	
	}
}
//conta quante volte l’elemento m e’ presente nella lista
int contaocc(Lista head, int m){
	int count=0;
	while(head!=NULL){
		if(head->info==m)	count++;
		head=head->next;
	}	
	return count;
}
//elimino l'elemento che precede l'ultima occorrenza di x
void deleteprecorr(Lista *head, int m){
	int v=0;
	Lista corr=*head, prec=NULL;
	while(v<contaocc((*head),m) && corr->next!=NULL){
		if(corr->next->next->info==m)	v++;
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){
		Lista el=*head;
		(*head)=(*head)->next;
		free(el);
	}else if(prec!=NULL){
		prec->next=prec->next->next;
		free(corr);
	}
}
//elimino l'elemento che segue l'ultima occorrenza di x
void deletesucorr(Lista *head, int m){
	int v=0;
	Lista corr=*head, prec=NULL;
	while(v<contaocc((*head),m) && corr->next!=NULL){
		if(corr->info==m)	v++;
		prec=corr;
		corr=corr->next;
	}
	if(prec!=NULL){
		prec->next=prec->next->next;
		free(corr);
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
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &m);	
//	deleteprec(&head, m);
//	deletesuc(&head, m);
//	deleteprecorr(&head, m);
	deletesucorr(&head, m);
	print(head);
	return 0;
}
