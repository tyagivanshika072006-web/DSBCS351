#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char x) {
    stack[++top] = x;
}


char pop() {
    return stack[top--];
}


int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}


void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++) {

       
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

       
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  
        }

       
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }
    }

    
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}