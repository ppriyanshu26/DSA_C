#include <stdio.h>
#include <time.h>

// Merge Sort
// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
// Space Complexity: O(n)

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void userDefinedArray(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void predefinedArray(int arr[], int *n)
{
    int temp[] = {12, 11, 13, 5, 6, 7};
    *n = sizeof(temp) / sizeof(temp[0]);
    for (int i = 0; i < *n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int choice, n;
    printf("\n1) User-defined Array \n2) Pre-defined Array: \nChoose Array Type: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);
        int arr[n];
        userDefinedArray(arr, n);
        printf("\nOriginal array: \n");
        printArray(arr, n);

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nMerge Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        int arr[100];
        predefinedArray(arr, &n);
        printf("\nOriginal array: \n");
        printArray(arr, n);

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nMerge Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
