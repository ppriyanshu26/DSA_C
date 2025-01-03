#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertAtFirst(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
    }
    printf("Value inserted\n");
}

void insertAtLast(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    printf("Value inserted\n");
}

void insertAtIndex(int data, int index) {
    if (last == NULL || index == 0) {
        insertAtFirst(data);
        return;
    }
    struct Node* temp = last->next;
    int count = 0;
    while (temp != last && count < index - 1) {
        temp = temp->next;
        count++;
    }
    if (count != index - 1) {
        printf("Index out of bounds\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) {
        last = newNode;
    }
    printf("Value inserted\n");
}

void deleteAtFirst() {
    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
    printf("\nValue deleted\n");
}

void deleteAtLast() {
    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
    printf("\nValue deleted\n");
}

void deleteAtIndex(int index) {
    if (last == NULL || index == 0) {
        deleteAtFirst();
        return;
    }
    struct Node* temp = last->next;
    int count = 0;
    while (temp->next != last && count < index - 1) {
        temp = temp->next;
        count++;
    }
    if (count != index - 1 || temp->next == last->next) {
        printf("Index out of bounds\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == last) {
        last = temp;
    }
    free(delNode);
    printf("Value deleted\n");
}

int searchElement(int data) {
    if (last == NULL) {
        printf("\nList is empty\n");
        return 0;
    }
    struct Node* temp = last->next;
    do {
        if (temp->data == data) return 1;
        temp = temp->next;
    } while (temp != last->next);
    return 0;
}

void printList() {
    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* temp = last->next;
    printf("HEAD --> ");
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("HEAD\n");
}

void reverseList() {
    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node *prev = last, *curr = last->next, *next;
    struct Node *first = curr; 
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != last);
    last->next = prev;
    last = first; 
    printf("\nList reversed\n");
}

void sortList() {
    if (last == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* temp1 = last->next;
    do {
        struct Node* temp2 = temp1->next;
        while (temp2 != last->next) {
            if (temp1->data > temp2->data) {
                int t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    } while (temp1 != last->next);
    printf("\nList sorted\n");
}

void emptyList() {
    while (last != NULL) {
        deleteAtFirst();
    }
    printf("\nList emptied\n");
}

int main() {
    int choice, data, index;
    while (1) {
        printf("\nMenu:\n1. Insert at first\n2. Insert at last\n3. Insert at index\n4. Delete at first\n5. Delete at last\n6. Delete at index\n7. Search element\n8. Print the list\n9. Reverse the list\n10. Sort the list\n11. Empty the list\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtFirst(data);
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                insertAtIndex(data, index);
                break;
            case 4:
                deleteAtFirst();
                break;
            case 5:
                deleteAtLast();
                break;
            case 6:
                printf("\nEnter index: ");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;
            case 7:
                printf("\nEnter data: ");
                scanf("%d", &data);
                if (searchElement(data)) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                printList();
                break;
            case 9:
                reverseList();
                break;
            case 10:
                sortList();
                break;
            case 11:
                emptyList();
                break;
            case 12:
                if (last != NULL){
                    emptyList();
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
