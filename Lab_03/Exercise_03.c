// Exercise 3
// Write a program to reverse a given list of numbers using stack implemented with array.
#include<stdio.h>

int main(){
    int item,top,stack[7];
    if(top==6){
        printf("Stack Overflow!");
    }
    
    else{
        printf("Enter 7 elements:\n");
        for(top=0;top<7;top++){
            scanf("%d",&stack[top]);
        }
    }
    printf("Given list of 7 numbers in reverse order is :-\n");
    for(top=6;top>=0;top--){
        printf("%d,",stack[top]);
    }
    return 0;
}