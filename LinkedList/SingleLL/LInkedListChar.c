#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("HEAD --> ");
    while (temp != NULL) {
        printf("%c --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int n;
    char data;

    printf("\nEnter the number of elements to be inserted: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &data);  // Note the space before %c to consume any leftover newline character
        insertAtEnd(&head, data);
    }

    printf("\nThe linked list is:\n");
    printList(head);

    deleteList(&head);

    return 0;
}
