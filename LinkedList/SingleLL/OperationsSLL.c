#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Value inserted\n");
}

void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Value inserted\n");
}

void insertAtIndex(struct Node** head, int data, int index) {
    if (index == 0) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Value inserted\n");
    }
}

void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("\nValue deleted\n");
}

void deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("\nValue deleted\n");
}

void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if (index == 0) {
        deleteAtFirst(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Index out of bounds\n");
    } else {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
        printf("Value deleted\n");
    }
}

void searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list\n", key);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("\nHEAD --> ");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("\nList Reversed\n");
}

void sortList(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct Node* i = *head;
    while (i != NULL) {
        struct Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("\nList sorted\n");
}

void emptyList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("\nList is now empty\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert at index\n");
        printf("4. Delete at first\n");
        printf("5. Delete at last\n");
        printf("6. Delete at index\n");
        printf("7. Search element\n");
        printf("8. Print the list\n");
        printf("9. Reverse the list\n");
        printf("10. Sort the list\n");
        printf("11. Empty the list\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to insert at first: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("\nEnter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 3:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                printf("\nEnter index: ");
                scanf("%d", &index);
                insertAtIndex(&head, data, index);
                break;
            case 4:
                deleteAtFirst(&head);
                break;
            case 5:
                deleteAtLast(&head);
                break;
            case 6:
                printf("\nEnter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                searchElement(head, data);
                break;
            case 8:
                printList(head);
                break;
            case 9:
                reverseList(&head);
                break;
            case 10:
                sortList(&head);
                break;
            case 11:
                emptyList(&head);
                break;
            case 12:
                if (head != NULL){
                    emptyList(&head);
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
