#include<stdio.h>
#include<math.h>
#define f(x) pow(x,3)-(8*x)-4

void main()
{ int a,b;
float x0,x1,x2,eps;
do{
printf("\nEnter the two guesses of root:\n ");
scanf("%d%d",&a,&b);
if ((f(a))*(f(b))<0)
break;
else
printf("The guesses are incorrect  Guess again");
}while(1);
// To check at which value function is neg or pos
// To make function negative at x0 and positive at x1 
if (f(a)<0&&f(b)>0)
    { x0=a;
      x1=b;
    }
else if (f(a)>0&&f(b)<0)
    { x0=b;
      x1=a;
    }
printf("\nFunction is negative at %f and positive at %f \n",x0,x1);
printf("\nEnter the EPS value: ");
scanf("%f",&eps);

while(fabs(f(x2))>eps)//x2 is gradually decreasing and at a certain value, fx2 will become almost zero. Now if it is less than eps that mean it has acquired zeros simialr to the eps' zero
{x2=(x0*(f(x1))-x1*(f(x0)))/(f(x1)-f(x0));
if (f(x2)<0)
x0=x2;
else if (f(x2)>0)
x1=x2;
else
break;
printf("€\n");
}
printf("The root is %f",x2);
}