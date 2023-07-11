#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>

void printarray(int a[],int n)
{
	for (int i = 0; i<n; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void insert(int a[],int key, int index)
{
	a[index] = key;
	printf("\nThe index of the inserted key %d is %d\n",key,index);
}

void divhash(int a[],int size)
{
	int key;
	printf("Enter the value to be inserted: ");
	scanf("%d",&key);
	int index =  (key%size);
	insert(a,key,index);	
}

void mulhash(int a[],int size)
{
	int key;
	printf("Enter the value to be inserted: ");
	scanf("%d",&key);
	float n = key * 0.62;
	int p = floor(n);
	float frac = n-p;
	frac*=size;
	int index = floor(frac);
	insert(a,key,index);
}

void folhash(int a[],int size)
{
	char key[10];
	printf("Enter the value to be inserted: ");
	scanf("%s",key);
//	sprintf(key_str,"%d",key); // integer to string
	
	char key_i[2],key_ii[100];
	
	key_i[0]=key[0];
	key_i[1]=key[1];
	key_i[2]='\0';
    
	key_ii[0]=key[2];
 	key_ii[1]=key[3];
 	key_ii[2]='\0';
 	
	//int ind1 = atoi(key_i); // string to integer
	int ind1,ind2;
	sscanf(key_i, "%d", &ind1);
    sscanf(key_ii, "%d", &ind2);
    //printf("%d  %d",ind1,ind2);
    int index = (ind1 + ind2)%size;
	//printf("%d",index);
	long x;
	char * ptr;
	x = strtol(key,&ptr,10);
    //sscanf(key, "%d", &key_val);
	insert(a,x,index);
	//printf("\n%d\n",key_val);
	printf("\nThe index of the inserted key %ld is %d\n",x,index);
}

void mid(int a[],int size)
{
	char key[100];
	printf("Enter the value to be inserted: ");
	scanf("%s",key);
	char c = key[2];
	int x;
	x=(int)(c);
	printf("%d",x);
	int index =  (x*x);
	int key_val;
	sscanf(key, "%d", &key_val);
	insert(a,key_val,index);
}

void main()

{
	int n;
	int a[100];
	int size = 100;
	// letting the key size = 4
	// printf("Enter the size of array: ");
	// scanf("%d",&n);
	int ch;
	while (ch!=5)
	{	
		printf("\n1.Division Method\n2.Multiplication Method\n3.Mid^2 Method\n4.Folding Method\n5.Exit\nEnter choice: ");
		scanf("%d",&ch);
		
		switch (ch)
		{
			case 1:
			{
				divhash(a,size);
				break;
			}
			case 2:
			{
				mulhash(a,size);
				break;
			}
			case 3:
			{
				mid(a,size);
				break;
			}
			case 4:
			{
				folhash(a,size);
				break;
			}
			case 5:
			{
				break;
			}
			case 6:
			{
				printf("Enter a valid choice!\n");
			}
		}
				
	}
}


