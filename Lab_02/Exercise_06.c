#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int n, choice, i, sum;
    for (;;)
    {
        printf("\n1.Create array");
        printf("\n2.Display array");
        printf("\n3.Find sum of elements");
        printf("\n4.Free memory");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // HERE , I have used if -else if in place of switch statement to create an infinite for loop with each continuous statement being executed without getting break unless asked .
        if (choice == 1)
        {
            printf("Enter number of elements:\n");
            scanf("%d", &n);
            arr = (int *)malloc(n * sizeof(int));
            printf("Enter the %d Elements as your choice:\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
        }
        else if (choice == 2)
        {
            printf("The entered elements are :\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\n", arr[i]);
            }
        }
        else if (choice == 3)
        {
            for (i = 0; i < n; i++)
            {
                sum = 0;
                sum = sum + arr[i];
            }
            printf("The sum of the elements is %d\n", sum);
        }
        else if (choice == 4)
        {
            free(arr);
            arr = NULL;
            printf("Memeory freed");
        }
        else if (choice == 5)
        {
            break;
        }
    }
    return 0;
}