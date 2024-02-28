// Write a C program to swap two numbers. Use a function pointer to do this operation.
// Input:
// 84 25
// Output:
// 25 84
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    void (*swapFunction)(int *, int *);
    swapFunction = swap;
    (*swapFunction)(&a, &b);
    printf("After Swapping: %d %d", a, b);
    return 0;
}