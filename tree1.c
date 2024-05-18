#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a few nodes
    TreeNode* node1 = createNode(10);
    TreeNode* node2 = createNode(20);
    TreeNode* node3 = createNode(30);

    // Manually connect nodes to form a simple tree
    node1->left = node2;
    node1->right = node3;

    // Print the data to verify node creation
    printf("Root node data: %d\n", node1->data);
    printf("Left child data: %d\n", node2->data);
    printf("Right child data: %d\n", node3->data);

    // Free the allocated memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
