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

struct Node * findlargest(struct Node * node)
{
//                                                  34
//                                                      89
//                                                          98       we'll get the highest only at right node
    // struct Node * temp = root;     
    //  while (temp->right!=NULL)                
    //     temp = temp->right;
    // return temp;
    if (node == NULL)
        return node;
    if (node->right == NULL)
        return node;
    else 
       findlargest(node->right); // in case of insertion or deletion we return function to a node and that node is returned to its parent so that 
                                    // the connections remains proper but here we want to return the last node
}

struct Node * delete(struct Node * root, int data)
{
    if (data < root->data)                  // when data is less than node data
        root->left = delete(root->left,data);
    else if (data > root->data)                 // when data is greater than node data
        root->right = delete(root->right,data);
    else if (data == root->data)                // when data is equal to node data
    {   
        // when the node which is to be deleted has either one child or no child

        if (root->left == NULL)     // no left child but may have right child
        {
		    root = root->right;
           // if no right also, then it will be null
		}
		else if (root->right == NULL)   // no right child but may have left child
        {
			root= root->left;
            // if no left also, then it will be null
		}
        // when the node which is to be deleted has 2 child

        else if (root->right != NULL && root->left != NULL)
        {
            struct Node * temp = findlargest(root->left);
            root->data = temp->data;
            root->left = delete(root->left,temp->data);      // temp = delete(temp,temp->data);
        }
    }  
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
    inorder(node1);
    printf("\n");
    node1 = delete(node1,22);
    inorder(node1);
}