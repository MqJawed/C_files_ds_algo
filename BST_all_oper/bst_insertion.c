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

struct Node * insert(struct Node * root, int data)
{
    if (root == NULL)
        root = create_node(data);
    else if (data < root->data)
        root->left=insert(root->left,data);
    else
       root->right= insert(root->right,data);
    return root;
} 

void postorder(struct Node * root)
{
    if (root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);

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
    node1 = insert(node1,5);  
    postorder(node1);
} 