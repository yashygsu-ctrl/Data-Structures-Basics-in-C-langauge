#include<stdio.h>
# define MAX 5
int q[MAX];
int front=-1,rear=-1;
int value,count=0,i;
void insert(){
    if(rear==MAX-1){
        printf("Queue Overflow!\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        printf("Enter the element to be inserted:\n");
        scanf("%d",&value);
        rear++;
        q[rear]=value;
        printf("Front: %d\n",front);
        printf("Rear: %d\n",rear);
        
    }
}
void delete(){
    if(front==-1 || front>rear){
        printf("Queue Underflow!");
    }
    else{
        printf("The element deleted is :%d\n",q[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
        printf("Front: %d\n",front);
        printf("Rear: %d\n",rear);
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
        printf("1.Insert\n 2.Delete\n 3.View Number of elements in the queue.\n 4.Exit\n");
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