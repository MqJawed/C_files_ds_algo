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

void bubble_sort(int a[],int n)
{
for (int i=0;i<n-1;i++)
    { for (int j=0;j<n-1-i;j++)
      {    if (a[j]>a[j+1]) 
          {swap(&a[j],&a[j+1]);
          }
    }
    }
}

void main()
{
int a[]={5,4,6,3,7,2};
int n=sizeof(a)/sizeof(int);
printf("The array before sorting is:\n");
printarray(a,n);
bubble_sort(a,n);
printf("\nThe array after sorting is:\n");
printarray(a,n);
} 