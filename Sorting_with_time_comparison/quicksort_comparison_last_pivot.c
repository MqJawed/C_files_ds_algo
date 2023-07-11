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
    swap(&a[i+1],&x);
    return i+1; // partition function return the true index of the supposed pivot element 
}

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
	int n=10;
    printf("Size\tMerge\n");
	while (n<=1000000)
	{
	int a[n];
	takearray (a,n);
    int p,r;
    p=0;
    r=n-1;
	clock_t start,end,duration;
	start = clock();
	quicksort(a,p,r);
	end = clock();
	duration = end - start;
	double time = (double)duration/CLOCKS_PER_SEC;
	printf("%d\t%lf\n",n,time);
 	//printarray(a,n);
    n*=10;
 	}
}	
