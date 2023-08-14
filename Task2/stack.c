#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

char push(Node **head, char element) {
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Out of memory");
        return -1;
    }
    temp->element = element;
    temp->next = *head;
    *head = temp;
    return (*head)->element;
}

char pop(Node **head, int *errorCode) {
    if (*head == NULL) {
        *errorCode = -1;
        return 0;
    }
    *errorCode = 0;
    char value = (*head)->element;

    Node *temp;
    temp = (*head)->next;
    free(*head);
    (*head) = temp;
    return value;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

char peek(Node *head) {
    if (isEmpty(head)) {
        return '0';
    }
    return head->element;
}

void clear(Node **head) {
    while (!isEmpty(*head)) {
        int errorCode = 0;
        pop(head, &errorCode);
        if (errorCode < 0) {
            break;
        }
    }
}

void deleteStack(Node* head) {
    if (head == NULL) {
        return;
    }
    Node *current = head;
    Node *next = NULL;
    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(next);
}