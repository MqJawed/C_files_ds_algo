#include<stdio.h>
#include<time.h>
int linear_search(int a[],int,int);
void main()
{int n,element;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {printf("Enter the element %d ",i+1);
    scanf("%d",&a[i]);
    }
    printf("Enter the element you want to find: ");
    scanf("%d",&element);
    clock_t start = clock();
    int p=linear_search(a,n,element);// at the time of function call we'll not call a[]
    clock_t end = clock();
    clock_t duration = end - start;
    printf("%f",(float)duration/CLOCKS_PER_SEC);
    printf("The element of array is  %d element",p+1);
}
int linear_search(int a[],int n,int element)
{    
    
    for (int i=0;i<n;i++)
    {    if (a[i]==element)
         return i;
            
    }
    return -1;    
}