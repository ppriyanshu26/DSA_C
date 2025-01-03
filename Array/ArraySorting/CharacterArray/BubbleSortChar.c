#include <stdio.h>
#include <time.h>

// Bubble Sort for Character Array
// Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
// Space Complexity: O(1)

void bubbleSortChar(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    char temp[] = {'d', 'a', 'c', 'b', 'e', 'f'};
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
        bubbleSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nBubble Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        char arr[100];
        predefinedArrayChar(arr, &n);
        printf("\nOriginal array: \n");
        printArrayChar(arr, n);

        start = clock();
        bubbleSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nBubble Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
