/* Si scriva una procedura che, presi una lista e un numero naturale n, crea una copia dei primi n elementi della lista 
e aggiunge tali nuovi elementi in coda alla lista stessa. Se la lista contiene meno di n elementi, tutti gli elementi vengono copiati e aggiunti in coda.	*/

#include<stdio.h>
#include<stdlib.h>

struct el{int info; struct el *next;};
typedef struct el *Lista;
void add(Lista *head, int m){
	Lista corr=*head, new=(Lista)malloc(sizeof(struct el));
	new->info=m;
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
int lunghezza(Lista head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
void copia(Lista head, int m){	//il parametro head non va passato per indirizzo perche' non si modifica mai il puntatore head
	if((head)!=NULL){
		Lista corr=head;
		int i=0;
		if(m<lunghezza(head)){
			while(i<m){
				add(&(head), corr->info);
				i++;
				corr=corr->next;
			}
		}
		else if(m>=lunghezza(head)){
			m=lunghezza(head);
			while(i<=m-1){	//non posso mettere qui i<lunghezza(head) perche' quest'ultima cambia ogni volta
				add(&(head), corr->info);
				i++;
				corr=corr->next;
			}			
		}
	}
}
//Una possibile soluzione consiste nel copiare un elemento per volta, andando via via ad aggiungere la copia in fondo alla lista.
void copia1(Lista l, int n){
	Lista tail=l, oldtail, tmp;
	if(l!=NULL && n>0){
		while(tail->next!=NULL)
			tail=tail->next;
		oldtail=tail;
		while(n>0 && l!=oldtail->next){
			tmp=(Lista)malloc(sizeof(struct el));
			tmp->info=l->info;
			tmp->next=NULL;
			tail->next=tmp;
			tail=tail->next;
			n--;
			l=l->next;
		}
	}
}
//Una soluzione alternativa consiste nel creare una nuova lista costituita dalle copie dei primi n elementi, 
// da “appendere” in un colpo solo in coda alla lista originaria.
void copia2(Lista l, int n){
	Lista copiati=NULL, last_copiati=NULL, tmp, curr=l;
	if(l!=NULL){
		while(n>0 && curr!=NULL){
			tmp=(Lista)malloc(sizeof(struct el));
			tmp->info=curr->info;
			tmp->next=NULL;
			if(copiati==NULL){
				copiati=tmp;
				last_copiati=tmp;
			}else{
				last_copiati->next=tmp;
				last_copiati=tmp;
			}
			n--;
			curr=curr->next;
		}
		while(l->next!=NULL)
			l=l->next;
		l->next=copiati;
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
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);	
	}
	scanf("%d", &m);	
	print(head);
	printf("\n");
//	copia(head, m);
//	copia1(head, m);
	copia2(head, m);
	print(head);
	printf("\n");
	return 0;
}
