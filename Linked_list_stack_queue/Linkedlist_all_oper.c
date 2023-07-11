#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
    int data;
    struct Node * next;
 };
void create_first(struct Node ** head,int data) // either use ** head or return head so that actual head in the main will get updated
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    if ((*head)==NULL)
    {
        (*head)=ptr;
        ptr->next=NULL;
    }
    else
    {
        (*head)->next=ptr;
        ptr->next=NULL;
    }

}

void traversal(struct Node ** head)
{
    struct Node * ptr=(*head);
    if ((*head)==NULL)
    {
        printf("UNDERFLOW");
    }
    else
    {
        while (ptr!=NULL) // if we write ptr->next!=NULL ptr when ptr will reach the last node, loop will not be entered hence, last node data will not be printed
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void append(struct Node ** head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=(*head)->next;
    (*head)->next=ptr;
    //printf("%d",ptr->data); 
}

void appendatindex(struct Node ** head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=(*head)->next;
    (*head)->next=ptr;
    //printf("%d",ptr->data); 
}

int count(struct Node ** head)
{
    struct Node * ptr=(*head);
    int cal=0;
    if (ptr==NULL)
    return cal;
    else
    {
        while (ptr!=NULL)
        {
            cal++;
            ptr=ptr->next;
        }
    return cal;
    }
}
void search(struct Node ** head,int data)
{
    struct Node * ptr=(*head);
    int cal=0,flag;
    if ((*head)==NULL)
    {
        printf("No element!");
    }
    else
    {
        while(ptr!=NULL)
        {   cal++;
            if (ptr->data==data)
            {//ptr=ptr->next; not require to change ptr!!
            flag=1;
            break;
            }
            else
         {
            ptr=ptr->next;
            flag=0;
        }
        }
        if (flag==0)
        printf("Element not present");
        else
        printf("THe element is found at index %d",cal);
    }
}

void deletefirst(struct Node ** head)
{
    struct Node * p=(*head);
    if ((*head)==NULL)
    {
        printf("Underflow!");
    }
    else
    {
        (*head)=(*head)->next;
        free(p);
    }
}
void deletelast(struct Node ** head)
{
    struct Node * p=(*head);
    //struct Node *q;
    if ((*head)==NULL)
    {
        printf("Underflow!");
    }
    else
    {
        struct Node *q;  
        q=(*head)->next;
         while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;    
    }
        p->next=NULL;
        free(q);
    }
}

void main()
{
    int data;
    struct Node * head=NULL;
    struct Node * q;
    printf("Enter the data: ");
    scanf("%d",&data);
    create_first(&head,data);
    append(&head,data);
    append(&head,data);
    append(&head,data);
    traversal(&head);
//     printf("%d",count(&head));
//     search(&head,457);
//     deletelast(&head);
//    deletefirst(&head);
//    deletefirst(&head);
//    deletefirst(&head);
//   deletelast(&head);
//   deletelast(&head);
//     traversal(&head);
   // printf("%d",head->data);
}