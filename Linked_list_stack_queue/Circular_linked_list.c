#include<stdio.h>
#include<stdlib.h>

struct Node 
{
		int data;
		struct Node * next;
};
	
void create_cll(struct Node ** head,int data)
{
	struct Node * p = (*head);
	struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
	if ((*head)==NULL)
	{
		ptr->next=ptr;
		(*head)=ptr;
	}	
	else
	{
		while (p->next!=(*head))
		{
			p=p->next;
		}
		ptr->next=p->next;
		p->next=ptr;
	}
	ptr->data=data;
}
void insertaf(struct Node ** head,int index,int data)
{	
	
		struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
		struct Node * p=(*head);
		int i=1;
		while (i!=index)
		{
			p=p->next;
			i++;
		}
		ptr->next=p->next;
		p->next=ptr;
	
	ptr->data=data;	
}

void insertbf(struct Node ** head,int index,int data)
{	
	
		struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
		struct Node * p=(*head);
		int i=1;
		while (i!=(index-1))
		{
			p=p->next;
			i++;
		}
		ptr->next=p->next;
		p->next=ptr;
	
	ptr->data=data;	
}

void deletefir(struct Node ** head)
{
	struct Node * p=(*head);
	if ((*head)==NULL)
		printf("Underflow");
	else
	{	while (p->next!=(*head))
			p=p->next;
		p->next=(*head)->next;
		free((*head));
		(*head)=p->next;
	}
}

void deletelas(struct Node ** head)
{
	struct Node * p=(*head);
	struct Node * q;
	if ((*head)==NULL)
		printf("Underflow");
	else
	{	q=p->next;
		while (q->next!=(*head))
			{q=q->next;
			p=p->next;
			}
		p->next=(*head);
		free(q);
	}
}

void totaldel(struct Node ** head)
{
	struct Node * p=(*head);
	while (p->next!=NULL)
	{
	p=p->next;
	free((*head));
	(*head)=p;
	}
}

void traversal(struct Node ** head)
{
	struct Node * ptr = (*head);
	if ((ptr)==NULL)
		printf("Underflow");
	// else if ((ptr)->next==(*head))
	// 	printf("%d",(ptr)->data);
	else
	{
		while((ptr)->next!=(*head))
		{
			printf("%d",(ptr)->data);
			(ptr)=(ptr)->next;
		}
		printf("%d",(ptr)->data);
	}
}

void main()
{
	struct Node * head=NULL;
	create_cll(&head,5);
	create_cll(&head,6);
	create_cll(&head,7);
	insertbf(&head,2,4);
	insertaf(&head,1,8);
	deletefir(&head);
	deletelas(&head);
	//totaldel(&head);
	traversal(&head); 
	
	
}














