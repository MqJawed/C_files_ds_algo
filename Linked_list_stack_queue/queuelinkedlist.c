#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void insert(struct Node ** front,struct Node ** rear, int data)
{
    struct Node * newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    if ((*front)==NULL)
    {
        newnode->next==NULL;
        (*front)=(*rear)=newnode;
        (*rear)->next=NULL;
    }
    else
    {
        newnode->next=NULL;
        (*rear)->next=newnode;
        (*rear)=newnode;
    }
    printf("Successfully inserted the element in the Queue\n");
}

void delete(struct Node ** front)
{
    struct Node * p;
    if ((*front)==NULL)
        printf("Underflow\n");
    else
    {
        p=(*front);
        (*front)=(*front)->next;
        free(p);
    }
    printf("Successfully deleteed the element from the Queue\n");
}

void display(struct Node ** front)
{
    struct Node * p;
    if ((*front)==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        p=(*front);
        while (p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void main()
{
    struct Node * front, * rear;
    front=rear=NULL;
    int data, c;
    
    while (c!=4)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter the data: ");
                scanf("%d",&data);
                insert(&front,&rear,data);
                break;
            }
            case 2:
            {    
                delete(&front);
                break;
            }
            case 3:
            {    
                display(&front);
                break;
            }
            case 4:
                break;
            default :
            {   
                 printf("\nEnter a correct choice: ");
                break;
            }    
        }
    }
}