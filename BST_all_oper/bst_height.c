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

int height(struct Node * root)
{   
    int left_height,right_height;
    if (root == NULL)
        return 0;
    else
        left_height = height(root->left);
        right_height = height(root->right);
        if (left_height > right_height)
            return left_height+1;
        else                                // for both right>=left; cause when left=right can increment any of these
            return right_height+1;
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
    printf("%d",height(node1)-1);   
  
}