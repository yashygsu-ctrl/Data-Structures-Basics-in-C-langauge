// Exercise 1
// Write a program to implement stack using array and perform PUSH and POP operations without using menu-driven approach.
#include<stdio.h>
# define MAX 5
int main(){
    int stack[MAX];
    int i,top=-1,item;
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    else{
        printf("Enter the element to be pushed:");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
    if(top==-1){
        printf("Stack Underflow!");
    }
    else{
        printf("Popped element is %d",stack[top]);
        top--;
    }
    return 0;
}