#include <stdio.h>
#include <time.h>

// Quick Sort for Character Array
// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n^2)
// Space Complexity: O(log n)

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int partition(char arr[], int low, int high)
{
    char pivot = arr[high];
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

void quickSortChar(char arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

void printArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

void userDefinedArrayChar(char arr[], int n)
{
    printf("Enter %d characters:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
}

void predefinedArrayChar(char arr[], int *n)
{
    char temp[] = {'d', 'a', 'c', 'b', 'e'};
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
        printf("\nEnter the number of characters: ");
        scanf("%d", &n);
        char arr[n];
        userDefinedArrayChar(arr, n);
        printf("\nOriginal array: \n");
        printArrayChar(arr, n);

        start = clock();
        quickSortChar(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nQuick Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        char arr[100];
        predefinedArrayChar(arr, &n);
        printf("\nOriginal array: \n");
        printArrayChar(arr, n);

        start = clock();
        quickSortChar(arr, 0, n - 1);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nQuick Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
