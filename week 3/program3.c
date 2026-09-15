
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
void push(int x)
{
    stack[++top] = x;
}


int pop()
{
    return stack[top--];
}


int evaluatePostfix(char postfix[])
{
    int i;
    int a, b, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

       
        if (isdigit(ch))
        {
            push(ch - '0');
        }

       
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;

                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}

