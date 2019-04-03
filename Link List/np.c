//program for operations on linked list.
#include<stdio.h>
#include<stdlib.h>

struct node                                    //defining the node structure.
{
    int data;
    struct node* next;
};

struct node* head=NULL;                                //head as global initialized to NULL.

int len(void)                                    //function to find length of linked list.
{
    struct node* trav;
    int count=0;
    trav=head;

    while(trav!=NULL)
    {
        trav=trav->next;
        count++;
    }
    return count;
}


void rev_data(void)                            //printing data in reverse manner.(without disturbing the list)
{
    int count,i;
    struct node* temp;
    struct node* prev;
    temp=head;
    i=len();

     printf("printing in reverse way reva_data\n");

    for(;i>0;i--)
    {
        count=0;
        while(temp!=NULL)
        {
            if(count==i)
            {
                break;
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        printf("%d->",prev->data);
        temp=head;
    }
    printf("\n\n");
}


void node(void)                                            //function for node creation
{
    int num;
    struct node* temp;
  //  struct node* temp1;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter the Data onto the node\n");
    scanf("%d",&num);

    temp->data=num;
    temp->next=NULL;

    if(head==NULL)                    //insert first node.
    {
        head=temp;
    }
    else
    {
       struct node* temp1;                        //insert node append.
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void display(void)                            //displaying nodes of the linked list.
{
   struct node* temp;
   temp=head;
   printf("\ncurrent list is \n");

   while(temp!=NULL)
   {
           printf("%d->",temp->data);
           temp=temp->next;
   }
    printf("\n");

}

void rev_addr(void)                                    //reversing the nodes with addresses.
{
    struct node* curr;
    struct node* prev;
    struct node* nxt;
    curr=head;
    prev=NULL;

    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;                                    //three pointers for keeping track of nxt,prev,cur address values.
        prev=curr;
        curr=nxt;
    }

    struct node* temp;
       head=prev;                                        //making last node as head and printing till null.
       temp=head;
    printf("\nreverse linked list is\n");                //displaying the revverse linked list.
       while(temp!=NULL)
       {
           printf("%d->",temp->data);
           temp=temp->next;
       }

}

void sort(void)                                                        //soriing the data of the nodes of linked list.
{
    int count,i,j;
    struct node* temp1;
    struct node* temp2;
    count=len();
    for(i=1;i<count;i++)
    {
        temp1=head;
        temp2=temp1->next;
        for(j=1;j<count;j++)
        {
            temp2=temp1->next;
            if(temp1->data>temp2->data)
            {
                int temp;
                temp=temp1->data;
                temp1->data=temp2->data;
                temp2->data=temp;
            }
            temp1=temp2;
        }
    }
}

void rev_print_recursion(struct node* temp)
{
    if(temp->next!=NULL)
    {
        rev_print_recursion(temp->next);
    }
    printf("%d",temp->data);
}

void add_swap(void)                                    //function for sorting data using address swap's using bubble sort.
{
    int count,i,j;
    struct node* temp1;
    struct node* temp2;
    struct node* temp;
    count=len();
    for(i=1;i<count;i++)
    {
        temp1=head;
        temp2=temp1->next;
        for(j=1;j<count;j++)
        {
            temp2=temp1->next;
            if(temp1->data>temp2->data)
            {
                temp=temp1->next;
                temp1->next=temp2->next;
                temp2->next=head;
                head=temp2;
                temp2=temp1;
            }
            else
                temp1=temp2;
        }
    }
}

int main()                                            //main program starts from here.
{

       node();
       node();
       node();
       node();
 node();
       node();
       node();
       node();

   //    node();
    display();


  //  rev_data();
  //  display();

   // rev_addr();
   // display();

   // sort();
   // display();

    //rev_print_recursion(head);
    add_swap();
    display();



}

