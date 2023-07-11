#include<stdio.h>

int isoperater(char c)
{
	if (c=='+' || c=='-' || c=='*'|| c=='/')
		return 1;
	else 
		return 0;
}
void eval(char postfix[])
{	
	int stack[100];
	int top=-1;
	int i=0;
	while(postfix[i]!='\0')
	{
		if (!isoperater(postfix[i]))
		{
			int temp=(int)(postfix[i++]);
			stack[++top]=temp-48;
		}
		else
		{
			char c=postfix[i++];
			switch (c)
			{
				case '+':
				{
					int a= stack[top--];
					int b= stack[top--];
					int result = b+a;
					stack[++top]=result;
					break;
				}
				case '-':
				{
					int a= stack[top--];
					int b= stack[top--];
					int result = b-a;
					stack[++top]=result;
					break;
				}
				case '/':
				{
					int a= stack[top--];
					int b= stack[top--];
					int result = b/a;
					stack[++top]=result;
					break;
				}
				case '*':
				{
					int a= stack[top--];
					int b= stack[top--];
					int result = b*a;
					stack[++top]=result;
					break;
				}
			}
		}
	}
	printf("The result value is : %d",stack[top--]);
}

void main()
{
	char postfix[100];
	printf("Enter the postfix expression: ");
	scanf("%s",postfix);	
	eval(postfix);
	
}
