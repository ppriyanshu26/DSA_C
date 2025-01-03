#include <stdio.h>
#include <time.h>

// Insertion Sort for Character Array
// Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
// Space Complexity: O(1)

void insertionSortChar(char arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printCharArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

void userDefinedCharArrayChar(char arr[], int n)
{
    printf("Enter %d characters:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
}

void predefinedCharArrayChar(char arr[], int *n)
{
    char temp[] = {'d', 'b', 'a', 'c', 'e'};
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
    printf("\n1) User-defined Char Array \n2) Pre-defined Char Array: \nChoose Array Type: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nEnter the number of characters: ");
        scanf("%d", &n);
        char arr[n];
        userDefinedCharArrayChar(arr, n);
        printf("\nOriginal array: \n");
        printCharArrayChar(arr, n);

        start = clock();
        insertionSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printCharArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nInsertion Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else if (choice == 2)
    {
        char arr[100];
        predefinedCharArrayChar(arr, &n);
        printf("\nOriginal array: \n");
        printCharArrayChar(arr, n);

        start = clock();
        insertionSortChar(arr, n);
        end = clock();

        printf("\nSorted array: \n");
        printCharArrayChar(arr, n);
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nInsertion Sort Time: %f seconds\n\n", cpu_time_used);
    }
    else
    {
        printf("\nInvalid Choice\n\n");
    }
    return 0;
}
