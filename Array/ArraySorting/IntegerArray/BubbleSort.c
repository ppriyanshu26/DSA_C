#include <stdio.h>
#include <time.h>

// Bubble Sort
// Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
// Space Complexity: O(1)

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int temp[] = {64, 34, 25, 12, 22, 11, 90};
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
        bubbleSort(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nBubble Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        int arr[100];
        predefinedArray(arr, &n);
        printf("\nOriginal array: \n");
        printArray(arr, n);

        start = clock();
        bubbleSort(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArray(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nBubble Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
