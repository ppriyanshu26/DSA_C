#include <stdio.h>
#include <time.h>

// Selection Sort for Character Array
// Time Complexity: Best: O(n^2), Average: O(n^2), Worst: O(n^2)
// Space Complexity: O(1)

void selectionSortChar(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        char temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);
        char arr[n];
        userDefinedArrayChar(arr, n);
        printf("\nOriginal array: \n");
        printArrayChar(arr, n);

        start = clock();
        selectionSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nSelection Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        char arr[100];
        predefinedArrayChar(arr, &n);
        printf("\nOriginal array: \n");
        printArrayChar(arr, n);

        start = clock();
        selectionSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nSelection Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
