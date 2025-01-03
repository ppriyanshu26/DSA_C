#include <stdio.h>

#define ROWS_A 4
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 4

void printMatrix(int matrix[ROWS_A][COLS_B])
{
    for (int i = 0; i < ROWS_A; i++)
    {
        for (int j = 0; j < COLS_B; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[ROWS_A][COLS_A] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    int B[ROWS_B][COLS_B] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int result[ROWS_A][COLS_B] = {0};

    for (int i = 0; i < ROWS_A; i++)
    {
        for (int j = 0; j < COLS_B; j++)
        {
            for (int k = 0; k < COLS_A; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix A:\n");
    for (int i = 0; i < ROWS_A; i++)
    {
        for (int j = 0; j < COLS_A; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < ROWS_B; i++)
    {
        for (int j = 0; j < COLS_B; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nResult of A * B:\n");
    printMatrix(result);

    return 0;
}
