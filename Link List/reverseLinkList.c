#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
void addNode(void);
void display(void);
NODE* newnode(void);
void reverseList(void);
int main()
{
	int i;
	NODE *temp;
	printf("Enter the 5 Element in link list\n");
	for(i=0;i<5;i++)
	{
		addNode();
	}
	printf("The Link list element is\n");
	display();
	printf("Reverse Link list is\n");
	reverseList();
	display();
	
}
NODE *newnode()
{
	int num;
	NODE* temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Element\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	return temp;
}
void addNode(void)
{
	NODE *temp,*current;

	temp=newnode();
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
		{
			current=current->next;	
		}	
		current->next=temp;
	}
}
void display(void)
{
	NODE *temp;
	temp=head;
	if(head==NULL)
	{
		printf("Link list is empty\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("-> %d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void reverseList(void)
{
	NODE *next,*prev,*current;

	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	
}











