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
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

void insert(struct node** root, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (*root == NULL) {
        *root = newNode;
    }
    else {
        struct node* prev = NULL;
        struct node* curr = *root;

        while (curr != NULL) {
            prev = curr;
            curr = (val < curr->val) ? curr->left : curr->right;
        }

        if (val < prev->val) prev->left = newNode;
        else prev->right = newNode;
    }
}

bool search(struct node* root, int val) {
    struct node* ptr = root;

    while (ptr != NULL) {
        if (ptr->val == val) return true;
        ptr = (val < ptr->val) ? ptr->left : ptr->right;
    }

    return false;
}

void delete(struct node** root, int val) {
    if (*root == NULL) {
        printf("Value not found\n");
        return;
    }

    struct node* prev = NULL;
    struct node* curr = *root;

    while (curr != NULL && curr->val != val) {
        prev = curr;
        curr = (val < curr->val) ? curr->left : curr->right;
    }

    if (curr == NULL) {
        printf("Value not found\n");
        return;
    }
    else if (curr->left == NULL) {
        if (prev == NULL) *root = curr->right;
        else if (curr == prev->left) prev->left = curr->right;
        else prev->right = curr->right;
    }
    else if (curr->right == NULL) {
        if (prev == NULL) *root = curr->left;
        else if (curr == prev->left) prev->left = curr->left;
        else prev->right = curr->left;
    }
    else {
        struct node *successorParent = curr;
        struct node *successor = curr->right;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        curr->val = successor->val;

        if (successor == successorParent->left) successorParent->left = successor->right;
        else successorParent->right = successor->right;

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
    
    printf("%d\n", search(root, 70));
    printf("%d\n", search(root, 75));

    delete(&root, 70);
    printf("%d\n", search(root, 70));
    inorderTraversal(root);
    printf("\n");

    return 0;
}