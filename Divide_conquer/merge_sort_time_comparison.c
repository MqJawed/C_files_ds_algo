#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void takearray(int *a,int n)
{	
	for (int i=0;i<n;i++)
	{
		int k = rand()%n;
		a[i] = k;
	}
}

void printarray(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}



void merge(int a[],int low,int mid,int high)
{
    int n1 = mid - low +1;
    int n2 = high - mid;
    int left[n1+1], right[n2+1];
    int i,j,k;
    for (i=0;i<n1;i++)
    {
        left[i] = a[low + i];
    }
    for (j=0;j<n2;j++)
    {
        right[j] = a[mid+1+j];
    } 
    left[n1]=1000001;//assigning sentinel value
    right[n2]=1000001; // assigning sentinel value
    i=j=0;
    for (k=low;k<=high;k++)
    {
        if (left[i]<=right[j])
            a[k]=left[i++];
        else
            a[k]=right[j++];
    }
}

void mergesort(int a[],int low,int high)
{
	if (low<high)
	{
		int mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void main()
{	
	int n=10;
    printf("Size\tMerge\n");
	while (n<=1000000)
	{
	int a[n];
	takearray (a,n);
	clock_t start,end,duration;
	start = clock();
	mergesort(a,0,n-1);
	end = clock();
	duration = end - start;
	double time = (double)duration/CLOCKS_PER_SEC;
	printf("%d\t%lf\n",n,time);
 	printarray(a,n);
    n*=10;
 	}
}	
