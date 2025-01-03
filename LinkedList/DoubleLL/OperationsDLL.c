#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int isEmpty(struct Node* head) {
    return head == NULL;
}

void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Value inserted\n");
}

void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Value inserted\n");
}

void insertAtIndex(struct Node** head, int data, int index) {
    if (index == 0) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Value inserted\n");
}

void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("\nValue deleted\n");
}

void deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
    printf("\nValue deleted\n");
}

void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Value deleted\n");
}

void searchElement(struct Node* head, int data) {
    struct Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at index %d.\n", data, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element %d not found.\n", data);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nList: \nHEAD --> ");
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%d --> NULL\n", temp->data);
        } else {
            printf("%d <--> ", temp->data);
        }
        temp = temp->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("\nList reversed\n");
}

void sortList(struct Node** head) {
    if (*head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* i, *j;
    int temp;
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
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
    printf("\nThe list has been emptied.\n");
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
                printf("\nEnter data to insert at index: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                insertAtIndex(&head, data, index);
                break;
            case 4:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    deleteAtFirst(&head);
                }
                break;
            case 5:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    deleteAtLast(&head);
                }
                break;
            case 6:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    printf("\nEnter index to delete: ");
                    scanf("%d", &index);
                    deleteAtIndex(&head, index);
                }
                break;
            case 7:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    printf("\nEnter data to search: ");
                    scanf("%d", &data);
                    searchElement(head, data);
                }
                break;
            case 8:
                printList(head);
                break;
            case 9:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    reverseList(&head);
                }
                break;
            case 10:
                if (isEmpty(head)) {
                    printf("\nThe list is empty.\n");
                } else {
                    sortList(&head);
                }
                break;
            case 11:
                emptyList(&head);
                break;
            case 12:
                if (!isEmpty(head)){
                    emptyList(&head);
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
