#include <stdio.h>
#define MAX 5
int q[MAX];
int front = -1, rear = -1;
int value, i;

int isDuplicate(int value)
{
    if (front == -1)
    {
        return 0;
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            if (q[i] == value)
            {
                return 1;
            }
            // This means if something is found to be duplicate then it will return something instead of 0 , here it is 1 i.e. the loop gets ended and we can then print value is duplicate ( understand return 0 means loop continues or code continues but not after "return")
        }
        return 0;
    }
}
void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter the element to be inserted:\n");
        scanf("%d", &value);
        if (isDuplicate(value))
        {
            printf("Duplicate Element Found!\n");
        }
        else
        {
            printf("Element inserted succesfully!\n");
            rear++;
            q[rear] = value;
        }
    }
}
void delete(){
    if(front==-1){
        printf("Queue is Underflow\n");
    }
    else{
        printf("Deleted element is:%d\n",q[front]);
        if(front==rear){
            front = rear=-1;
        }
        else{
            front++;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty!\n");
    }
    else{
        printf("Elements in the queue are:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",q[i]);
        }
    }
}
int main(){
    int choice;
    do
    {
        printf("1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf("Choose any of the operations from the above given:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert(); break;
            case 2:delete(); break;
            case 3:display(); break;
            case 4:printf("Exiting the program!\n"); break;
            default:printf("Invalid Choice!\n");
        }
    } while (choice!=4); 
    
}