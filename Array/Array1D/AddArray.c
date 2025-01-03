#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[])
{
    int k = 0;
    for (int i = 0; i < n1 - 1; i++)
    {
        result[k++] = arr1[i];
    }
    result[k++] = arr1[n1 - 1];
    result[k++] = arr2[0];
    for (int i = 1; i < n2; i++)
    {
        result[k++] = arr2[i];
    }
}

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[n1 + n2];
    mergeArrays(arr1, n1, arr2, n2, result);
    printf("\nThe Result Array:\n");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}
