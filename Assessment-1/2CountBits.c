//Write a C program to count the number of bits set in a number.
// Input:
// 144
// Output: 
// Count of Set bits: 2 


#include<stdio.h>

int main()
{
    int n, count=0;
    scanf("%d", &n);
    while(n > 0)
    {
        count += n & 1;
        n = n >> 1;
    }
    printf("Count of Set bits: %d", count);
    return 0;
}