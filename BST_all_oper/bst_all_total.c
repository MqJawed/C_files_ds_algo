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

int total(struct Node * root)
{   
    int toleft,toright;
    if (root == NULL)
        return 0;
    else
        {toleft = total(root->left);
        toright = total(root->right);
        return toleft + toright + 1;}
}

int total_internal(struct Node * root) // non leaf nodes
{   
    int toleft,toright;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right== NULL)
        return 0;
    else
        {toleft = total_internal(root->left);
        toright = total_internal(root->right);
        return toleft + toright+1;}
}

int total_external(struct Node * root) // leaf nodes
{   
    int toleft,toright;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right== NULL)
        return 1;
    else
        {toleft = total_external(root->left);
        toright = total_external(root->right);
        return toleft + toright;}
}

void main()
{
    struct Node * node1;
    struct Node * node2;
    struct Node * node3;
    struct Node * node4;                               //        22         //
    struct Node * node5;                               //       /  \       //           
    struct Node * node6;                               //      17   28     //
    struct Node * node7;                               //     / \   / \     //
    node1 = create_node(22);                           //   10  18  25  31  //
    node2 = create_node(17);
    node3 = create_node(28);
    node1->left = node2;
    node1->right = node3;
    node4 = create_node(10);
    node5 = create_node(18);
    node2->left = node4;
    node2->right = node5;
    node6 = create_node(25);
    node7 = create_node(31);
    node3->left = node6;
    node3->right = node7;
    printf("%d\n",total(node1));   
    printf("%d\n",total_internal(node1));
    printf("%d\n",total_external(node1));
}