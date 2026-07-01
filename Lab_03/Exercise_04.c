// Exercise 4
// Write a program to check whether a stack is empty or full at any given time.
#include<stdio.h>
# define MAX 5

    int stack[MAX],top;
    int is_Empty(){
        return top==-1;
    }
    int is_Full(){
        return top==MAX-1;
    }
    int main(){
        if(is_Empty){
            printf("Stack is empty\n");
        }
        top=MAX-1;
        if (is_Full)
        {
            printf("Stack is full\n");
        }
        return 0;

    }


