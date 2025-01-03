#include <stdio.h>
#include <time.h>

/*
 * Binary Search Algorithm for Character Array
 *
 * Time Complexity:
 * - Worst Case: O(log n)
 * - Average Case: O(log n)
 * - Best Case: O(1)
 *
 * Space Complexity: O(1)
 */

int binarySearchChar(char arr[], int size, char key)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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
    int result = binarySearchChar(arr, size, key);
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
