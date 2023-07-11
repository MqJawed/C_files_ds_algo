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

void selection_sort(int a[],int n)
{   for (int i=0;i<n-1;i++)
    {   int maxindex=0;
        for (int j=1;j<=n-1-i;j++)
            {    
                 if (a[j]>a[maxindex])
                maxindex = j;
            } 
        swap(&a[maxindex],&a[n-1-i]);
            
     }
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
selection_sort(a,n);
printf("\nThe array after sorting is:\n");
printarray(a,n);
} 