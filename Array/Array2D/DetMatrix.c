#include <stdio.h>

int main()
{
    int a[3][3] = {
        {5, -4, 0},
        {-3, 5, 0},
        {5, 4, 2}
    };
    int determinant;

    determinant = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
                  a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
                  a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    printf("\nEntered matrix: \n");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d  ", a[i][j]);
            if (j == 2)
                printf("\n");
        }
    }

    printf("\nDeterminant of the matrix is: %d\n", determinant);

    return 0;
}
