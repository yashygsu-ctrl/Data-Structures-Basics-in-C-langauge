/* 🔹 2. Insertion in Array
👉 Concept:

To insert an element:

Choose position

Shift elements to right

Insert value

👉 In array, insertion needs shifting.

👉 Code: */
#include <stdio.h>
int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int pos = 2, i;
    int n = 5;
    int value = 100;
    for (i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}