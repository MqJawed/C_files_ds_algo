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

void inorder(struct Node * root)
{
    if (root==NULL)
    return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
    
}

void preorder(struct Node * root)
{
    if (root==NULL)
    return;
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);

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

int balance_factor(struct Node * node)
{
    if (node==NULL)
        return 0;
    else
        return (height(node->left)-height(node->right));
}

struct Node * rightrotation(struct Node * root)
{
    struct Node * temp;
    temp = root->left->right; // if no right child of root->left then temp == NULL;
    root->left->right = root;
    root = root->left;
    root->right->left = temp;
    return root;
    // NOTE : IN CASE OF LL right rotation is required
}

struct Node * leftrotation(struct Node * root)
{
    struct Node * temp;
    temp = root->right->left;
    root->right->left = root;                                //        22        
    root = root->right;                                      //       /  \                 
    root->left->right = temp;                                //      17   28     
    return root;                                             //     / \   / \     
                                                             //   10  18  25  31    
    // NOTE : IN CASE OF RR right rotation is required
}

struct Node * leftrightrotation(struct Node * root)
{
    root->left = leftrotation(root->left); // left rotation on child of first imbalance node 
    root = rightrotation(root);             // right rotation on first imbalance node
    return root;
    // IN CASE OF LR leftrightrotation is required
}

struct Node * rightleftrotation(struct Node * root)
{
    root->right = rightrotation(root->right); // right rotation on child of first imbalance node 
    root = leftrotation(root);             // left rotation on first imbalance node
    return root;
    // IN CASE OF RL rightleftrotation is required
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
    
    int bf = balance_factor(root); // balance factor of the ancestor node
    if (bf>1 && data < root->left->data)    // LL case
        return root = leftrotation(root);
    if (bf<-1 && data > root->left->data)   // RR case
        return rightrotation(root);
    if (bf>1 && data > root->left->data)    // LR case
        return leftrightrotation(root);
    if (bf<-1 && data < root->left->data)   // RL case
        return rightleftrotation(root);
    
    return root;
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
    // preorder(node1);
    // printf("\n");
    // node1 = rightrotation(node1);
    // preorder(node1);
    // printf("\n");
    // node1 = leftrotation(node1);
    // preorder(node1);
    // printf("\n");
    // node1 = leftrightrotation(node1);
    // preorder(node1);
    // printf("\n");
    // node1 = rightleftrotation(node1);
    // preorder(node1);
  //  printf("%d",balance_factor(node7));
     
}