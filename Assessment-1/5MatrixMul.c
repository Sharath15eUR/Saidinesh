
// Write a C program to Multiply two matrix (n*n) using pointers.
// Input: 				Output:
// Size of Row: 3 			Product:
// Size of Column: 3 			48 39 30
// Matrix 1: 				102 84 66
// 2 3 4 				129 111 93
// 5 6 7
// 8 9 1
// Matrix 2:
// 9 8 7
// 6 5 4
// 3 2 1

#include <stdio.h>

void matrixInput(int *mat, int ROW, int COL);
void matrixPrint(int *mat, int ROW, int COL);
void matrixMultiply(int *mat1, int *mat2, int *res, int ROW, int COL);

int main()
{
    int ROW, COL;
    printf("Enter the size of row and column:");
    scanf("%d %d", &ROW, &COL);
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];
    printf("\nEnter elements in first matrix of size %dx%d:", ROW, COL);
    matrixInput(&mat1[0][0], ROW, COL);
    printf("\nEnter elements in second matrix of size %dx%d:", ROW, COL);
    matrixInput(&mat2[0][0], ROW, COL);
    matrixMultiply(&mat1[0][0], &mat2[0][0], &product[0][0], ROW, COL);
    printf("Product of both matrices is : \n");
    matrixPrint(&product[0][0], ROW, COL);
    return 0;
}
void matrixInput(int *mat, int ROW, int COL)
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", (mat + row * COL + col));
        }
    }
}
void matrixPrint(int *mat, int ROW, int COL)
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%d ", *(mat + row * COL + col));
        }
        printf("\n");
    }
}
void matrixMultiply(int *mat1, int *mat2, int *res, int ROW, int COL)
{
    int row, col, i;
    int sum;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;
            for (i = 0; i < COL; i++)
            {
                sum += (*(mat1 + row * COL + i)) * (*(mat2 + i * COL + col));
            }
            *(res + row * COL + col) = sum;
        }
    }
}
