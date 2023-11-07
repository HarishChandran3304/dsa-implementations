// Binary Search Tree Implementations and Basic Operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
    int val;
    struct node* left;
    struct node* right;
};


void inorderTraversal(struct node* root) {
    // Empty tree case
    if (root == NULL) {
        return;
    }

    // Recursive inorder traversal (Left-Root-Right)
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}


void insert(struct node** root, int val) {
    // Create new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    // Empty tree case
    if (*root == NULL) {
        *root = newNode;
    }

    else {
        // Two pointers for search
        struct node* prev = NULL;
        struct node* curr = *root;

        // Iterative search
        while (curr != NULL) {
            prev = curr;
            curr = (val < curr->val) ? curr->left : curr->right;
        }

        // Insert
        if (val < prev->val) prev->left = newNode;
        else prev->right = newNode;
    }
}


bool search(struct node* root, int val) {
    // Pointer for traversal
    struct node* ptr = root;

    // Iterative search
    while (ptr != NULL) {
        if (ptr->val == val) return true; // Element found
        ptr = (val < ptr->val) ? ptr->left : ptr->right;
    }

    // Element not found case
    return false;
}


void delete(struct node** root, int val) {
    // Empty tree case
    if (*root == NULL) {
        printf("Value not found\n");
        return;
    }

    // Two pointers for search
    struct node* prev = NULL;
    struct node* curr = *root;

    // Iterative search
    while (curr != NULL && curr->val != val) {
        prev = curr;
        curr = (val < curr->val) ? curr->left : curr->right;
    }

    // Element not found case
    if (curr == NULL) {
        printf("Value not found\n");
        return;
    }
    
    // One child case (left child)
    // Also includes leaf node case
    else if (curr->left == NULL) {
        if (prev == NULL) *root = curr->right; // Root node case
        else if (curr == prev->left) prev->left = curr->right; // Left child case
        else prev->right = curr->right; // Right child case
        free(curr); // Free memory of current node
    }

    // One child case (right child)
    else if (curr->right == NULL) {
        if (prev == NULL) *root = curr->left; // Root node case
        else if (curr == prev->left) prev->left = curr->left; // Left child case
        else prev->right = curr->left; // Right child case
        free(curr); // Free memory of current node
    }

    // Two Children Case
    else {
        // Two pointers for inorder successor search
        struct node *successorParent = curr;
        struct node *successor = curr->right;

        // Iterative search
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace value of current node with successor value
        curr->val = successor->val;

        // Delete successor node
        if (successor == successorParent->left) successorParent->left = successor->right; // Successor is left child
        else successorParent->right = successor->right; // Successor is right child

        // Free memory of successor node
        free(successor);
    }
}
    

int main() {
    struct node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    inorderTraversal(root);
    printf("\n");
    
    printf("%d\n", search(root, 80));

    delete(&root, 80);
    printf("%d\n", search(root, 80));
    inorderTraversal(root);
    printf("\n");

    return 0;
}