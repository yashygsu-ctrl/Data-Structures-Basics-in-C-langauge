#include<stdio.h>
#define MAX 5
int queue[MAX];
int f=-1,r=-1;
int count=0;
int y;
void insert(){
    if(r==MAX-1){
        printf("Queue Overflow");
    }
    else{
        printf("Enter the element to be inserted:\n");
        scanf("%d",&y);
        queue[r]=y;
        y++;
        count++;
    }
}
void delete(){
    if(f==-1 ||f>r){
        printf("Queue Underflow");
    }
    else{
        printf("Element deleted is :%d\n",queue[f]);
        f++;
        count--;
    }
}
int main(){
    int choice;
    do { 
        printf("\n1. Insert\n2. Delete\n3. View number of elements\n4. Exiting Program\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: insert(); break; 
            case 2: delete(); break;  
            case 3: printf("the number of elements in the queue are:%d\n",count); break;
            case 4: printf("Exiting program\n"); break; 
            default: printf("Invalid choice\n"); 
        } 
    } while (choice != 4); 
    return 0;
}