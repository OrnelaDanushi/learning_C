/*Si implementi una lista concatenata che contenga, come dati, interi positivi. Si implementino anche tre funzioni per:
_aggiungere un elemento in fondo alla lista
_aggiungere un elemento in cima alla lista
_dato un valore positivo v, eliminare la prima occorrenza di v nella lista (non modificare la lista nel caso che non contenga v)
Quindi scrivere un programma che legga degli interi. Per ogni interi letto (e nello stesso ordine dell'input) si applichi una delle seguenti modifiche:
_se il valore letto v e' strettamente negativo, rimuovere il primo elemento uguale a |v| dalla lista (non modificare la lista nel caso che questa non contenga |v|)
_se il valore letto v e' positivo e pari, aggiungerlo in cima alla lista
_se il valore letto v e' positivo e dispari, aggiungerlo in fondo alla lista
_se il valore letto e' 0, terminare l'esecuzione del programma stampando, in ordine, gli elmenti della lista.
input: 4	5	2	-4	-5	-3	9	2	0	
output:	2	2	9	*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *addf(Il_node *head, int v){
	Il_node *corr=head;	
	Il_node *new_node=malloc(sizeof(Il_node));	
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else{
		while(corr->next!=NULL){
			corr=corr->next;
		}
		corr->next=new_node;
	}
	return head;
}
Il_node *addc(Il_node *head, int v){
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=head;
	head=new_node;
	return head;	
}
Il_node *elim(Il_node *head,int v){
	Il_node *prec=NULL, *corr=head;
	int trovato=0;
	while(corr!=NULL && trovato==0){
		if(corr->info==v)
			trovato=1;
		else{
			prec=corr;	//avanzo con i puntatori fino a che trovo la prima occorrenza di v
			corr=corr->next;
		}
	}
	if(trovato==1){
		if(prec==NULL){
			head=corr->next;
			free(corr);
		}
		else if(prec!=NULL){
			prec->next=corr->next;
			free(corr);
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
	int n,t;
	scanf("%d",&n);
	while(n!=0){
		if(n<0){
			t=n*(-1);	//altrimenti non elimina quelli di segno positivo!
			head=elim(head,t);
			scanf("%d",&n);
		}	
		if(n>0 && n%2==0){
			head=addc(head,n);
			scanf("%d",&n);	
		}
		else if(n>0 && n%2!=0){
			head=addf(head,n);
			scanf("%d",&n);
		}
	}
	print(head);
	return 0;
}

/*oppure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;

void addtesta(Lista *head, int n){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
	new->info=n;
	new->next=(*head);
	(*head)=new;
}	

void addfondo(Lista *head, int n){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
	new->info=n;
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
void delete(Lista *head, int n){
	if((*head)!=NULL){
		Lista corr=*head, prev=NULL;
		int trovato;
		while(corr!=NULL && trovato==0){
			if(corr->info==abs(n))	trovato=1;
			else if(corr->info!=n){	
				prev=corr;
				corr=corr->next;	
			}
		}
		if(trovato==1){
			if(prev==NULL){
				(*head)=(*head)->next;
				free(corr);
			}else if(prev!=NULL){
				prev->next=prev->next->next;
				free(corr);
			}
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
	int n;
	scanf("%d", &n);
	while(n!=0){
		if(n<0)	delete(&head, n);
		else if(n>0){
			if(n%2==0) addtesta(&head, n);
			else if(n%2!=0)	addfondo(&head, n);
		}	
		scanf("%d", &n);	
	}
	print(head);
//	printf("\n");
	return 0;
}	*/
