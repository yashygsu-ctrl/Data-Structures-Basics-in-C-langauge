#include<stdio.h>
# define  MAX 5
int item;
int top=-1;
int stack[MAX];
int i;


void push(){
    if(top == MAX -1){
        printf("Stack Overflow");
    }
    else{
        printf("Enter the element to be pushed:\n");
        scanf("%d",&item);
        top++;
        stack[top] = item;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow!");
    }
    else{
        printf("Popped element is:%d\n",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Stack Underflow!");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("Entered elements are:%d,",stack[top]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
