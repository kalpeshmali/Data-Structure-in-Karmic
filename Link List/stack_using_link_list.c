#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
void push(void);
void pop(void);
void display(void);
int input_data(void);
NODE* newnode();
NODE *top=NULL;
int main()
{
	int choice;
	do
	{
		printf("Stack operation\n");
		printf("\n\t1.Push\n\t2.Pop\n\t3.Display\n");
		
		printf("\tEnter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					push();
					break;
			case 2:
					pop();
					break;
			case 3:
					display();
					break;
			case 4:
					exit(1);
					break;
			default:
					printf("Invalid Choice\n");
					break;
					
		}
	}while(1);
}
int input_data(void)
{
	int num;
	printf("Enter the Number\n");
	scanf("%d",&num);
	return num;
}
NODE* newnode(void)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->next=NULL;
	return temp;
}
void push(void)
{
	NODE *temp;
	int num;
	num=input_data();
	temp=newnode();
	temp->data=num;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}
void display(void)
{
	NODE *temp;
	printf("Stack element \n");
	temp=top;
	while(temp!=NULL)
	{
		printf("-> %d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void pop(void)
{
	NODE *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("stack Underflow\n");
	}
	else
	{
		printf("%d Element is deleted\n",temp->data);
		top=temp->next;
	}
}
