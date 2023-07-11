#include<stdio.h>

void printarray(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void main()
{
    int a[100];
    int n,index,elem;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter the element %d: \n",i+1);
        scanf("%d",&a[i]);
    }
    printf("The array before deletion is:\n");
    printarray(a,n);
    printf("Enter the element to delete: ");
    scanf("%d",&elem);
    for (int i=0;i<n;i++)
    {
        if (a[i]==elem)
        {    index=i;
            break;
        }
    }
    for (int i=0;i<n-1;i++)
    {
        if (i<index)
            continue;
        else
            a[i]=a[i+1];
    }
    printf("The array after insertion is:\n");
    printarray(a,n-1);
}