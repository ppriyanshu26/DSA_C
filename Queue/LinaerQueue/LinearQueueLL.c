#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nERROR: Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d Enqueued\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("\nERROR: Queue Is Empty\n");
        return -1;
    }
    int item = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("\nElement Dequeued\n");
    return item;
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("\nERROR: Queue Is Empty\n");
        return;
    }
    struct Node* current = q->front;
    printf("\nQueue:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void emptyQueue(struct Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    printf("\nQueue Emptied\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Empty Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                emptyQueue(&queue);
                break;
            case 5:
                if (!isEmpty(&queue)) {
                    emptyQueue(&queue);
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
