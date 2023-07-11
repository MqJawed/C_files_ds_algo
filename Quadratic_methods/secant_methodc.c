#include<stdio.h>
#include<math.h>
#define f(x) pow(x,3)-(8*x)-4

void main()
{ float a,b;
float x[100],eps,root;
do{
printf("\nEnter the two guesses of root:\n ");
scanf("%f%f",&a,&b);
if ((f(a))*(f(b))<0)
break;
else
printf("The guesses are incorrect  Guess again");
}while(1);
// To check at which value function is neg or pos
// To make function negative at x0 and positive at x1 
if (f(a)<0&&f(b)>0)
    { x[0]=a;
      x[1]=b;
    }
else if (f(a)>0&&f(b)<0)
    { x[0]=b;
      x[1]=a;
    }
printf("\nFunction is negative at %f and positive at %f \n",x[0],x[1]);
printf("\nEnter the EPS value: ");
scanf("%f",&eps);
int i=2;
do//x2 is gradually decreasing and at a certain value, fx2 will become almost zero. Now if it is less than eps that mean it has acquired zeros simialr to the eps' zero
{x[i]=(x[i-2]*(f(x[i-1]))-x[i-1]*(f(x[i-2])))/(f(x[i-1])-f(x[i-2]));

root=x[i];/*if (f(x2)<0)
x0=x2;
else if (f(x2)>0)
x1=x2;
else
break;
if (i==2)
printf("1st approx root is %f",x[i]);
else if (i==3)
printf("2nd approx root is %f",x[i]);
else if (i==4)
printf("3rd approx root is %f",x[i]);
else
printf("%dth approx root is %f",(i-1),x[i]);
*/}while(fabs(f(x[i]))>eps);
printf("The root is %f",root);
}