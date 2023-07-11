#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

// Given a reference (pointer to pointer) to
// the head of a list and an int, appends a
// new node at the end
// Given a reference (pointer to pointer) to
// the head of a list and an int, appends a
// new node at the end
void append(struct Node** head_ref,
			int new_data)
{
	// 1. Allocate node
	struct Node*ptr =
		(struct Node*) malloc(sizeof(struct Node));

	// Used in step 5
	struct Node *p = *head_ref;

	// 2. Put in the data
	ptr->data = new_data;


	// 4. If the Linked List is empty, then make
	// the new node as head
	if (*head_ref == NULL)
	{
	*head_ref = ptr;
    return;
	}
	
	// 5. Else traverse till the last node
	while (p->next != NULL)
		p = p->next;

// 3. This new node is going to be the
	// last node, so make next of it as NULL
	ptr->next =NULL;
	// 6. Change the next of last node
	p->next = ptr;
    return;
    
}


struct Node*insertatend(struct Node * head,int data)
{
    struct Node *ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    if (head==NULL)
    {
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
   // printf("without while\n");
    
    }
    else
    {
        struct Node * p=head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
  //  printf("while");
       return head;
    }
 
}

int calc(struct Node * head)
{   int c=1;
    struct Node * p=head;
    if (head==NULL)
    return 0;
    else
    {
    while (p->next!=NULL)
    {
        p=p->next;
        c++;
        
    }
    return c;
    }
}

void Afterindex(struct Node ** head_ref, int index, int data)
{
    struct Node *ptr;
    struct Node * p=*head_ref;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    if (*head_ref==NULL)
    {
    ptr->data=data;
    ptr->next=*head_ref;
    *head_ref=ptr;
    }
    else if (index>0&&index<=5)
    {   int i = 1;
        while (i!=index)
        {
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
    }
    else 
   { printf("Invalid");
   }
}

void traversal(struct Node * ptr)
{   
     if (ptr==NULL)
     printf("Underflow");
     else
     {
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
     }
}

void main()
{   
   
    struct Node *head,*temp;
     head=NULL;
  // ptr=(struct Node *)malloc(sizeof(struct Node));
    int new_data;
  // for (int i=0;i<=2;i++){
   
   
 printf("Enter the data: ");
 scanf("%d",&new_data);
append(&head, new_data);

   //printf("%d",head->data);
 printf("Enter the data: ");
 scanf("%d",&new_data);
append(&head, new_data);

printf("Enter the data: ");
 scanf("%d",&new_data);
append(&head, new_data);


Afterindex(&head, 2, 98);
temp=head;
traversal(head);
head=temp;
printf("%d",calc(head));
}
