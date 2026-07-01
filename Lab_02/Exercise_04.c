#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    int max,min;
    int*arr = (int*)malloc(n*sizeof(n));
    printf("Enter the value of n:\n");
    scanf("%d", &n);

    printf("Enter %d numbers :", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The entered elements of the array are :\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    max = arr[0];
    for ( i = 1; i < n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("The largest element of the array is: %d\n", max);
    min = arr[0];
    for ( i = 1; i < n; i++)
    {
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("The smallest element of the array is: %d\n", min);
    
    
    return 0;
}