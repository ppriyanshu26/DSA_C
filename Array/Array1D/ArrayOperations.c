#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;

void insertAtFirst(int element)
{
    if (size >= MAX)
    {
        printf("\nArray is full\n");
        return;
    }
    for (int i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
    printf("Element Inserted\n");
}

void insertAtLast(int element)
{
    if (size >= MAX)
    {
        printf("\nArray is full\n");
        return;
    }
    arr[size++] = element;
    printf("Element Inserted\n");
}

void insertAtIndex(int index, int element)
{
    if (size >= MAX)
    {
        printf("\nArray is full\n");
        return;
    }
    if (index < 0 || index > size)
    {
        printf("Invalid index\n");
        return;
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
    printf("Element Inserted\n");
}

void deleteAtFirst()
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("\nElement Deleted\n");
}

void deleteAtLast()
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    size--;
    printf("\nElement Deleted\n");
}

void deleteAtIndex(int index)
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    if (index < 0 || index >= size)
    {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("\nElement Deleted\n");
}

void printArray()
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    printf("\nThe Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchElement(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("\nElement found at index %d\n", i);
            return;
        }
    }
    printf("\nElement not found\n");
}

void sortArray()
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nArray Sorted\n");
}

void reverseArray()
{
    if (size == 0)
    {
        printf("\nArray is empty\n");
        return;
    }
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("\nArray Reversed\n");
}

void emptyArray()
{
    size = 0;
    printf("\nDeleted all elements\n");
}

int main()
{
    int choice, element, index;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Element At First\n");
        printf("2. Insert Element At Last\n");
        printf("3. Insert Element At Index\n");
        printf("4. Delete Element At First\n");
        printf("5. Delete Element At Last\n");
        printf("6. Delete Element At Index\n");
        printf("7. Search Element\n");
        printf("8. Print Array\n");
        printf("9. Reverse Array\n");
        printf("10. Sort Array\n");
        printf("11. Empty Array\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert at first: ");
            scanf("%d", &element);
            insertAtFirst(element);
            break;
        case 2:
            printf("\nEnter element to insert at last: ");
            scanf("%d", &element);
            insertAtLast(element);
            break;
        case 3:
            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            printf("Enter index: ");
            scanf("%d", &index);
            insertAtIndex(index, element);
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            if (size == 0)
            {
                printf("\nArray is empty\n");
            }
            else
            {
                printf("\nEnter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(index);
            }
            break;
        case 7:
            if (size == 0)
            {
                printf("\nArray is empty\n");
            }
            else
            {
                printf("\nEnter element to search: ");
                scanf("%d", &element);
                searchElement(element);
            }
            break;
        case 8:
            printArray();
            break;
        case 9:
            reverseArray();
            break;
        case 10:
            sortArray();
            break;
        case 11:
            emptyArray();
            break;
        case 12:
            printf("\nExiting\n\n");
            exit(0);
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }

    return 0;
}
