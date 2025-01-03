#include <stdio.h>
#include <time.h>

// Selection Sort
// Time Complexity: Best: O(n^2), Average: O(n^2), Worst: O(n^2)
// Space Complexity: O(1)

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
    int temp[] = {64, 25, 12, 22, 11};
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
        selectionSort(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nSelection Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        int arr[100];
        predefinedArray(arr, &n);
        printf("\nOriginal array: \n");
        printArray(arr, n);

        start = clock();
        selectionSort(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nSelection Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
