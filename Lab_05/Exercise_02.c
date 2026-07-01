#include<stdio.h>
# define MAX 5
int q[MAX];
int front=-1,rear=-1;
int value,count=0,i;
void insert(){
    if(rear==MAX-1){
        printf("Queue Overflow!");
    }
    else{
        if(front==-1){
            front=0;
        }
        printf("Enter the element to be inserted:\n");
        scanf("%d",&value);
        rear++;
        q[rear]=value;
        count++;
        
    }
}
void delete(){
    if(front==-1 || front>rear){
        printf("Queue Underflow!");
    }
    else{
        printf("The element deleted is :%d\n",q[front]);
        count--;
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
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
            case 3:printf("The number of elements present in the queue currently are : %d\n",count); break;
            case 4:printf("Exiting the program!\n"); break;
            default:printf("Invalid Choice!\n");
        }
    } while (choice!=4); 
    
}