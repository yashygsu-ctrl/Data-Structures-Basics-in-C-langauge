#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    int i, j = 0;
    char ch;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while(top != -1 &&
                 ((priority(stack[top]) > priority(ch)) ||
                 (priority(stack[top]) == priority(ch) && ch != '^')))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}
