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
int input_num(void);
void add_last(void);
void add_first(void);
void add_position(void);
void delete_first(void);
void delete_last(void);
void delete_pos(void);
int main()
{
	int choice,len;
	do
	{
		printf("\n\t\t1.Add Element Last.\t\t2.Add Element First.\t\t3.Add Element Position.\n");
		printf("\n\t\t4.Delete Element Last.\t\t5.Delete Element First.\t\t6.Delete Element Position.\n");
		
		printf("\n\t\t7.Link list length\t\t8.Display.\t\t\t9.Exit.\n");
		

		printf("\n\tEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					add_last();
					break;
			case 2: add_first();
					break;
			case 3: add_position();
					break;
		
			case 4: delete_last();
					break;
					
			case 5:delete_first();
					break;
					
			case 6:delete_pos();
					break;
			case 7: len=length();
					printf("link list length is = %d\n",len);
					break;
			case 8:
					display();
					break;
			case 9:
					exit(0);
					break;		
			default:printf("Invalid Choice\n");
		}
	}while(1);
}

struct node* newnode()
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

int length(void)
{
	int count=0;
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Link list Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
	}
	return count;
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
void add_first()
{
	NODE *temp;
	int num;
	temp=newnode();
	num=input_num();
	temp->data=num;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
		printf("%d\n",temp->data);
	}	
	//-----
//	temp->next = head;
//	head = temp;
}

void add_position(void)
{
	NODE *temp,*temp1;
	int num,len,pos,count=0;
	printf("Enter the Position\n");
	scanf("%d",&pos);
	
	len=length();
	printf("Link list length is %d\n",len);
	if(pos>len)
	{
		printf("Enter Position is invalid\n ");	
	}	
	else if(pos==0)
	{
	//	add_first();
		int num;
		temp=newnode();
		num=input_num();
		temp->data=num;
		temp->next=head;
		head=temp;
		printf("%d\n",temp->data);
	}
	else
	{
		temp1=head;
		temp=newnode();
		num=input_num();
		temp->data=num;	
		while(count!=pos-1)
		{
			printf("%d\n",temp1->data);
			temp1=temp1->next;
			count++;
		}
		temp->next=temp1->next;
		temp1->next=temp;		
	}
}

void delete_first(void)
{
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Link list is Empty\n");
	}
	else
	{
		printf("%d Element is deleted\n",temp->data);
		head=temp->next;
	}
	free(temp);
}
void delete_last(void)
{
	
	NODE *temp;
	NODE *prev_node;
	temp=head;
	if(temp==NULL)
	{
		printf("Link list is Empty\n");
	}
	else
	{
		#if 0
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		printf("%d Element is Deleted\n",temp->next->data);
		temp->next=NULL;
		#endif
		while(temp->next!=NULL)
		{
			prev_node = temp;
			temp=temp->next;
		}
		prev_node->next = NULL;
		free(temp);
	}
}
void delete_pos(void)
{
	NODE *temp,*prev_node;
	temp=head;
	int len,count=1,pos;
	len=length();
	printf("Enter the Position\n");
	scanf("%d",&pos);
	if(pos<=len)
	{
		if(pos==1)
		{
			//temp=temp->next;
			//free(head);
			head=temp->next;
			free(head);
		}
		else
		{	
			while(count!=pos)
			{
				prev_node = temp;
				temp=temp->next;
				count++;
			}
			prev_node->next=temp->next;
			free(temp);
			printf("\n");
		}
	}
	else
	{
		printf("Position is Invalid\n");
	}
}

