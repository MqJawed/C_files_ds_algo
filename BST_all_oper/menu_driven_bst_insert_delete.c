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

struct Node * findlargest(struct Node * root)
{
//                                                  34
//                                                      89
//                                                          98       we'll get the highest only at right node
    struct Node * temp = root;     
     while (temp->right!=NULL)                
        temp = temp->right;
    return temp;
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
		}
		else if (root->right == NULL)   // no right child but may have left child
        {
			root= root->left;
		}
        // when the node which is to be deleted has 2 child

        else if (root->right != NULL && root->left != NULL)
        {
            struct Node * temp = findlargest(root->left);
            root->data = temp->data;
            root->left = delete(root->left,temp->data);  // temp=delete(temp,temp->data) will give same output
        }
    }  
   return root;
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
    int c=0,data;
    struct Node * root=NULL;
    while(c!=3)
    {
        printf("\n1.Insert\n2.Delete\n3.Exit\nEnter choice ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter data to insert : ");
                scanf("%d",&data);
                root = insert(root,data);
                printf("\nPreorder traversal: \n");
                preorder(root);
                printf("\nPostorder traversal: \n");
                postorder(root);
                printf("\nInorder traversal: \n");
                inorder(root);
                break;
            }
            case 2:
            {
                printf("Enter the data to delete: ");
                scanf("%d",&data);
                root = delete(root,data);
                printf("\nPreorder traversal: \n");
                preorder(root);
                printf("\nPostorder traversal: \n");
                postorder(root);
                printf("\nInorder traversal: \n");
                inorder(root);
                break;
            }
            case 3:
                break;
            default: 
            {
                printf("\nWrong choice\n");
                break;
            }
        }
    }
}