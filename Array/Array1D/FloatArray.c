#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("\nEnter %d float numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    printf("\nArray Elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
