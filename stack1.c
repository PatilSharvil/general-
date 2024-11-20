#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack[++top] = c; 
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--]; // Return value before decrementing
    }
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3; // Highest precedence for exponentiation
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

void reverse(char exp[])
{
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int j = 0;

    for (int i = 0; infix[i]; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

void infixToPrefix(char infix[], char prefix[])
{
    reverse(infix); // Step 1: Reverse the infix expression

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; infix[i]; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix); // Convert to postfix

    reverse(postfix);
    strcpy(prefix, postfix); // Copy to prefix
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}