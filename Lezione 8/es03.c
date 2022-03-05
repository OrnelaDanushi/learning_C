/*Scrivere un programma che acquisisca da tastiera una successione di numeri interi positivi e li inserisca in maniera ordinata (crescente) all'interno di una lista. La lista puo' contenere duplicati. L'acquisizione da tastiera termina quando si incontra il primo valore negativo (che non va inserito in lista) e viene stampato il contenuto corrente della lista.
input:	4	5	7	1	2	6	9	10	-1
output:	1	2	4	5	6	7	9	10	*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *ordina(Il_node *head, int v){
	Il_node *new_node=malloc(sizeof(Il_node));
	Il_node *prec=NULL, *corr=head;
	int trovato=0;
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else if(head!=NULL){
		while(corr!=NULL && trovato==0){
			if(corr->info>=v){
				trovato=1;		
			}else if(corr->info<v){
				prec=corr;
				corr=corr->next;
			}
		}
		if(trovato==1){
			new_node->next=corr;
			if(prec!=NULL){
				prec->next=new_node;
			}
			else if(prec==NULL){
				head=new_node;
			}
		}
		else if(trovato==0){
			if(prec!=NULL){
				prec->next=new_node;
			}
			else if(prec==NULL){
				head=new_node;
			}
		}		
	}
	return head;	
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}
}
int main(){
	Il_node *head=NULL;
	int n;
	scanf("%d",&n);
	while(n>0){
		head=ordina(head,n);
		scanf("%d",&n);
	}
	print(head);
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;

void addordine(Lista *head, int n){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head, prev=NULL;
	new->info=n;
	new->next=NULL;
	if((*head)==NULL){
		new->next=(*head);
		(*head)=new;
	}else if((*head)!=NULL){
		int trovato=0;
		while(corr!=NULL && trovato==0){
			if(corr->info<n){
				prev=corr;
				corr=corr->next;
			}else if(corr->info>=n)	trovato=1;
		}
		if(trovato==1){
			if(prev==NULL){
				new->next=(*head);
				(*head)=new;
			}else if(prev!=NULL){
				new->next=corr;
				prev->next=new;
			}
		}else if(trovato==0)	prev->next=new;
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
	int n;
	scanf("%d", &n);
	while(n>=0){
		addordine(&head, n);
		scanf("%d", &n);	
	}
	print(head);
//	printf("\n");
	return 0;
}	*/
