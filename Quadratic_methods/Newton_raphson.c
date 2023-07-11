#include<stdio.h>
#include<math.h>
#define f(x) pow(x,3)-(8*x)-4
#define g(x) 3*pow(x,2)-8
void main()
{
float a,x[100],eps,root;

printf("\nEnter the guess of root:\n");
scanf("%f",&a);
printf("\nEnter the EPS value: ");
scanf("%f",&eps);

int i=0;
x[i]=a;
while(fabs(f(x[i]))>eps)//x2 is gradually decreasing and at a certain value, fx2 will become almost zero. Now if it is less than eps that mean it has acquired zeros simialr to the eps' zero
{x[i+1]=x[i]-(f(x[i]))/(g(x[i]));
root =x[i+1];
//printf("\n%d approx root is %f\n",i+1,x[i+1]);
i++;
}
printf("The root is %f",root);
}