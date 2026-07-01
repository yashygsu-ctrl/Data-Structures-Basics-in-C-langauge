#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *top = NULL;
void push(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = top;
    top = newNode;
    printf("Element inserted successfully\n");
}
void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Deleted element: %d\n", top->info);
    top = top->link;
    free(temp);
}
void display()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is: %d\n", top->info);
    }
}

int count()
{
    int c = 0;
    struct node *temp = top;

    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }

    printf("Total element in stack: %d", c);
}

int main()
{
    int choice, value;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. peek\n5. count element\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            count();
            break;
        case 6:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}