#include <stdio.h>
#include <time.h>

/*
 * Recursive Binary Search Algorithm
 *
 * Time Complexity:
 * - Worst Case: O(log n)
 * - Average Case: O(log n)
 * - Best Case: O(1)
 *
 * Space Complexity: O(log n) due to recursion stack
 */

int binarySearch(int arr[], int left, int right, int key)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] > key)
        {
            return binarySearch(arr, left, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    start = clock();
    int result = binarySearch(arr, 0, size - 1, key);
    end = clock();

    printf("%s", (result != -1) ? "\nElement found at index: " : "\nElement not found");
    if (result != -1)
    {
        printf("%d", result);
    }
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nBinary Search Time: %f seconds\n\n", cpu_time_used);

    return 0;
}
