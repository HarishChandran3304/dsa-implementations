// Linked List Implementation and Basic Operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int val;
    struct node* next;
};

void printList(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert(struct node** head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

bool search(struct node* head, int val) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->val == val) return true;
        ptr = ptr->next;
    }
    return false;
}

void delete(struct node** head, int val) {
    if (*head == NULL) {
        printf("Value not found\n");
        return;
    }
    else if ((*head)->val == val) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    else {
        struct node* prev = *head;
        struct node* curr = (*head)->next;
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
                free(curr);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        printf("Value not found\n");
    }
}

int main() {
    struct node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    printList(head);
    printf("%d\n", search(head, 2));
    delete(&head, 2);
    printList(head);
    printf("%d\n", search(head, 2));
    return 0;
}