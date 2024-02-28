// Write a C program to determine the given number is odd or even using Bitwise operators

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    //using bitwise AND operator
    if(n & 1)
    {
        printf("Even Number");
    }else{
        printf("Odd Number");
    }

    return 0;
}