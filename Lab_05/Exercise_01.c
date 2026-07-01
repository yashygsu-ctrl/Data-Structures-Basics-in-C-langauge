#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
int value;
void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        // from this we are letting the insert opertation know that whether the stack is empty or not by giving the front counter variables's current stage to let it know whether the queue is empty or not
        if (front == -1)
        {
            front = 0;
            printf("Enter the element to be inserted:\n");
            scanf("%d", &value);
            rear++;
            q[rear] = value;
        }
    }
}
void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow:\n");
    }
    else
    {
        printf("Deleted element is %d\n:", q[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{   
    if(front==-1){
        printf("Queue Underflow\n");
    }
    else{
    printf("The elements in the queue are:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d,", q[i]);
    }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        printf("From the above operations ,choose any one:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting Program!");
            break;
        default:
            printf("Invalid Choice!");
        }
    } while (choice != 4);
}