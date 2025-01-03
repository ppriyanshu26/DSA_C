#include <stdio.h>
#include <time.h>

// Quick Sort
// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n^2)
// Space Complexity: O(log n)

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int temp[] = {10, 7, 8, 9, 1, 5};
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
        quickSort(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nQuick Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        int arr[100];
        predefinedArray(arr, &n);
        printf("\nOriginal array: \n");
        printArray(arr, n);

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nQuick Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
