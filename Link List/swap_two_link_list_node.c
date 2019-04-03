#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
void display(void);
NODE* newnode(void);
void insert_node(void);
void sortingList(void);
int main()
{
	int i;
	printf("Enter the two Element to link list\n");
	for(i=0;i<2;i++)
	{
		insert_node();
	}
	display();
	swapNode();
	printf("After swapping Link List Node is \n");
	display();
}
NODE* newnode(void)
{
	int num;
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Element\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	return temp;
}
void insert_node(void)
{
	NODE *temp,*temp1;
	temp=newnode();
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
}
void display(void)
{
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Link List is Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("-> %d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void swapNode(void)
{
	NODE *temp1,*temp2;
	temp1=head;
	temp2=temp1->next;
	temp2->next=temp1;
	temp1->next=NULL;
	head=temp2;
	
}
