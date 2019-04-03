#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
NODE *last=NULL;
NODE* newNode(void);
int isEmpty(void);
void display(void);
void addFirst(void);
int linkLength(void);
void addLast(void);
int main()
{
	int choice,length;
	do
	{
		printf("Circular Link List Operation\n");
		printf("0.Display\n1.Length\n2.Add Node First\n3.Add Node Last\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:display();
				break;
				
			case 1:printf("Link List Element is %d\n",linkLength());
				break;
			case 2:addFirst();
				break;
			case 3:addLast();
				break;
		}
	}while(1);
	return 0;
}
int linkLength(void)
{
	if(isEmpty()==1)
	{
		return 0;
	}
	else
	{
		int count=0;
		NODE *trav;
		trav=head;
		while(trav!=NULL)
		{
			trav=trav->next;
			count++;
		}
		return count;
	}
}
int isEmpty(void)
{
	if(head==NULL && last==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
NODE* newNode(void)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Element\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}
void display(void)
{
	if(isEmpty()==1)
	{
		printf("Link List Is Empty");
	}
	else if(head==last)
	{
		printf("%d->",head->data);
	}
	else
	{
		NODE* trav,*prev;
		trav=head;
		while(prev!=last)
		{
			prev=trav;
			printf("%d->",trav->data);
			trav=trav->next;
		}
	}
	printf("\n");
}
void addFirst(void)
{
	NODE *temp;
	temp=newNode();
	if(isEmpty()==1)
	{
		head=temp;
		last=temp;	
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void addLast(void)
{
	NODE *temp;
	temp=newNode();
	if(isEmpty()==1)
	{
		head=temp;
		last=temp;	
	}
	else
	{
		last->next=temp;
		last=temp;
	}
	
}

