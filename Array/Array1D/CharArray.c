#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of characters: ");
    scanf("%d", &n);

    char arr[n + 1]; 
    printf("\nEnter %d characters:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
    arr[n] = '\0'; 

    printf("\nArray Elements:\n%s\n", arr);

    return 0;
}
