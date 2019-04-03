#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
void reverseList(NODE*);
NODE* newnode(void);
void display(void);
void add_last(void);
int main()
{
	NODE *temp;
	int num,i;
	printf("How Many elementinsert to link list\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		add_last();	
	}	
	display();
	temp=head;
	reverseList(head);
}
void reverseList(NODE *temp)
{
	if(temp->next!=NULL)
	{
		reverseList(temp->next);			
	}	
	printf("%d -> ",temp->data);
}	
NODE* newnode(void)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->next=NULL;
	return temp;
}
int input_num()
{
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	return num;
}

void display()
{
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Link list is empty\n");
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
void add_last()
{
	int num,count=1;
	NODE *temp,*temp1;
	temp1=head;
	temp=newnode();
	num=input_num();
	temp->data=num;
	if(head==NULL)
	{
		head=temp;
		printf("Element is added %d location index\n",count);
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
			count++;
		}
		
		temp1->next=temp;
		printf("Element is added %d location\n",count+1);
	}
}
