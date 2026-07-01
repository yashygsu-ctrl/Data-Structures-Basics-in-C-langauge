#include <stdio.h>
#define MAX 5

struct Queue
{
    int q[MAX];
    int front;
    int rear;
};

void insert(struct Queue *cq, int value)
{
    if ((cq->front == cq->rear + 1) || (cq->front == 0 && cq->rear == MAX - 1))
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (cq->front == -1)
    {
        cq->front = cq->rear = 0;
    }
    else
    {
        cq->rear = (cq->rear + 1) % MAX;
    }
    cq->q[cq->rear] = value;
    printf("Inserted element is : %d\n", cq->q[cq->rear]);
    printf("Rear: %d\n", cq->rear);
}

void delete(struct Queue *cq)
{
    if (cq->front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Front: %d\n", cq->front);
    printf("Deleted Element is :%d\n", cq->q[cq->front]);

    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
    }
    else
    {
        cq->front = (cq->front + 1) % MAX;
    }
}

void display(struct Queue *cq)
{
    if (cq->front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    int i = cq->front;
    while (1)
    {
        printf("%d\n", cq->q[i]);
        if (i == cq->rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main()
{
    struct Queue cq;
    cq.front = -1;
    cq.rear = -1;

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
            insert(&cq, value);
            break;

        case 2:
            delete(&cq);
            break;

        case 3:
            display(&cq);
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