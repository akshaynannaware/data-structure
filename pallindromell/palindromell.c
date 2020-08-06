#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

void create(node *list){
	int no;
	printf("enter size of linked list");
	
	scanf("%d",&no);

	node *temp=list;
	
	node *newn;
	//temp->next=list;
	for(int i=0;i<no;i++){
		newn=(node *)malloc(sizeof(node));
		newn->next=NULL;
		newn->prev=NULL;
		scanf("%d",&newn->data);
		temp->next=newn;
		newn->prev = temp;
		temp=newn;		
	}	
	
}
void palindrome(node *list){
	int flag=0;
	
	node *temp1=list->next;
	node *temp2=list;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	//printf("\n%d",temp2->data);
	//printf("%d",temp1->data);
	while(temp1->next!=NULL && temp2->prev!=NULL){
		if(temp1->data==temp2->data){
			flag=0;
		}
		else{
			flag=1;
			break;
		}
		temp1=temp1->next;
		temp2=temp2->prev;
	}
	if(flag==0){
		printf("linked list is palindrome\n");
	}
	else
		printf("linked list is NOT palindrome\n");
}

void display(node *list){
	node *temp1=list;
	while(temp1->next!=NULL){
		temp1=temp1->next;
		printf("%d	",temp1->data);
	}
}

void main()
{
	node *list;
	list = (node*)malloc(sizeof(node));
	list->next=NULL;
	list->prev=NULL;
	
	create(list);
	display(list);
	palindrome(list);


}






