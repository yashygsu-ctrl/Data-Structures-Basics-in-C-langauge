#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);
    // Studying the difference in initialization between mallaoc and calloc:
    int*arr1 = (int*)malloc(n*sizeof(int));
    for ( i = 0; i < n; i++)
    {
        printf("The default values allocated for %d elements is : %d\n",n, arr1[i]);
    }
    int*arr2 = (int*)calloc(n,sizeof(int));
    for ( i = 0; i < n; i++)
    {
        printf("The default values allocated for %d elements is : %d\n",n, arr2[i]);
    }
    // Displaying the input through user using calloc DMA :
    printf("Enter the %d elements :",n);
    if(arr2 == NULL){
        printf("Memory allocation failed using calloc.\n");
        free(arr2);
    }
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("The entered elements are:");
     for ( i = 0; i < n; i++)
    {
        printf("%d\n",arr2[i]);
    }
    return 0;
}