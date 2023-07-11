#include <stdio.h>
#include <stdlib.h>//for rand()
#include <time.h>

void printarray(int a[], int n)
{
    for(int i = 0;i<n;i++)
        printf("%li  ",a[i]);
    printf("\n");
}

void takearray(int * a, int n)
{
    for(int i = 0;i<n;i++)
    {
        int k = rand()%n;
        a[i] = k;
    }
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// Bubble sort
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

// Insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Selection sort
void selectionSort(int arr[], int n)
{
	int i, j, midx;

	for (i = 0; i < n - 1; i++) {


		midx = i;

		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[midx])
				midx = j;


		swap(&arr[midx], &arr[i]);
	}
}

int linear_search(int a[],int n,int element)
{    
    
    for (int i=0;i<n;i++)
    {    if (a[i]==element)
         return i;
            
    }
    return -1;    
}

void main()
{
	//clock_t str = clock();
    //printf("%d",CLOCKS_PER_SEC);
	int n = 10;
    double time[4];
	

	printf("Size\tBubble\t\tInsertion\tSelection\tLinear_search\n");


	while (n <= 1000000)
    {
		int a[n], b[n], c[n];

		takearray(a,n);
        takearray(b,n);
        takearray(c,n);
		

		// using clock_t to store time
		clock_t start, end,duration;

		// Bubble sort
		start = clock();
		bubbleSort(a, n);
// 		printarray(a,n);
		end = clock();

		duration = end-start;
        time[0] = (double)duration/CLOCKS_PER_SEC;

		// Insertion sort
		start = clock();
		insertionSort(b, n);
// 		printarray(a,n);
		end = clock();

		duration = end-start;
        time[1] = (double)duration/CLOCKS_PER_SEC;

		// Selection sort
		start = clock();
		selectionSort(c, n);
// 		printarray(a,n);
		end = clock();

		duration = end-start;
        time[2] = (double)duration/CLOCKS_PER_SEC;

        // linear search
		start = clock();
		int search = linear_search(a, n, 5985);
		end = clock();

		duration = end-start;
        time[3] = (double)duration/CLOCKS_PER_SEC;

		printf("%d \t%lf  \t%lf  \t%lf  \t%lf\n",n, time[0],time[1],time[2],time[3]);

		n *= 10;
	}
}
