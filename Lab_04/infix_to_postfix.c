#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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

char peek()
{
    return stack[top];
}

int isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int precedence(char x)
{
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    if(x == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    top = -1;

    while(infix[i] != '\0')
    {
        symbol = infix[i];

        if(isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else if(symbol == '(')
        {
            push(symbol);
        }
        else if(symbol == ')')
        {
            while(!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while(!isEmpty() &&
                 (precedence(peek()) > precedence(symbol) ||
                 (precedence(peek()) == precedence(symbol) && symbol != '^')))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }

        i++;
    }

    while(!isEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int i = 0;
    int valStack[MAX];
    int valTop = -1;

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            valStack[++valTop] = postfix[i] - '0';
        }
        else
        {
            int op2 = valStack[valTop--];
            int op1 = valStack[valTop--];

            switch(postfix[i])
            {
                case '+': valStack[++valTop] = op1 + op2; break;
                case '-': valStack[++valTop] = op1 - op2; break;
                case '*': valStack[++valTop] = op1 * op2; break;
                case '/': valStack[++valTop] = op1 / op2; break;
                case '^': valStack[++valTop] = pow(op1, op2); break;
            }
        }
        i++;
    }

    return valStack[valTop];
}

int main()
{
    char infix[MAX], postfix[MAX];
    int choice;

    printf("------ INFIX TO POSTFIX CONVERTER ------\n");
    printf("1. Convert Expression\n");
    printf("2. Convert and Evaluate (numbers only)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter Infix Expression (no spaces): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    if(choice == 2)
    {
        if(isdigit(postfix[0]))
        {
            int result = evaluatePostfix(postfix);
            printf("Evaluation Result: %d\n", result);
        }
        else
        {
            printf("Evaluation not possible (contains variables).\n");
        }
    }

    return 0;
}
