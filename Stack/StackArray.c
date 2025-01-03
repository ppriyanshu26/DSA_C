#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int element) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = element;
        printf("%d pushed to stack\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void empty() {
    top = -1;
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
                top = -1;
                printf("\nExiting\n\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
