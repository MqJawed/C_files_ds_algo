#include<stdio.h>

int binary_search(int a[],int size,int elem)
{
    int mid,low=0,high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if (a[mid]==elem)
           { return mid;break;}
        else if (a[mid]<elem)
            low = mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int rec_bin(int a[],int low,int high,int elem)
{
        int  mid=(low+high)/2;
        if (a[mid]==elem)
            return mid;
        else if (a[mid]<elem)
            return rec_bin(a,mid+1,high,elem);
        else
            return rec_bin(a,low,mid-1,elem);
}

void main()
{
    int n,a[100],elem,p,c;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter the element %d: \n",i+1);
        scanf("%d",&a[i]);
    }
         printf("Enter the element to find: ");
        scanf("%d",&elem);
        while (c!=3)
        {   printf("\n1.Non recursive binary search\n2.Recursive binary search\n3.Exit\nEnter choice:\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1: 
                {
                    printf("\nNon recursive binary search is running: \n");
                    p=binary_search(a,n,elem);
                    if (p!=-1)
                        printf("The element is found at index %d\n",p);
                    else
                        printf("The element is not presesnt");
                    break;

                }
                 case 2: 
                {
                    printf("\nRecursive binary search is running: \n");
                    int low=0,high=n-1;
                    p=rec_bin(a,low,high,elem);
                    printf("The element is found at index %d\n",p);
                    break;

                }
                case 3: 
                    break;
                default : 
                    printf("\nChoose a correct alternative\n");
                    break;
            }
        }
    
}