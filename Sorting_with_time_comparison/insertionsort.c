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

void insertion_sort(int a[],int n)
{int key;
    for (int i=1;i<=n-1;i++)
    {    key=a[i];
        int j=i-1;
        while (a[j]>key&&j>=0)
        {    a[j+1]=a[j];
             j--;             
        }//now j becomes -1
    a[j+1]=key;
    }
}

void main()
{
int a[]={5,4,6,3,7,2};
int n=sizeof(a)/sizeof(int);
printf("The array before sorting is:\n");
printarray(a,n);
insertion_sort(a,n);
printf("\nThe array after sorting is:\n");
printarray(a,n);
} 