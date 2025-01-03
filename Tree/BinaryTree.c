#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
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

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d --> ", root->data);
        inOrderTraversal(root->right);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 6);

    printf("\nInOrder Traversal Of The Binary Tree:\n");
    inOrderTraversal(root);
    printf("NULL\n\n");

    freeTree(root);

    return 0;
}
