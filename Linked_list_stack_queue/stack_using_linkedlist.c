#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void push(struct Node ** top, int data)
{
    struct Node * newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    if ((*top)==NULL)
    {
        newnode->next==NULL;
        (*top)=newnode;
    }
    else
    {
        newnode->next=(*top);
        (*top)=newnode;
    }
    printf("Successfully pushed the element in the stack\n");
}

void pop(struct Node ** top)
{
    struct Node * p;
    if ((*top)==NULL)
        printf("Underflow\n");
    else
    {
        p=(*top);
        (*top)=(*top)->next;
        free(p);
    }
    printf("Successfully popped the element from the stack\n");
}

void display(struct Node ** top)
{
    struct Node * p;
    if ((*top)==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        p=(*top);
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
    struct Node * top;
    top=NULL;
    int data, c;
    
    while (c!=4)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter the data: ");
                scanf("%d",&data);
                push(&top,data);
                break;
            }
            case 2:
            {    
                pop(&top);
                break;
            }
            case 3:
            {    
                display(&top);
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