#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
void display(void);
int linkLength(void);
void addFirst(void);
void addLast(void);
int linkLength(void);
void addPos(void);
void deleteFirst(void);
void deletePos(void);
void deleteLast(void);
void clearScreen(void);
int main()
{
	int choice;
	do
	{
		printf("0.Display\n1.Length\n");
		printf("2.Add Node First\n3.Add Node Last\n4.Add Node Position\n");
		printf("5.Delete Node First\n6.Delete Node Last\n7.Delete Node Position\n");
		printf("8.Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				clearScreen();
				display();
				break;
			case 1:
					clearScreen();
				printf("Link List Length is = %d\n",linkLength());
				break;
			case 2:
				clearScreen();
				addFirst();
				break;
			case 3:
				clearScreen();
				addLast();
				break;
			case 4:
				clearScreen();
				addPos();
				break;
			case 5:
				clearScreen();
				deleteFirst();
				break;
			case 6:
				clearScreen();
				deleteLast();
				break;
			case 7:
				clearScreen();
				deletePos();
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}while(1);
return 0;
}
void display(void)
{
	NODE *trav;
	trav=head;
	do
	{
		trav=trav->next;
		printf("%d->",trav->data);
				
	}while(trav!=head);
	printf("\n");
}
int isEmpty(void)
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		return 1;	
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
void addFirst(void)
{
	NODE *temp;
	temp=newNode();
	if(isEmpty()==0)
	{
		head=temp;
		temp->next=head;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;
	}
}
void addLast(void)
{
	if(isEmpty()==0)
	{
		addFirst();
	}
	else
	{
		NODE *temp;
		temp=newNode();
		temp->next=head->next;
		head->next=temp;
		head=temp;
	}
}
int linkLength(void)
{
	if(isEmpty()==0)
	{
		return 0;
	}
	else
	{
		NODE *trav;
		int count=0;
		trav=head;
		do
		{
			trav=trav->next;
			count++;
					
		}while(trav!=head);
		return count;
	}
}
void addPos(void)
{
	int pos;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		addFirst();
	}
	else if(pos==linkLength()+1)
	{
		addLast();
	}
	else if(pos<=linkLength())
	{	
		NODE *trav,*temp,*prev;
		temp=newNode();
		int count=0;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
			count++;
						
		}while(pos!=count);	
		temp->next=prev->next;
		prev->next=temp;
	}
}
void deleteFirst(void)
{
	if(isEmpty())
	{
		NODE *temp;
		temp=head->next;
		head->next=head->next->next;
		free(temp);		
	}
	else
	{
		printf("Link List Is Empty\n");
	}
}
void deleteLast(void)
{
	if(isEmpty())
	{
		NODE *prev,*trav;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
						
		}while(trav!=head);	
		prev->next=head->next;
		head=prev;
		free(trav);
	}
	else
	{
		printf("Link List Is Empty\n");
	}
}
void deletePos(void)
{
	int pos;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		deleteFirst();
	}
	else if(pos==linkLength())
	{
		deleteLast();
	}
	else if(pos<linkLength())
	{
		NODE *prev,*trav;
		int count=0;
		trav=head;
		do
		{
			prev=trav;
			trav=trav->next;
			count++;
		}while(count!=pos);
		prev->next=trav->next;
		free(trav);
	}
}
void clearScreen(void)
{
	system("cls");
}
