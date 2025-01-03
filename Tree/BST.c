#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d --> ", root->data);
        inOrderTraversal(root->right);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);

    printf("\nInOrder Traversal:\n");
    inOrderTraversal(root);
    printf("NULL\n");

    int key1 = 5;
    struct Node* result1 = search(root, key1);
    if (result1) {
        printf("\n%d found in the Binary Search Tree\n", key1);
    } else {
        printf("\n%d not found in the Binary Search Tree\n", key1);
    }

    int key2 = 7;
    struct Node* result2 = search(root, key2);
    if (result2) {
        printf("\n%d found in the Binary Search Tree\n", key2);
    } else {
        printf("\n%d not found in the Binary Search Tree\n\n", key2);
    }

    freeTree(root);

    return 0;
}
