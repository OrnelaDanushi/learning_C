/* Si scriva una procedura che, presi attraverso opportuni parametri una lista di interi ed un intero n, cancella dalla lista i primi n elementi maggiori di 0.	*/
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
void delete(Lista *head, int m){
	if((*head)!=NULL && m>0){
		int v=0;
		Lista corr=*head, prec=NULL, prev=corr;
		while(corr!=NULL && v<m){
			if(corr->info>0){
				if(prec==NULL){
					if(corr->next==NULL)	(*head)=NULL;
					else if(corr->next!=NULL){
						(*head)=(*head)->next;
						prev=corr; //per non creare garbage e errori dobbiamo liberare lo spazio 
						free(prev);
						corr=prev->next;
						//free(corr);	//oppure
						//corr=(*head);
					}
				}else if(prec!=NULL){
					if(corr->next==NULL){
						prec->next=NULL;
						prev=corr;
						free(prev);
						corr=prev->next;
					}else if(corr->next!=NULL){
						prec->next=prec->next->next;
						prev=corr;
						free(prev);
						corr=prev->next;
					}
				}	
				v++;
			}else if(corr->info<0){
				prec=corr;
				corr=corr->next;
			}			
		}
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
	delete(&head, m);
	print(head);	
	printf("\n");
	return 0;
}
