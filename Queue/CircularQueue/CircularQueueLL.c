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

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->rear->next = queue->front;
    printf("%d Enqueued\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nERROR: Queue Is Empty\n");
        return -1;
    }
    int data;
    if (queue->front == queue->rear) {
        data = queue->front->data;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        struct Node* temp = queue->front;
        data = temp->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }
    return data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nERROR: Queue Is Empty\n");
        return;
    }
    struct Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

void emptyQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    printf("\nQueue has been emptied.\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Empty Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("\n%d dequeued\n", data);
                }
                break;
            case 3:
                printf("\nQueue Elements:\n");
                display(queue);
                break;
            case 4:
                emptyQueue(queue);
                break;
            case 5:
                if (!isEmpty(queue)) {
                    emptyQueue(queue);
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
