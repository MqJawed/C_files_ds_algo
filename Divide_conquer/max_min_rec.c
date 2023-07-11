#include<stdio.h>

int max,min;
void max_min(int a[],int i,int j)
{
	int max1,min1,mid;
	if (i == j)
	{	max = min =a[i];
	}
	
	else if (i == j-1)
	{
		if (a[i]<a[j])
		{
			max = a[j];
			min = a[i];
		}
		else
		{
			max = a[i];
			min = a[j];
		}
	
	}
	else
	{	
		mid = (i+j)/2;
		max_min(a,i,mid);
		max1 = max;
		min1 = min;
		max_min(a,mid+1,j);
		if (max<max1)
			max = max1;
		if (min>min1)
			min = min1;
	}
}

void main()
{
	int n;
	int a[10];
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the element %d : ",i+1);
		scanf("%d",&a[i]);
	}	
	int p,q;
	p=0;
	q=n-1;
	max_min(a,p,q);
	printf("max = %d	min = %d",max,min);
}























