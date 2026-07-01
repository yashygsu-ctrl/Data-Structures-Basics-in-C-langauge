#include <stdio.h>
void modify();
void modify(int a, int b)
{
    a += 100;
    b += 200;
}
void modify1();

void modify1(int *a, int *b)
{
    *a += 100;
    *b += 200;
}

void main()
{
    int a, b;
    printf("Enter the value of a :\n");
    scanf("%d", &a);
    printf("Enter the value of b :\n");
    scanf("%d", &b);
    modify(a, b);
    printf("The values of a and b after caliing it through value in modify function are %d and %d \n", a, b);
    modify1(&a, &b);
    printf("The values of a and b after caliing it through reference in modify function are %d and %d \n", a, b);
}