#include <stdio.h>
#include <time.h>

/*
 * Linear Search Algorithm
 *
 * Time Complexity:
 * - Worst Case: O(n)
 * - Average Case: O(n)
 * - Best Case: O(1)
 *
 * Space Complexity: O(1)
 */

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
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
    int result = linearSearch(arr, size, key);
    end = clock();

    printf("%s", (result != -1) ? "\nElement found at index: " : "\nElement not found");
    if (result != -1)
    {
        printf("%d", result);
    }
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nLinear Search Time: %f seconds\n\n", cpu_time_used);

    return 0;
}
