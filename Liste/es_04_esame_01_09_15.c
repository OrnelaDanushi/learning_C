/* Scrivere una procedura che data una lista di interi, antepone ad ogni elemento negativo 0, se non ci sono elementi negativi, la lista deve rimanere inalterata. 

//se sfruttiamo la lista nella modalita’ sbagliata, questa procedura non funziona per il caso in cui il primo elemento della lista sia negativo.
#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *add(Il_node *head, int v){
	Il_node *corr=head;
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else if(head!=NULL){
		while(corr->next!=NULL){
			corr=corr->next;
		}
		corr->next=new_node;
	}
	return head;
}
//questa procedura non funziona per il primo elemento se negativo
void zero(Il_node *head){
	Il_node *prec, *corr;
	if(head!=NULL){	//dobbiamo assicurarci che la lista non sia vuota
		if(head->info<0){	//per il primo elemento della lista negativo
			Il_node *new_node=malloc(sizeof(Il_node));
			new_node->info=0;
			new_node->next=head;	//questo non puo' essere fatto con l'ordine inverso con quello che segue
			head=new_node;
			prec=head->next; //avanzo dal primo elemento che ho aggiunto essere zero
			corr=prec->next;
		}
		else if(head->info>0){	//per il primo elemento della lista positivo
			prec=head;	//avanzo dal primo elemento della lista
			corr=prec->next;
		}
		while(corr!=NULL){
			if(corr->info<0){
				Il_node *new_node=malloc(sizeof(Il_node));
				new_node->info=0;
				new_node->next=corr;
				prec->next=new_node;
				prec=corr;	//dopo aver aggiunto il nodo zero avanzo con i puntatori di scorrimento
				corr=corr->next;
			}
			else if(corr->info>0){
				prec=corr;
				corr=corr->next;
			}
		}
	}
}
int main(){
	Il_node *head=NULL;
	int n, x;
	scanf("%d",&n);
	while(n!=0){
		head=add(head,n);
		scanf("%d",&n);		
	}
	zero(head);
	print(head);
	return 0;
}

//se invece usiamo la modalita’ di definizione corretta della lista, tale procedura funziona.
#include<stdio.h>
#include<stdlib.h>
struct el{
	int info;
	struct el *next;
}el;
typedef struct el *Lista;
void add(Lista *head, int v){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=v;
	new->next=NULL;
	if((*head)==NULL){
		new->next=*head;
		(*head)=new;
	}else if((*head)!=NULL){
		while(corr->next!=NULL){
			corr=corr->next;
		}
		corr->next=new;
	}
}
void zero(Lista *head){
	Lista prec, corr;
	if((*head)!=NULL){	//dobbiamo assicurarci che la lista non sia vuota
		if((*head)->info<0){	//per il primo elemento della lista negativo
			Lista new=(Lista)malloc(sizeof(struct el));
			new->info=0;
			new->next=*head;	//questo non puo' essere fatto con l'ordine inverso con quello che segue
			(*head)=new;
			prec=(*head)->next; //avanzo dal primo elemento che ho aggiunto essere zero
			corr=prec->next;
		}else if((*head)->info>0){	//per il primo elemento della lista positivo
			prec=*head;	//avanzo dal primo elemento della lista
			corr=prec->next;
		}
		while(corr!=NULL){	//se facessi while(corr->next!=NULL){	mi salterebbe l'ultimo elemento
			if(corr->info<0){
				Lista new=(Lista)malloc(sizeof(struct el));
				new->info=0;
				new->next=corr;
				prec->next=new;
				prec=corr;	//dopo aver aggiunto il nodo zero avanzo con i puntatori di scorrimento
				corr=corr->next;
			}
			else if(corr->info>0){
				prec=corr;
				corr=corr->next;
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
	int n, x;
	scanf("%d", &n);
	while(n!=0){
		add(&head,n);
		scanf("%d", &n);		
	}
	zero(&head);
	print(head);
	return 0;
}

//..VARIANTE: Scrivere una procedura che data una lista di interi e un intero x, aggiunge un elemento che contiene x prima di ogni elemento negativo presente nella lista. Se non ci sono elementi negativi, la lista deve rimanere inalterata.
Anche qui, se usiamo il modo sbagliato di definire la lista, la procedura non funziona per il primo elemento se negativo.
#include<stdio.h>
#include<stdlib.h>
typedef struct Il_node_struct{
	int info;
	struct Il_node_struct *next;
}Il_node;
Il_node *add(Il_node *head, int v){
	Il_node *corr=head;
	Il_node *new_node=malloc(sizeof(Il_node));
	new_node->info=v;
	new_node->next=NULL;
	if(head==NULL){
		new_node->next=head;
		head=new_node;
	}
	else if(head!=NULL){
		while(corr->next!=NULL){
			corr=corr->next;
		}
		corr->next=new_node;
	}
	return head;
}
void variante(Il_node *head, int x){
	Il_node *prec, *corr;
	if(head!=NULL){	//dobbiamo assicurarci che la lista non sia vuota
		if(head->info<0){	//per il primo elemento della lista negativo
			Il_node *new_node=malloc(sizeof(Il_node));
			new_node->info=x;
			new_node->next=head;	//questo non puo' essere fatto con l'ordine inverso con quello che segue
			head=new_node;
			prec=head->next; //avanzo dal primo elemento che ho aggiunto essere zero
			corr=prec->next;
		}
		else if(head->info>0){	//per il primo elemento della lista positivo
			prec=head;	//avanzo dal primo elemento della lista
			corr=prec->next;
		}
		while(corr!=NULL){
			if(corr->info<0){
				Il_node *new_node=malloc(sizeof(Il_node));
				new_node->info=x;
				new_node->next=corr;
				prec->next=new_node;
				prec=corr;	//dopo aver aggiunto il nodo zero avanzo con i puntatori di scorrimento
				corr=corr->next;
			}
			else if(corr->info>0){
				prec=corr;
				corr=corr->next;
			}
		}
	}
}
void print(Il_node *head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}
}
int main(){
	Il_node *head=NULL;
	int n, x;
	scanf("%d",&n);
	while(n!=0){
		head=add(head,n);
		scanf("%d",&n);		
	}
	scanf("%d",&x);
	variante(head,x);
	print(head);
	return 0;
}

//questa e’ la versione corretta della variante
#include<stdio.h>
#include<stdlib.h>
struct el{
	int info;
	struct el *next;
}el;
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
void variante(Lista *head, int x){
	Lista prec, corr;
	if((*head)!=NULL){	//dobbiamo assicurarci che la lista non sia vuota
		if((*head)->info<0){	//per il primo elemento della lista negativo
			Lista new=(Lista)malloc(sizeof(struct el));
			new->info=x;
			new->next=*head;	//questo non puo' essere fatto con l'ordine inverso con quello che segue
			*head=new;
			prec=(*head)->next; //avanzo dal primo elemento che ho aggiunto essere zero
			corr=prec->next;
		}else if((*head)->info>0){	//per il primo elemento della lista positivo
			prec=*head;	//avanzo dal primo elemento della lista
			corr=prec->next;
		}
		while(corr!=NULL){
			if(corr->info<0){
				Lista new=(Lista)malloc(sizeof(struct el));
				new->info=x;
				new->next=corr;
				prec->next=new;
				prec=corr;	//dopo aver aggiunto il nodo zero avanzo con i puntatori di scorrimento
				corr=corr->next;
			}else if(corr->info>0){
				prec=corr;
				corr=corr->next;
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
	int n, x;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);		
	}
	scanf("%d", &x);
	variante(&head, x);
	print(head);
	return 0;
}

//..VARIANTE2: Scrivere una procedura che data una lista di interi, un intero x e un intero y, aggiunge un elemento che contiene y prima di ogni elemento uguale ad x presente nella lista. Se non ci sono elementi uguali ad x, la lista deve rimanere inalterata.
#include<stdio.h>
#include<stdlib.h>
struct el{
	int info;
	struct el *next;
}el;
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
void variante(Lista *head, int x, int y){
	Lista prec, corr;
	if((*head)!=NULL){	//dobbiamo assicurarci che la lista non sia vuota
		if((*head)->info==x){	//per il primo elemento della lista negativo
			Lista new=(Lista)malloc(sizeof(struct el));
			new->info=y;
			new->next=*head;	//questo non puo' essere fatto con l'ordine inverso con quello che segue
			*head=new;
			prec=(*head)->next; //avanzo dal primo elemento che ho aggiunto essere zero
			corr=prec->next;
		}else if((*head)->info!=x){	//per il primo elemento della lista positivo
			prec=*head;	//avanzo dal primo elemento della lista
			corr=prec->next;
		}
		while(corr!=NULL){
			if(corr->info==x){
				Lista new=(Lista)malloc(sizeof(struct el));
				new->info=y;
				new->next=corr;
				prec->next=new;
				prec=corr;	//dopo aver aggiunto il nodo zero avanzo con i puntatori di scorrimento
				corr=corr->next;
			}else if(corr->info!=x){
				prec=corr;
				corr=corr->next;
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
	int n, x, y;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);		
	}
	scanf("%d", &x);
	scanf("%d", &y);
	variante(&head, x,y);
	print(head);
	return 0;
}

//se vogliamo invece inserire un solo elemento prima/dopo un dato elemento
#include<stdio.h>
#include<stdlib.h>
struct el{
	int info;
	struct el *next;
}el;
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
void variante(Lista *head, int x, int y){
//cosi inseriamo y prima di x, che non sia il primo, non funziona cioe' su una lista contenente solo x
	Lista corr=*head;
	int trovato=0;
//i puntatori di attacco sono gli stessi ma cambia dove ci fermiamo e chi abbiamo controllato, per inserire prima controlliamo se l'elemento seguente e' x, e viceversa, per inserire dopo controlliamo se l'elemento corrente e' x
//per inserire y subito prima di x
/*	while(corr!=NULL && corr->next!=NULL && trovato==0){
		if(corr->next->info==x)	trovato=1;
		else	corr=corr->next;
	}
	if(trovato==1){
		Lista new=(Lista)malloc(sizeof(struct el));
		new->info=y;
		new->next=corr->next; //e' importante quest'ordine
		corr->next=new;
	}	*/

