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

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left); 
        printf("%d --> ", root->data);    
        inOrderTraversal(root->right); 
    }
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d --> ", root->data);    
        preOrderTraversal(root->left); 
        preOrderTraversal(root->right); 
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left); 
        postOrderTraversal(root->right); 
        printf("%d --> ", root->data);      
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
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->right = createNode(6);

    printf("\nInOrder Traversal:\n");
    inOrderTraversal(root);
    printf("NULL\n");

    printf("\nPreOrder Traversal:\n");
    preOrderTraversal(root);
    printf("NULL\n");

    printf("\nPostOrder Traversal:\n");
    postOrderTraversal(root);
    printf("NULL\n\n");

    freeTree(root);

    return 0;
}
