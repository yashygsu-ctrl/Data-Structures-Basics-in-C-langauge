#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1;
    int *ptr2;
    int elements;
    printf("Enter the number of elements whose dynamic memory is to be allocated: \n");
    scanf("%d", &elements);
    // USING malloc() -->
    // ptr = (data_type*) malloc(size_in_bytes);
    ptr1 = (int *)malloc(6);
    printf("Enter %d elements for malloc :\n", elements);
    if (ptr1 == NULL)
    {
        printf("Memory allocation failed using malloc.\n");
        free(ptr1);
        return 0;
    }
    for (int i = 0; i < elements; i++)
    {
        scanf("%d", &ptr1[i]);
    }
    for (int i = 0; i < elements; i++)
    {
        printf("The entered elements are using malloc : %d\n", ptr1[i]);
    }

    // USING calloc() -->
    // ptr = (data_type*) calloc(number_of_elements, size_of_each_element);

    ptr2 = (int *)calloc(5, 4);
    // printf("Enter %d elements for calloc (intiatialisation with zero) :\n", elements);
    if (ptr2 == NULL)
    {
        printf("Memory allocation failed using malloc.\n");
        free(ptr2);
        return 0;
    }
    // for (int i = 0; i < elements; i++)
    // {
    //     scanf("%d", &ptr2[i]);
    // }
    for (int i = 0; i < elements; i++)
    {
        printf("The entered elements using calloc are : %d\n", ptr2[i]);
    }
    return 0;
}