/* Scrivere una procedura che, prese due liste di interi, cancella dalla prima lista tutti gli elementi che compaiono anche nella seconda.
(Supponiamo che non debbano essere cancellati tutti quanti gli elementi della prima lista, altrimenti se vuota da' segmentation fault.	*/
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
int contamembro(Lista head, int val){
	int count=0;
	while(head!=NULL){
		if(head->info==val) count++;
		head=head->next;
	}
	return count;
}
void cancella(Lista *head, Lista *head1){
	if((*head)!=NULL || (*head1)!=NULL){
		Lista corr=*head, corr1=*head1, prec=NULL;
		int v;
		while(corr1!=NULL){ //se mettessi while(corr1->next!=NULL){.. non controllerebbe mai l'ultimo elemento di *head1
//			printf("corrr %d ", corr1->info);
//			printf("count %d  ", contamembro(*head, corr1->info));
			if(contamembro(*head, corr1->info)>0){
				v=0, corr=*head, prec=NULL; //questi devono essere sempre inizializzati cosi per ogni nuovo elemento
				while(v<=contamembro(*head, corr1->info)){
					if(corr->info==corr1->info){
						if(prec==NULL){
							Lista prev=*head;
							(*head)=(*head)->next;
							free(prev);
						}else if(prec!=NULL){
							Lista prev=corr;
							prec->next=prec->next->next;
							corr=prec->next;
							free(prev);
						}
						v++;
					}
					prec=corr;
					corr=corr->next;
				}
		//		printf("%+d ",prec->info);					
		//		printf("%+d ",corr->info);
		//per l'ultimo corr che non controlla il while perche' esce dal ciclo visto che v ha raggiunto il limite
				if(corr->info==corr1->info){
					if(prec!=NULL){
						prec->next=NULL;
						free(corr);
					}else if(prec==NULL)	(*head)=NULL;
				}						
			}
			corr1=corr1->next;
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
	Lista head=NULL, head1=NULL;
	int n, m;
	scanf("%d", &n);
	while(n!=0){
		add(&head, n);
		scanf("%d", &n);
	}
	scanf("%d", &m);
	while(m!=0){
		add(&head1, m);
		scanf("%d", &m);
	}
	print(head);	
	printf("\n");	
	print(head1);
	printf("\n");	
	cancella(&head, &head1);
	print(head);	
	printf("\n");
	return 0;
}
