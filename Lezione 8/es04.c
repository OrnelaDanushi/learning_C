/*Scrivere un programma che acquisisca da tastiera 2 successioni di interi positivi, 
entrambe terminate da un numero negativo, e le inserisca in 2 liste distinte. 
Realizzare poi una funzione che, prese in input le 2 liste, restituisca una nuova lista contenente l'intersezione ordinata 
tra le due: non vi devono quindi essere elementi ripetuti e i valori devono essere memorizzati in ordine crescente. 
Si stampi il contenuto della lista intersezione. N.B. si possono organizzare le 2 liste in input come meglio si ritiene necessario.
input:	4	5	6	7	-1	10	9	7	6	5	-1
output:	5	6	7	*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *aggordinati(Il_node *head, int v){	//aggiunge gli elementi in maniera ordinata e senza duplicati per agevolare la ricerca
	Il_node *prec=NULL, *corr=head;			//degli elementi intersezione
	int trovato=0, dupli=0;
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else if(head!=NULL){
		while(corr!=NULL && trovato==0 && dupli==0){
			if(corr->info>v){
				trovato=1;
			}
			else{
				if(corr->info==v)
					dupli=1;
				else if(corr->info<v){
					prec=corr;
					corr=corr->next;
				}
			}
		}
		if(trovato==1){
			if(prec!=NULL){
				new_node->next=corr;
				prec->next=new_node;
			}
			else if(prec==NULL){
				new_node->next=corr;
				head=new_node;
			}
		}
		else if(trovato==0 && dupli==0){
			new_node->next=corr;
			prec->next=new_node;
		}
	}
	return head;
}
Il_node *interseca(Il_node *head1, Il_node *head2){
	Il_node *head3=NULL, *corr1=head1, *corr2=head2;
	if((head1==NULL || head2==NULL))
		return NULL;
	else{
		while(corr1!=NULL && corr2!=NULL){
			if(corr1->info==corr2->info){
				head3=aggordinati(head3,corr1->info);
				corr1=corr1->next;
				corr2=corr2->next;
			}
			else{
				if(corr1->info<corr2->info)
					corr1=corr1->next;
				else if(corr1->info>corr2->info)
					corr2=corr2->next;
			}			
		}
		return head3;
	}
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}
}
int main(){
	Il_node *head1=NULL,*head2=NULL,*head=NULL;
	int n,m;
	scanf("%d",&n);
	while(n>0){
		head1=aggordinati(head1,n);
		scanf("%d",&n);
	}
	scanf("%d",&m);
	while(m>0){
		head2=aggordinati(head2,m);
		scanf("%d",&m);
	}
	head=interseca(head1,head2);
	print(head);
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;

void add(Lista *head, int n){
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
		}if(trovato==1){
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

int conta(Lista head, int n, int init){
	Lista corr=head, prev=NULL;
	int i=1, conta=0;
	while(i<init){
		corr=corr->next;
		i++;	
	}prev=corr;
	while(prev!=NULL){
		if(prev->info==n)	conta++;
		prev=prev->next;
	}
	return conta;
}

int trova(Lista head, int n){
	int trovato=0;
	while(head!=NULL && trovato==0){
		if(head->info==n)	trovato=1;
		head=head->next;
	}
	return trovato;
}

void intersezione(Lista *head2, Lista *head1, Lista *head){
	if((*head)!=NULL){
		Lista corr=*head;
		int inizio=1;
		while(corr!=NULL){
			if((conta((*head), corr->info, inizio)==1)&&(trova((*head1), corr->info)==1))	add(&(*head2), corr->info);
			inizio++;
			corr=corr->next;
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
	Lista head=NULL, head1=NULL, head2=NULL;
	int n, m;
	scanf("%d", &n);
	while(n>=0){
		add(&head, n);
		scanf("%d", &n);	
	}
	scanf("%d", &m);
	while(m>=0){
		add(&head1, m);
		scanf("%d", &m);	
	}
	intersezione(&head2, &head1, &head);
	print(head2);
//	printf("\n");
//	print(head);
//	printf("\n");
//	print(head1);	
	return 0;
}	*/
