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
int main()
{
	NODE *root;
	root =NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,20);
	root=Insert(root,25);
	root=Insert(root,8);
	root=Insert(root,12);
	display(root);
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

