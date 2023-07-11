#include<stdio.h>
void root(int,int,int);
void main() 
{int a,b,c;
printf("Enter the coefficent of x^2: ");
scanf("%d",&a);
printf("Enter the coefficent of x: ");
scanf("%d",&b);
printf("Enter the constant term: ");
scanf("%d",&c);
root(a,b,c);
}
void root(int a,int b,int c)
{int p=(pow(b,2)-(4*a*c));
if (p>0)
{float q=sqrt(p);
float r1=(-b+q)/(2*a);
float r2=(-b-q)/(2*a);
printf("%f\n%f",r1,r2);}
else if (p==0)
{
float r=(-b)/(2*a);
printf("Roots are equal and is %f",r);}
else
printf("Roots are imaginary");
}