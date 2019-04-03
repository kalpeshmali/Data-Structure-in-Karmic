#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
void clrScreen(void)
{
	system("cls");
	system("pause");
}
NODE *front=NULL;
NODE *rear=NULL;
void enQueue(void);
void deQueue(void);
void display(void);
int main()
{
	int choice;
	do
	{
		printf("\n\tQueue Operation\n");
		printf("\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enQueue();
				clrScreen();
					break;
			case 2:deQueue();
				clrScreen();
					break;
			case 3:display();
				
					break;
			case 4:exit(0);
			default:printf("Invalid Choice\n");
			
		}
	}while(1);
}
NODE* newnode(void)
{
	int num;
	printf("Enter the Element\n");
	scanf("%d",&num);
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=num;
	temp->next=NULL;
	return temp;
}
void enQueue(void)
{
	NODE *temp;
	temp=newnode();
	if(rear==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		NODE *temp1;
		temp1=front;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		rear=temp;		
	}
}
void deQueue(void)
{
	NODE *temp;
	temp=front;
	if(front==NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("\t\t%d element deleted\n",temp->data);
		front=temp->next;
		free(temp);
	}
}
void display(void)
{
	NODE *temp;
	temp=front;
	clrScreen();
	if(front==NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("\tQueue Element is\n");
		while(temp!=NULL)
		{
			printf("-> %d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}

}
