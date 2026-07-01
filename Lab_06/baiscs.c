#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
void insert(int value)
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    {
        printf("Queue Overflow!\n");
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    q[rear] = value;
    printf("Inserted element is : %d\n", q[rear]);
}
void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
    }
    printf("Deleted Element is :%d\n", q[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", q[i]);
    }
}
int main()
{
    int choice, value;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}