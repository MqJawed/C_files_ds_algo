#include<stdio.h>

int isempty(int * top)
{
    if ((*top)==-1)
    return 1;
    else
    return 0;
}

void push(int *top, char c[],char data)
{
    (*top)+=1;
    c[(*top)]=data;    
}

char pop(int * top,char c[])
{
    char val=c[(*top)];
    (*top)-=1;
    return val;
}

int preced(char c)
{
    if (c == '/' || c == '*') // character in c will never be in double quotation
    return 2;
    else if (c == '+' || c == '-')
    return 1;
    else
    return 0;
}

int isoperater(char c)
{
    if (c == '/' || c == '*' || c == '+' || c == '-')
    return 1;
    else 
    return 0;
}

void intopo(char infix[])
{
    char postfix[100];
    char stack[100];
    int top=-1;
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        if(!isoperater(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if (isempty(&top))
                push((&top),stack,infix[i++]);
            else
            {   
                if (preced(infix[i]) > preced(stack[top]))
                    push((&top),stack,infix[i++]);
                else 
                   postfix[j++]=pop(&top,stack);                
            }
        }
    }
    while (!isempty(&top))
        postfix[j++]=pop((&top),stack);
    
    printf("%s",postfix);
}

void eval(char postfix[])
{
    int stack[100];
    int top=-1;
    int i=0;
    while (postfix[i]!='\0')
    {
        if(!isoperater(postfix[i]))
        {
            int temp = (int)(postfix[i++]);
            stack[++top] = temp-48;
        }
        else
        {
            int a = stack[top--];
            int b = stack[top--];
            int cal;
            char c = postfix[i++];
            switch(c)
            {
                case '+':
                {
                    cal = b+a;
                    stack[++top] = cal;
                    break;
                }
                case '-':
                {
                    cal = b-a;
                    stack[++top] = cal;
                    break;
                }
                case '*':
                {
                    cal = b*a;
                    stack[++top] = cal;
                    break;
                }
                case '/':
                {
                    cal = b/a;
                    stack[++top] = cal;
                    break;
                }
            }
        }
    }
printf("%d",stack[top--]);
}

void main()
{
    // char infix[100];
    // printf("Enter the infix expression: ");
    // scanf("%s",infix); //'\0' will be automatically added at the end of a string
    // printf("The equivalent postfix expression is :\n");
    // intopo(infix);
    char postfix[100];
    scanf("%s",postfix);
    eval(postfix);

    
}