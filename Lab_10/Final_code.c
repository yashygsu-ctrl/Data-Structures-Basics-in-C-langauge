
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertFront(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteLast()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteBeforePos(int pos)
{
    struct node *temp = head;
    int i;

    for(i=1; i<pos; i++)
        temp = temp->next;

    if(temp->prev == NULL || temp->prev->prev == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }

    struct node *del = temp->prev;
    del->prev->next = temp;
    temp->prev = del->prev;

    free(del);
}

/* Exercise Question 1 implemented: Insert a node after a specified position */
void insertAfterPos(int data, int pos)
{
    struct node *temp = head;
    int i;

    for(i=1; i<pos; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Position not found\n");
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void display()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Exercise Question 2 implemented: Display doubly linked list in reverse order */
void displayReverse()
{
    struct node *temp = head;

    if(temp == NULL)
        return;

    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    insertFront(10);
    insertFront(20);
    insertEnd(30);
    insertEnd(40);

    display();

    deleteLast();
    display();

    deleteBeforePos(3);
    display();

    insertAfterPos(25, 2);
    display();

    displayReverse();

    return 0;
}

