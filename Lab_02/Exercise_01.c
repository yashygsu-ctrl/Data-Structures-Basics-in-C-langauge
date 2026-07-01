#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i;
    printf("Enter the number of elements whose dynamic memory is to be allocated: \n");
    scanf("%d", &n);
    int*ptr;
    ptr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements for malloc :\n", n);
    if(ptr  == NULL){
        printf("Memory allocation failed using malloc.\n");
        free(ptr);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The entered elements are using malloc : %d\n",ptr[i]);
    }
    
    return 0;
}