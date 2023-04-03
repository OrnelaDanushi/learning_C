/* Scrivere una procedura che, dati in ingresso attraverso opportuni parametri una lista di interi e un intero x, 
elimina dalla lista l’ultimo elemento maggiore di x. 
Se nessun elemento della lista `e maggiore di x, la procedura elimina, se esiste, l’ultimo elemento della lista.	*/

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

int contamaggiori(Lista head, int x){
	int count=0, lengh=0;
	while(head!=NULL){
		if(head->info>x)	count++;
		lengh++;
		head=head->next;
	}
	if(lengh==count)	return 0;
	return count;
}
void delete(Lista *head, int x){
	if(*head!=NULL){	//questa condizione e' fondamentale
		Lista corr=*head, prec=NULL, preprec=NULL;
	//	printf("conta%d\n",contamaggiori(*head, x));
		if(contamaggiori(*head, x)!=0){
			int v=0;	
			while(v<contamaggiori(*head, x)){
				if(corr->info>x)	v++;
				preprec=prec;
				prec=corr;
				corr=corr->next;
			}
		//	printf("corr%d\n",corr->info);
		//	printf("v%d\n",v);
			if(preprec==NULL){
				(*head)=(*head)->next;
				free(prec);
			}else if(preprec!=NULL){
				if(corr!=NULL){
					preprec->next=preprec->next->next;
					free(prec);
				}else if(corr==NULL)	preprec->next=NULL;
			}
		}else if(contamaggiori(*head, x)==0){
			while(corr->next!=NULL){
				prec=corr;
				corr=corr->next;
			}
			if(prec!=NULL){
				prec->next=NULL;
				free(corr);
			}else if(prec==NULL)
				(*head)=NULL;
		}
	}
}
void delete1(Lista *l, int x){	//soluzione del prof
	if(*l!=NULL){
		Lista corr=*l, prec=NULL, prec_prec=NULL, prec_ultimo=NULL;
		int trovato=0;
		while(corr!=NULL){
			if(corr->info>x){
				trovato=1; 
				prec_ultimo=prec;
			}
			prec_prec=prec;
			prec=corr;
			corr=corr->next;
		}
		if(trovato)
			if(prec_ultimo==NULL){
				corr=*l;
				*l=(*l)->next; 
				free(corr);
			}else{
				corr=prec_ultimo->next; 
				prec_ultimo->next=corr->next; 
				free(corr);
			}
		else
			if(prec_prec==NULL){
				corr=*l; 
				*l=(*l)->next; 
				free(corr);
			}else{
				corr=prec_prec->next; 
				prec_prec->next=NULL; 
				free(corr);
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
	int n, x;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &x);
	print(head);
	printf("\n");
//	delete(&head, x);
	delete1(&head, x);
	print(head);
	printf("\n");
	return 0;
}

/*oppure 
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
int contamaggiori(Lista head, int x){
	int count=0, lengh=0;
	while(head!=NULL){
		if(head->info>x)	count++;
		lengh++;
		head=head->next;
	}
	if(lengh==count)	return 0;
	return count;
}
void delete(Lista *head, int x){
	if(*head!=NULL){	//questa condizione e' fondamentale
		Lista corr=*head, prec=NULL, preprec=NULL;
	//	printf("conta%d\n",contamaggiori(*head, x));
		if(contamaggiori(*head, x)!=0){
			int v=0;	
			while(v<contamaggiori(*head, x)){
				if(corr->info>x)	v++;
				preprec=prec;
				prec=corr;
				corr=corr->next;
			}
		//	printf("corr%d\n",corr->info);
		//	printf("v%d\n",v);
			if(preprec==NULL){
				(*head)=(*head)->next;
				free(prec);
			}else if(preprec!=NULL){
				if(corr!=NULL){
					preprec->next=preprec->next->next;
					free(prec);
				}else if(corr==NULL)	preprec->next=NULL;
			}
		}else if(contamaggiori(*head, x)==0){
			while(corr->next!=NULL){
				prec=corr;
				corr=corr->next;
			}
			if(prec!=NULL){
				prec->next=NULL;
				free(corr);
			}else if(prec==NULL)
				(*head)=NULL;
		}
	}
}
void delete1(Lista *l, int x){	//soluzione del prof
	if(*l!=NULL){
		Lista corr=*l, prec=NULL, prec_prec=NULL, prec_ultimo=NULL;
		int trovato=0;
		while(corr!=NULL){
			if(corr->info>x){
				trovato=1; 
				prec_ultimo=prec;
			}
			prec_prec=prec;
			prec=corr;
			corr=corr->next;
		}
		if(trovato)
			if(prec_ultimo==NULL){
				corr=*l;
				*l=(*l)->next; 
				free(corr);
			}else{
				corr=prec_ultimo->next; 
				prec_ultimo->next=corr->next; 
				free(corr);
			}
		else
			if(prec_prec==NULL){
				corr=*l; 
				*l=(*l)->next; 
				free(corr);
			}else{
				corr=prec_prec->next; 
				prec_prec->next=NULL; 
				free(corr);
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
	int n, x;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &x);
	print(head);
	printf("\n");
//	delete(&head, x);
	delete1(&head, x);
	print(head);
	printf("\n");
	return 0;
}
	*/