/*//se invece vogliamo che funzioni anche su una lista contenente solo x oppure come primo elemento x abbiamo bisogno di 2 puntatori
	Lista corr=*head, prec=NULL;
	int trovato=0;
	while(corr!=NULL && corr->next!=NULL && trovato==0){
		if(corr->info==x)	trovato=1;
		else{
			prec=corr;
			corr=corr->next;
		}
	}
	if(trovato==1){
		Lista new=(Lista)malloc(sizeof(struct el));
		new->info=y;
//		if(prec==NULL){
//			new->next=(*head); 
//			(*head)=new;
//		}else if(prec!=NULL){
//			new->next=prec->next; 
//			prec->next=new;
//		}
//		//oppure analogamente
		new->next=corr;
		if(prec!=NULL)	prec->next=new;
		else (*head)=new;
	}	*/	

//per inserire y subito dopo di x, non funziona se x e' l'ultimo elemento
	while(corr!=NULL && corr->next!=NULL && trovato==0){
		if(corr->info==x)	trovato=1;
		else	corr=corr->next;
	}
	if(trovato==1){
		Lista new=(Lista)malloc(sizeof(struct el));
		new->info=y;
		new->next=corr->next; //e' importante quest'ordine
		corr->next=new;
	}	

//se x non e' presente, oppure se x e' l'ultimo della lista inseriamo la y in fondo alla lista, altrimenti cosi come e' rimane inalterata
	else if(trovato==0){
		Lista new=(Lista)malloc(sizeof(struct el));
		new->info=y;
		corr->next=new;
		new->next=NULL; //e' importante quest'ordine
	}	
}

//cosi inseriamo y subito dopo l'ultima occorrenza di x
int var(Lista head, int x){
	int conta=0;
	while(head!=NULL){
		if(head->info==x)
			conta++;
		head=head->next;
	}
	return conta;
}
void varr(Lista *head, int x, int y){
	int v=0;
	Lista corr=*head;
	while(v<var((*head), x) && corr->next!=NULL){
		if(corr->next->info==x)	v++;
		corr=corr->next;
	}
	Lista new=(Lista)malloc(sizeof(struct el));
	new->info=y;
	new->next=corr->next;
	corr->next=new;
}

void print(Lista head){
	while(head!=NULL){
		printf("%d\n",head->info);
		head=head->next;
	}
}
int main(){
	Lista head=NULL;
	int n, x, y;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);		
	}
	scanf("%d", &x);
	scanf("%d", &y);
	variante(&head, x, y);
//	varr(&head, x, y);
	print(head);
	return 0;
}
