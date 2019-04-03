#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}NODE;
NODE *head=NULL;
int inputData();
int linkListLength(void);
void addLast(void);
void addFirst(void);
void addPos(void);
int inputIndex(void);
NODE* newNode(void);
void display(void);
void deleteFirst(void);
void deleteLast(void);
void deletePos(void);
void reverseList(void);
int main()
{
	int choice;
	do
	{
		printf("0.Display\n1.Find Link List Length\n");
		printf("\n2.Add Element Last\n3.Add Element First\n4.Add Element Pos\n");
		printf("\n5.Delete First element \n6.Delete last element\n7.Delete Element Pos\n");
		printf("\n8.Reverse Link List\n");
		printf("Enter the Your Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:	display();	
				break;
			case 1:
				//linkLen=linkListLength();
				printf("Link List Length is %d\n",linkListLength());
				break;
			case 2:	addLast();
				break;
			case 3: addFirst();
				break;
			case 4: addPos();
					break;
			case 5: deleteFirst();
					break;
			case 6: deleteLast();
					break;
			case 7:
					deletePos();
					break;
			case 8:
					reverseList();
					break;
			default:
				printf("Invalid Choice\n");
		}
	}while(1);
}

int linkListLength(void)
{
	int linkLen=0;
	NODE *trav;
	trav=head;
	while(trav!=NULL)
	{
		
		linkLen++;
		trav=trav->next;
	}
	return linkLen;
}
int inputData(void)
{
	int num;
	printf("Enter The Element\n");
	scanf("%d",&num);
	return num;
}
NODE* newNode(void)
{

	
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->prev=NULL;
	temp->data=inputData();
	temp->next=NULL;
}
void addLast(void)
{

	if(head==NULL)
	{
		head=newNode();
	}
	else
	{
		NODE *temp,*trav;
		trav=head;
		temp=newNode();
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=temp;
		temp->prev=trav;
	}
}
void addFirst(void)
{
	NODE *temp;
	temp=newNode();
	temp->next=head;
	head=temp;
}
void addPos(void)
{
	int pos,num,len;
		pos=inputIndex();
	len=linkListLength();
	printf("length=%d\n",len);
	if(pos==1)
	{
		addFirst();
	}
	else if(len>=pos-1)
	{
	
		int count=1;
		NODE *trav;
		trav=head;
		while(pos!=count+1)
		{
			count++;
			trav=trav->next;
		}
		NODE *newnode,*travnext;
		newnode=newNode();
		
		newnode->prev=trav;
		newnode->next=trav->next;
		trav->next=newnode;
	}
	else
	{
		printf("Invalid Position\n");
	}
}
int inputIndex(void)
{
	int indx;
	printf("Enter the position\n");
	scanf("%d",&indx);
	return indx;
}
void display(void)
{
	NODE *temp;
	temp=head;
	if(temp!=NULL)
	{
	
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	else
	{
		printf("Link List is Empty\n");
	}
	
}
void deleteFirst(void)
{
	NODE *temp;
	if(head==NULL)
	{
		printf("Link Is Empty\n");
	}
	else
	{
		if(head->next==NULL)
		{
			temp=head;
			printf("%d elememnt deleted\n",temp->data);
			head=NULL;
			free(temp);
			
		}
		else
		{
			temp=head;
			printf("%d element deleted\n",temp->data);
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
	}
}
void deleteLast(void)
{
	if(head==NULL)
	{
		printf("Link List Is Empty\n");
	}
	else
	{
		if(head->next==NULL)
		{
			printf("%d Element deleted\n",head->data);
			head=NULL;
		}
		else
		{
			NODE *trav,*temp;
			trav=head;
			while(trav->next!=NULL)
			{
				temp=trav;
				trav=trav->next;	
			}
			printf("%d Element deleted\n",trav->data);
			temp->next=NULL;
			free(trav);	
		}
	}
}
void deletePos(void)
{
	int pos,len,count=1;
	printf("Enter the Pos\n");
	scanf("%d",&pos);
	len=linkListLength();
	if(pos<=len)
	{
		NODE *trav,*temp;
		trav=head;
		while(count!=pos)
		{
			temp=trav;
			trav=trav->next;
			count++;	
		}
		printf("%d element is deleted\n",trav->data);
		temp->next=trav->next;
		free(trav);
	}
}
void reverseList(void)
{
	NODE *trav,*temp;
	trav=head;
	while(trav->next!=NULL)
	{
		trav=trav->next;	
	}
	while(trav!=NULL)
	{
	    printf("%d->",trav->data);
		trav=trav->prev;
	}
	printf("\n");	
}
