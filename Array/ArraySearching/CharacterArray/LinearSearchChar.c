#include <stdio.h>
#include <time.h>

/*
 * Linear Search Algorithm for Character Array
 *
 * Time Complexity:
 * - Worst Case: O(n)
 * - Average Case: O(n)
 * - Best Case: O(1)
 *
 * Space Complexity: O(1)
 */

int linearSearchChar(char arr[], int size, char key)
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

    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int size = sizeof(arr) / sizeof(arr[0]);
    char key;

    printf("\nEnter the character to search: ");
    scanf(" %c", &key);

    start = clock();
    int result = linearSearchChar(arr, size, key);
    end = clock();

    printf("%s", (result != -1) ? "\nCharacter found at index: " : "\nCharacter not found");
    if (result != -1)
    {
        printf("%d", result);
    }
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nLinear Search Time: %f seconds\n\n", cpu_time_used);

    return 0;
}
