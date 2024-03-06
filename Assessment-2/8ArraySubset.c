
#include <stdio.h>

int main() {

    int n1, n2;
    printf("Enter the size of the array1:");
    scanf("%d", &n1);
    int arr1[n1];
    printf("\nEnter the elements of array1:");
    for(int i=0;i<n1;i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the size of the array2:");
    scanf("%d", &n2);
    int arr2[n2];
    printf("\nEnter the elements of array2:");
    for(int i=0;i<n2;i++)
    {
        scanf("%d", &arr2[i]);
    }
    int count = 0;
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                count++;
            }
        }
    }
    if(count == n2)
    {
        printf("\narr2[] is a subset of arr1[]");
    }else{
        printf("\narr2[] is not a subset of arr1[]");
    }
    
    

    return 0;
}