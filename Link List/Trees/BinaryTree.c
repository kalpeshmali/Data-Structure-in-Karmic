#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;	
}NODE;
NODE *root=NULL;

int inputData(void);
NODE* newNode(void);
void insert(void);
void display(NODE*);
int main()
{
	int choice;
	do
	{
		
		printf("1.Insert Node to tree.\n2.display tree\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				display(root);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Invalid choice\n");	
		}	
	}while(1);
} 
int inputData(void)
{
	int num;
	printf("Enter the Element\n");
	scanf("%d",&num);
	return num;
}
NODE* newNode(void)
{
	NODE* temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->key=inputData();
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert(void)
{
	NODE *temp,*trav;
	trav=root;
	temp=newNode();
	if(root==NULL)
	{
		root=temp;
		return ;
	}
	for(;;)
	{
		if(temp->key == trav->key)
		{
			printf("Duplicate data\n");
			free(temp);
			break;
		}
		if(temp->key<trav->key)
		{
			if(trav->left==NULL)
			{
				trav->left=temp;
				break;
			}
			else
			{
				trav=trav->left;
			}
		}
		else
		{
			if(trav->right==NULL)
			{
				trav->right=temp;
				break;
			}
			else
			{
				trav=trav->right;
			}	
		}
	}
}
void display(NODE *cnode)
{
	if (cnode != NULL) 
    { 
        display(cnode->left); 
        printf("%d \n", cnode->key); 
        display(cnode->right); 
    } 
}

