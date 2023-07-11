#include<stdio.h>

void printarray(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d   ",a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int a[], int p, int r)
{
    int x = a[r];  // supposing last element as pivot;
    int i=p-1;
    int j=p;
    for (;j<=r-1;j++)
    {
        if (a[j]<=x)
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1; // partition function return the true index of the supposed pivot element 
}

// int partition(int a[], int p, int r)
// {
//     int x = a[p];  // supposing first element as pivot;
//     int i=r+1;
//     int j=r;
//     for (;j>=p+1;j--)
//     {
//         if (a[j]>x)
//         {
//             i=i-1;
//             swap(&a[i],&a[j]);
//         }
//     }
//     swap(&a[i-1],&a[p]);
//     return i-1;
// }

void quicksort(int a[],int p,int r)
{
    if (p<r)
    {
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

void main()
{
    int a[]={6,5,7,4,8,3,9};
    int n=sizeof(a)/sizeof(int);
    printarray(a,n);
    int p=0,r=n-1;
    quicksort(a,p,r);
    printarray(a,n);
}