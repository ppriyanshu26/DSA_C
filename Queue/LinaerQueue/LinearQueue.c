#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == SIZE - 1) {
        printf("\nERROR: Queue Is Full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d Enqueued\n", data);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nERROR: Queue Is Empty\n");
    } else {
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("\n%d Dequeued\n", data);
    }
}

void display() {
    if (front == -1) {
        printf("\nERROR: Queue Is Empty\n");
    } else {
        printf("\nQueue Elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void emptyQueue() {
    front = rear = -1;
    printf("\nQueue Emptied\n");
}

int main() {
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
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                emptyQueue();
                break;
            case 5:
                if (front != -1) {
                    emptyQueue();
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
