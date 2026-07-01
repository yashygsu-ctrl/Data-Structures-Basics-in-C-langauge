#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at end */
void insertEnd(int value)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

/* Insert before position */
void insertBeforePos(int value, int pos)
{
    struct node *newNode, *temp;
    int i;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (pos == 1)
    {
        printf("Use insert at beginning\n");
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete first node */
void deleteFirst()
{
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }

    free(temp);
}

/* Delete after position */
void deleteAfterPos(int pos)
{
    struct node *temp, *del;
    int i;

    temp = head;

    for (i = 1; i < pos; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;

    free(del);
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* Exercise Question 1 implemented: Insert node at beginning */
void insertBegin(int value)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

/* Exercise Question 2 implemented: Search element and display position */
void search(int key)
{
    struct node *temp;
    int pos = 1, found = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        printf("Element not found\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertBegin(5);
    display();

    insertBeforePos(15, 3);
    display();

    deleteFirst();
    display();

    deleteAfterPos(2);
    display();

    search(20);

    return 0;
}