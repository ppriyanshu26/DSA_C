#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int sum[ROWS][COLS];
    int diff[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nMatrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nSum of A and B:\n");
    printMatrix(sum);

    printf("\nDifference of A and B:\n");
    printMatrix(diff);

    return 0;
}
