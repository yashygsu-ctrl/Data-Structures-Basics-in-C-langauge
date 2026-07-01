// 🔹 1. Traversing an Array
// 👉 Concept:

// Accessing and printing each element of the array one by one.

// 👉 Code:
#include<stdio.h>
int main(){
    int arr[10]={10,20,30,40,50};
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
    
}