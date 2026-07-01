#include <stdio.h>
#define MAX 5
int front = -1, rear = -1;
int queue[MAX];
int value;

void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("ENter element to insert:\n");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }
}
void delete()
{
    if ((front == -1) || (front > rear))
    {
        printf("Queue underflow!");
    }
    else
    {
        printf("Element deleted is %d\n", queue[front]);
        front++;
    }
}
void display(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
    }
    else{
         printf("Elements in queue are:");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
    printf("\n");
}
int main(){
    int choice;
      do { 
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: insert(); break; 
            case 2: delete(); break; 
            case 3: display(); break; 
            case 4: printf("Exiting program\n"); break; 
            default: printf("Invalid choice\n"); 
        } 
    } while (choice != 4); 
    return 0;
}