#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = (int*) malloc(5 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }

    ptr[0] = 10;
    printf("%d", ptr[0]);

    free(ptr);

    return 0;
}
