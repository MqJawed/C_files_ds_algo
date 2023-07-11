#include<stdio.h>

void flprintarray(float a[],int n)
{
for (int i=0;i<n;i++)
    {
    printf("%f\t",a[i]);
    }
    printf("\n");
}

void printarray(int a[],int n)
{
for (int i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    printf("\n");
}

void flswap(float * a, float * b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

void bubbleSort(float a[],int b[],int c[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] < a[j + 1])
            {
				flswap(&a[j], &a[j + 1]);
                swap(&b[j],&b[j + 1]);
                swap(&c[j], &c[j + 1]);
                
			}
		}
	}
}

void main()
{
    int i, n,cons;
    float profit = 0;
    printf("Enter the constraint: ");
    scanf("%d",&cons);
    printf("Enter the number of object: ");
    scanf("%d",&n);
    int w[n],p[n];
    float solvec[n];
    float pw[n];
    for (i = 0;i<n;i++)
    {
        printf("\nEnter the weight of product %d ",i+1);
        scanf("%d",&w[i]);
        printf("Enter the profit of product %d ",i+1);
        scanf("%d",&p[i]);
        pw[i] = (float)(p[i])/w[i];
        solvec[i] = 0;        
    }
    bubbleSort(pw,w,p,n);

    
    //  printarray(p,n);
    //  printarray(w,n);
    //  flprintarray(pw,n);

    for (int i = 0;i<n;i++)
    {
        if (cons > 0 && w[i] <=  cons)
        {
                cons -= w[i];
                profit += p[i];
                solvec[i] = 1;
        }
        else if(cons>0)
        {
            solvec[i] = (float)(cons)/w[i];
            profit += p[i] * solvec[i];
            cons = 0;
        }
    }
    printf("\nThe max profit is: %f\n",profit);
    printf("\nThe weight of the object sorted in decreasing of p/w order is: ");
    printarray(w,n);
    printf("\nThe solution vector is: ");
    flprintarray(solvec,n);
}