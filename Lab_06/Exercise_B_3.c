#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *q;
    int front;
    int rear;
    int size;
};

void insert(struct Queue *cq, int value)
{
    if ((cq->front == (cq->rear + 1) % cq->size))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (cq->front == -1)
    {
        cq->front = cq->rear = 0;
    }
    else
    {
        cq->rear = (cq->rear + 1) % cq->size;
    }

    cq->q[cq->rear] = value;
    printf("Inserted element: %d\n", value);
}

void delete(struct Queue *cq)
{
    if (cq->front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", cq->q[cq->front]);

    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
    }
    else
    {
        cq->front = (cq->front + 1) % cq->size;
    }
}

void display(struct Queue *cq)
{
    if (cq->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = cq->front;

    while (1)
    {
        printf("%d ", cq->q[i]);

        if (i == cq->rear)
            break;

        i = (i + 1) % cq->size;
    }

    printf("\n");
}

int main()
{
    struct Queue cq;
    int choice, value;

    printf("Enter size of queue: ");
    scanf("%d", &cq.size);

    cq.q = (int *)malloc(cq.size * sizeof(int));

    cq.front = -1;
    cq.rear = -1;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
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
            printf("Exiting\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    free(cq.q);

    return 0;
}