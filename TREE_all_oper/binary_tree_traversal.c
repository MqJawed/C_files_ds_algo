#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node * right;
};

struct Node * create_node(int data)
{
     struct Node * n;
     n = (struct Node * )(malloc(sizeof(struct Node)));
     n->left=NULL; // at the time of creation left right would be null
     n->right=NULL;
     n->data=data;
     return n;
}
void preorder(struct Node * root)
{
    if (root==NULL)
    return;
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);

}

void postorder(struct Node * root)
{
    if (root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);

}

void inorder(struct Node * root)
{
    if (root==NULL)
    return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
    
}

void main()
{

   struct Node * node1 = create_node(5);
   struct Node * node2 = create_node(6);
   struct Node * node3 = create_node(7);
   struct Node * node4 = create_node(8);
   struct Node * node5 = create_node(9);
   node1->left=node2;
   node1->right=node3;
   node1->left->left=node4;
   node1->left->right=node5;
   preorder(node1);
   postorder(node1);
   inorder(node1);
}