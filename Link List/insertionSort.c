#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
NODE* addNode(void);
void display(NODE*);
void sortNode(void);
void addFirst(NODE*);
void addLast(NODE*);
NODE *head1=NULL;

int main()
{
	int i,num;
	printf("How many node you want to create\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		createList();
		//sortNode();
	}
	display(head1);
	
	printf("After Sorting The List\n");
	display(head);
}
void createList()
{
	printf("Enter the Element\n");
	
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	if(head1==NULL)
	{
		head1=temp;
	}	
	else
	{
		NODE *trav;
		trav=head1;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=temp;
	}
}
NODE* addNode(void)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter the Number\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}

void display(NODE*)
{
	NODE *trav;
	trav=head1;
	while(trav!=NULL)
	{
		printf("%d->",trav->data);
		trav=trav->next;	
	}
	printf("\n");
}

void sortNode(void)
{
	NODE *temp;
	temp=addNode();
	if(head==NULL)
	{
		head=temp;
	}
	else if(head->data>temp->data)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		NODE *trav,*prev;
		trav=head;
		while(trav!=NULL)
		{	
			if(trav->data>temp->data)
			{
				prev->next=temp;
				temp->next=trav;
				break;
			}
			prev=trav;
			trav=trav->next;	
		}
		prev->next=temp;
	}
}


