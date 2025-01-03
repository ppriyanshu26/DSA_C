#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", element);
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return -1;
    } else {
        struct Node* temp = top;
        int popped = temp->data;
        top = top->next;
        free(temp);
        return popped;
    }
}

int peek() {
    if (top == NULL) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return top->data;
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty\n");
    } else {
        struct Node* temp = top;
        printf("\nStack elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void empty() {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("\nAll elements deleted from the stack\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Empty Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("\nPopped element: %d\n", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("\nTop element: %d\n", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                empty();
                break;
            case 6:
                struct Node* temp;
                while (top != NULL) {
                    temp = top;
                    top = top->next;
                    free(temp);
                }
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
