#include <stdio.h>
#include <time.h>

/*
 * Recursive Binary Search Algorithm for Character Array
 *
 * Time Complexity:
 * - Worst Case: O(log n)
 * - Average Case: O(log n)
 * - Best Case: O(1)
 *
 * Space Complexity: O(log n) due to recursive call stack
 */

int binarySearchCharRecursive(char arr[], int left, int right, char key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return binarySearchCharRecursive(arr, mid + 1, right, key);
        }
        else
        {
            return binarySearchCharRecursive(arr, left, mid - 1, key);
        }
    }
    return -1;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int size = sizeof(arr) / sizeof(arr[0]);
    char key;

    printf("\nEnter the character to search: ");
    scanf(" %c", &key);

    start = clock();
    int result = binarySearchCharRecursive(arr, 0, size - 1, key);
    end = clock();

    printf("%s", (result != -1) ? "\nCharacter found at index: " : "\nCharacter not found");
    if (result != -1)
    {
        printf("%d", result);
    }
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nBinary Search Time: %f seconds\n\n", cpu_time_used);

    return 0;
}
