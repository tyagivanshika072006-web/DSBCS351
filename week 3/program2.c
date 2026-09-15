
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[])
{
    char postfix[MAX];
    char prefix[MAX];
    int i, j = 0;
    char ch;

  
    reverse(infix);

   
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        
        else if (ch == '(')
        {
            push(ch);
        }

        
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); 
        }

        
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) > precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    

