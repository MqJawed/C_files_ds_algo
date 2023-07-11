#include<stdio.h>

int preced(char a)
{
	if (a == '*' || a == '/')
		return 2;
	else if (a == '+' || a == '-')
		return 1; 
}

int isoperater(char c)
{
    if (c == '/' || c == '*' || c == '+' || c == '-')
    return 1;
    else 
    return 0;
}

void reverse(char a[],char ac[])
{
    int i=0,j=0;
    while(a[i+1]!='\0')
		i++;
	while (i>=0)
	{
		ac[j]=a[i];
		i--;j++;
	}
}

void main()
{
	int i=0,j=0;
	char a[100];
	printf("Enter the expression: ");
	scanf("%s",a);
	
	// reversing the expression
	char b[100];
    reverse(a,b);
//	printf("%s",b);
	char s[100];
	int top=-1;
	char new[100];
	int l=0,k=0;
	while (b[k]!='\0')
	{
		if (isoperater(b[k]))
		{
			if (top == -1)
	    		s[++top] = b[k++];
			else if (preced(b[k])>preced(s[top]))
				s[++top] = b[k++];
			else
				new[l++] = s[top--];
		}
		else 
			new[l++] = b[k++];
	}
	while (top != -1)
		new[l++] = s[top--];
   // printf("%s",new);
	// again reversing the postfix expression
	char prefix[100];
	reverse(new,prefix);
	printf("The prefix expression is %s",prefix);
}

// NB: if we are not using is operator than write condition in this 
// 		((b[k] == '/' || b[k] == '*' || b[k] == '+' || b[k] == '-')) two paranthesis as we are using third bracket