#include<stdio.h>

void printarray(int a[],int n)
{
for (int i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
}

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

// In HEAP SORT we use array representation of binary tree; we will make a complete binary tree from that array(roughly not code)
// We will create a maxheap or heapify function which will determine the maximum value at a particular node (i)  in O(n) time 
// We will create the function heap sort which will exchange the last value and the root node value in O(nlogn) time

void max_heap(int a[], int n, int i) // n=size of the array
{
    // i is the index of the node
    int largest = i;
    int left = 2*i + 1;  // starting index is 0
    int right = 2*i + 2;
    if (left < n && a[largest] < a[left]) // max index can be n-1; now if left/right > n => no left/right child i.e. a[left] will contain garbage value
        largest = left;
    if (right < n && a[largest] < a[right])
        largest = right;
    if (largest!=i)
    {    swap(&a[largest], &a[i]);
         max_heap(a,n,largest); // this will be used only when every root node is greater than child node and deletion operation is performed
                                // i.e. line no. 48
    }
}

void heap_sort(int a[], int n)
{
    //int i = n/2 - 1; // will give the last nonleaf node
    for (int i= n/2 - 1; i>=0; i--) // loop to run max heap on every non leaf node till root node 
        max_heap(a,n,i);
    // now the root node contains the maximum value; exchange it with the last one
    for (int j=n-1; j>=0; j--)
    {
            swap(&a[0],&a[j]);
            max_heap(a,j,0); // run the loop to get the maximum again at the root node
    }                        //  as the last node is sorted reduce the size of the array; n = j = n-1   
    
}

void main()
{
int n;
int a[100];
printf("Enter the size of array: ");
scanf("%d",&n);
for (int i=0; i<n; i++)
scanf("%d",&a[i]);
printf("The array before sorting is:\n");
printarray(a,n);
heap_sort(a,n);
printf("\nThe array after sorting is:\n");
printarray(a,n);
} 