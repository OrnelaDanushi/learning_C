/*PILA: Le liste concatenate permettono di creare facilmente altre strutture dati, come ad es: le pile. Partendo dalla definizione di Il_node data a lezione realizzare le seguenti funzioni:
-Il_node *push(Il_node *head, int v) per aggiungere in cima alla lista un nuovo nodo contenente il valore v. Restituisce il puntatore alla nuova testa
-Il_node *pop(Il_node *head) per rimuovere il nodo in cima alla lista. Restituisce il puntatore alla nuova lista (fate attenzione al caso in cui la lista sia vuota: in questo caso il metodo non deve fare nulla).
-void print(Il_node *head) per stampare il contenuto attuale della lista.
Il programma dovra' acquisire da tastiera una lista di numeri interi. L'operazione da eseguire dipende dal valore acquisito:
-se il valore e' strettamente maggiore di 0, inserisce il valore in lista mediante la funzione push;
-se il valore e' pari a 0 richiama la funzione pop;
-se il valore e' strettamente minore di 0 termina stampando il contenuto corrente della lista.
Input:	4	1	0	10	8	0	0	2	-1 Output:	2	4	*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{int info; struct Il_node_struct *next;}Il_node;
Il_node *push(Il_node *head, int v){	//aggiungere in cima un nuovo nodo
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=head;
	head=new_node;
	return head;
}
Il_node *pop(Il_node *head){	//per rimuovere il nodo piu' giovane dalla lista
	/*Il_node *succ;	//in questo modo rimuove il nodo piu' vecchio della lista
	if(head==NULL || head->next==NULL)
		return;
	succ=(head->next)->next;
	free(head->next);
	head->next=succ;
	return head;*/
	if(head==NULL)	return head;
	else{
		Il_node *corr=head->next;
		free(head);
		return corr;
	}
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}	
}
int main(){
	int n;
	Il_node *head=NULL;	
	scanf("%d",&n);	
	while(n>0 || n==0){
		if(n>0){
			head=push(head, n);
			scanf("%d",&n);
		}
		else if(n==0){
			head=pop(head);
			scanf("%d",&n);
		}			
	}
	print(head);
	return 0;
}
/*struct node{int info; struct node *next;};	//oppure
struct node *push(struct node *head, int v){
        struct node *curr=(struct node *)malloc(sizeof(struct node));
        curr->info=v;
        curr->next=head;
	head=curr;
        return head;
};
struct node *pop(struct node *head){
	if(head==NULL)	return head;
	else{
        	struct node *curr=head->next;
        	free (head);
        	return curr;
	}
};
void print(struct node *head){
	while(head!=NULL){
            printf("%d\n", head->info);
            head=head->next;
        }
}
int main(){
	struct node *head=NULL;
	int n;
	scanf("%d", &n);
	while(n>0 || n==0){
		if(n>0){
			head=push(head, n);
			scanf("%d", &n);
		}
		else{
			head=pop(head);
			scanf("%d", &n);
		}
	}
	print(head);	
	return 0;
}	*/

/*struct el{int info; struct el *next;};	//oppure non come da consegna
typedef struct el *Lista;
void push(Lista *head, int n){
	Lista new=(Lista)malloc(sizeof(struct el)), corr=*head;
	new->info=n;
	new->next=(*head);
	(*head)=new;
}	
void pop(Lista *head){
	if((*head)!=NULL){
		Lista corr=*head;
		(*head)=(*head)->next;
		free(corr);
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
		if(n!=0) push(&head, n);	
		else if(n==0)	pop(&head);
		scanf("%d", &n);	
	}
	print(head);
//	printf("\n");
	return 0;
}	*/
