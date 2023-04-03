#include<stdio.h>
#include<stdlib.h>

//Liststructure
struct struct_list_item_t {	float key;	struct struct_list_item_t *next;};
typedef struct struct_list_item_t list_item_t;

//Functions to be implemented
float *readArray(int *len){
	*len=0;
	int i=0;
	float *a=(float *)malloc((*len)*sizeof(float)), el;
	scanf("%f", &el);
	while(el!=0){
		(*len)++;
		a=(float *)realloc(a,(*len)*sizeof(float));
		a[i]=el;
		i++;
		scanf("%f", &el);
	}
	return a;
/*	float *A=NULL, num;
	int i=0;
	scanf("%f", &num);
	while(num!=0){
        	A=(float *)realloc(A,sizeof(float)*(i+1));
        	A[i]=num;
        	i++;
        	scanf("%f", &num);
    	}
	*len=i;
    	return A;	*/
}

list_item_t *add(list_item_t *head, int v){
	list_item_t *corr=head, *new=(list_item_t *)malloc(sizeof(list_item_t));
	new->key=v;
	new->next=NULL;
	if(head==NULL){
		new->next=head;
		head=new;
	}else if(head!=NULL){
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=new;
	}
	return head;	//non dimenticare il return alla fine di queste funzioni!!!
}

list_item_t *concatInList(float a1[], float a2[], int len1, int len2){
/*	list_item_t *head=NULL;
	int i=0, j=0;
	while(i<len1 && j<len2){
		if(a1[i]==a2[j]){
			head=add(head, a1[i]);
			i++;
			j++;
		}else{
			if(a1[i]<a2[j]){
				head=add(head, a1[i]);
				i++;
			}else if(a1[i]>a2[j]){
				head=add(head, a2[j]);
				j++;
			}
		}
		if(j==len1){
			head=add(head, a1[i]);
			break;
		}else if(i==len2){
			head=add(head, a2[j]);
			break;
		}
	}	
	return head;	*/

	if(a1==NULL || a2==NULL)	return NULL;
	list_item_t *head=NULL;
	int i=0;
	while(i<len1 && i<len2){
        	if(a1[i]<a2[i]){
            		head=add(head, a1[i]);
            		head=add(head, a2[i]);
        	}else{
	        	head=add(head, a2[i]);
            		head=add(head, a1[i]);            
        	}
        	i++;
	}
	return head;	
}

list_item_t *orderedDeletion(list_item_t *list){
	if(list!=NULL){
		list_item_t *corr=list, *prev=NULL;
		while(corr->next!=NULL){
			if(corr->key>corr->next->key){
				if(prev==NULL){
					list=corr->next;
					free(corr);
					corr=list;
				}else if(prev!=NULL){
					prev->next=corr->next;
					free(corr);
					corr=prev->next;
				}
			}else if(corr->key<=corr->next->key){
				prev=corr;
				corr=corr->next;	
			}
		}
		if(corr->key<0){
			if(prev==NULL) list=NULL;
			else{
				prev->next=NULL;
				free(corr);
			}
		}
	}
	return list;
}

//Function to print all the elements of the list
void printList(list_item_t *list){
	printf("(");
	while(list!=NULL){
		printf("%.1f ", list->key);
		list=list->next;
	}
	printf(")\n");
}	
	
int main(){
	float *A1, *A2;
	int len1, len2, i;
	list_item_t *list1, *list2;

	//Read and print the two arrays
	A1=readArray(&len1);
	printf("Array:\n");
	for(i=0; i<len1; i++)	printf("%.1f ", A1[i]);
	printf("\n");
	A2=readArray(&len2);
	printf("Array:\n");
	for(i=0; i<len2; i++)	printf("%.1f ", A2[i]);
	printf("\n");

	//Concatenate the two arrays in the list
	list1=concatInList(A1, A2, len1, len2);
	//Print the concatenated list
	printf("Merged list:\n");
	printList(list1);

	//Deletes element out of order in the list
	list2=orderedDeletion(list1);
	//Print the cleaned list
	printf("Deleted list:\n");
	printList(list2);	

	return 0;
}
