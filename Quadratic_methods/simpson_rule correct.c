#include<stdio.h>
#define f(y) 4*y-3*y*y// this function will change for different function
// this means value of f(y)=4*y-3*y*y;
#include<math.h>

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
    
       y[i]=f(x[i]); // using x[i] instead of y in line 2 does'nt matter;
    // this line means y[i] = f(x[i]) = 4*x[i]-3*x[i]*x[i];
    }
    //printf("%f %f\n",x[9],y[9]);
float simp_odd=0,simp_even=0;
for (j=1;j<=n-1;j++)
    {    if (j%2==0)
         simp_even+=y[j];
         else
        simp_odd+=y[j];
    }

float integration = (h/3)*(y[0]+y[10]+(4*simp_odd)+(2*simp_even));
printf("The integration of the given function is %f",integration);
}