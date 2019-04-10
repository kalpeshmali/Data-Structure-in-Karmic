#include<stdio.h>
#include<stdlib.h>
typedef struct BstNode
{
	int data;
	struct BstNode *left;
	struct BstNode *right;
}NODE;

NODE* Insert(NODE *root,int data);
int Search(NODE*,int);
void display(NODE*);
void minElement(NODE*);
void maxElement(NODE*);
int treeHeight(NODE*,int);
int main()
{
	int count;
	NODE *root;
	root =NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,12);
	root=Insert(root,8);
	root=Insert(root,3);
	root=Insert(root,13);
	root=Insert(root,17);
	root=Insert(root,200);
	root=Insert(root,21);
	display(root);
	minElement(root);
	maxElement(root);
	printf("tree height = %d\n",(treeHeight(root,0)-1));
	if(Search(root,8))
	{
		printf(" 8 Element is found\n");	
	}	
	else
	{
		printf("Element is not Found\n");
	}
}
NODE* getNewNode(int data)
{
	NODE *newNode;
	newNode=(NODE*)malloc(sizeof(NODE));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
NODE* Insert(NODE *root,int data)
{
	NODE *newNode;
	newNode=getNewNode(data);
	if(root == NULL)
	{
		root=newNode;
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	return root;
}
int Search(NODE* root,int data)
{
	if(root == NULL)
	return 0;
	
	else if(root->data == data)
	return 1;
	
	else if(data<=root->data)
	return Search(root->left,data);
	
	else return Search(root->right,data);
}
void display(NODE *cnode)
{
	if (cnode != NULL) 
    { 
    	
        display(cnode->left); 
        printf("%d \n", cnode->data); 
        display(cnode->right); 
    } 
}
void minElement(NODE* root)
{
	NODE *temp;
	int temp1;
	temp=root;
	temp1=temp->data;
	while(temp!=NULL)
	{
		if(temp->data <= temp1);
		{
			temp1=temp->data;
		}
		temp=temp->left;
	}
	printf("The Minimum  Element is %d\n",temp1);
}
void maxElement(NODE* root)
{
	NODE *temp;
	int temp1;
	temp=root;
	temp1=temp->data;
	while(1)
	{
		if(temp->data >= temp1);
		{
			temp1=temp->data;
		}
		if(temp->right == NULL)
		{
			break;
		}
		temp=temp->right;
	}
	printf("The Maximum Element is %d\n",temp1);
}
int treeHeight(NODE *cnode,int level)    //Height Of Tree
{
	static int height=0;
	if(height<level)
	{
		height=level;
	} 
	if(cnode != NULL) 
    { 
        treeHeight(cnode->left,level+1); 
        treeHeight(cnode->right,level+1);       
	}
    return height;
}

