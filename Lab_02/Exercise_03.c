#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i;
    int sum=0;
    float avg;
    int* arr = (int*)malloc(n*sizeof(int));
    printf("How many numbers you want for memory allocation :\n");
    scanf("%d", &n);
    printf("Enter the %d elements:\n", n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Entered elements are :\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    for ( i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    avg = sum /n;
    printf("The sum of the entered elements is %d \n", sum );
    printf("The average of the entered elements is %f \n", avg );
   
    
    return 0;
}