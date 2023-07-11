#include<stdio.h>

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}


void max_heap(int a[], int n, int i) 
{
    
    int largest = i;
    int left = 2*i + 1; 
    int right = 2*i + 2;
    if (left < n && a[largest] < a[left])
        largest = left;
    if (right < n && a[largest] < a[right])
        largest = right;
    if (largest!=i)
    {    swap(&a[largest], &a[i]);
         max_heap(a,n,largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i= n/2 - 1; i>=0; i--) 
        max_heap(a,n,i);
    for (int j=n-1; j>=0; j--)
    {
            swap(&a[0],&a[j]);
            max_heap(a,j,0);
    }                       
    
}

void main()
{
    int i,j,n,value;
    printf("Enter the number of coins: ");
    scanf("%d",&n);
    int coin[n],sortcoin[n],coinlist[n],solvec[n];
    for (i=0;i<n;i++)
    {
        printf("Enter the coin %d : ",i+1);
        scanf("%d",&coin[i]);
        sortcoin[i] = coin[i];
        solvec[i] = 0;
    }
    heap_sort(sortcoin,n);
    printf("\nEnter the value: ");
    scanf("%d",&value);
    
   // COINLIST GENERATION USING GREEDY
    for (i = n-1;i>=0;i--)
    {
        while(value>=sortcoin[i])
        {
            value -= sortcoin[i];
            coinlist[j++] = sortcoin[i];
        }
    }
    coinlist[j] = -1;
    
    // UPDATION OF SOLUTION VECTOR W.R.T COIN
    for (i = 0;i<n;i++)
    {   
        j = 0;
        while(coinlist[j] != -1)
        {
            if (coin[i] == coinlist[j++])
                solvec[i] += 1;
        }
    }
    
    // PRINTING THE COINLIST & SOLUTION VECTOR
    i = j = 0;
    printf("The coin used are: ");
    while(coinlist[j] != -1)
        printf("%d\t",coinlist[j++]);
    printf("\nThe solution vector is : ");
    while (i<n)
        printf("%d\t",solvec[i++]);

}