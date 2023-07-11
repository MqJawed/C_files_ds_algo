#include<stdio.h>
#include<math.h>
#define f(y) 4*y-3*y*y
void main()
{
float x[100],y[100];
int a,b,n,i,j;
a=0;      // this will change for different lower limit
b=1;     // this will change for different upper limit
n=10;   // this will change for different value of interval
float h=(float)(b-a)/n;

for (i=0;i<=n;i++)
    {
        x[i]=a+i*h;
    
       y[i]=f(x[i]);  // this will change for different types of function f(x)
    
    }
    //printf("%f %f\n",x[9],y[9]);
float trap=0;
for (j=1;j<=n-1;j++)
    {
    trap+=y[j];
    }

float integration = (h/2)*(y[0]+y[10]+2*trap);
printf("The integration of the given function is %f",integration);
}