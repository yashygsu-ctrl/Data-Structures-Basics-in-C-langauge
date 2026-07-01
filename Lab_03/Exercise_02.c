// Exercise 2
// Modify the given program to display the current size of the stack after each PUSH and POP operation.
#include<stdio.h>
# define MAX 7

int top=-1;
int stack[MAX];
void push(int item){
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    else{
        // printf("Enter the element to be pushed:\n");
        // scanf("%d",&item);
        top++;
        stack[top]=item;
        printf("Current size of the stack is %d\n",top+1);  
        // Size of the stack means how many element are their present in stack right now, not the empty space.
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow!");
    }
    else{
        // printf("Popped element is %d",stack[top]);
        top--;
        printf("Current size of the stack is :%d\n",top+1);
    }
}
int main(){
    push(20);
    push(10);
    push(30);
    pop();
    pop();
    return 0;
}