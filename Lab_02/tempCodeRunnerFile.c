#include <stdio.h>
#include <stdlib.h>

// The output depends on whether the system has enough free heap memory at runtime.
int main()
{
    int *ptr = NULL;
    int n;
    // printf("Enter the number of elements whose DMA you need to see :\n");
    // scanf("%d",&n);/

    ptr = (int*)malloc(n*sizeof(int));
    if(ptr == NULL){
        printf("MEmeory allocation failed!\n");
    }
    else{
        printf("Memory allocation Success!");
        free(ptr);
    }
    // printf("Enter the elements:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&ptr[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n",ptr[i]);
    // }
    // printf("Since we can see the elements being stored in ptr using DMA so,DMA is succesfull!");
    // free(ptr);
    
    
    return 0;
}