#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

bool pushTests() {
    Node *testStack1 = NULL;

    push(&testStack1, 'a');
    char testElement1 = testStack1->element;
    if (testElement1 != 'a') {
        printf("Push Failed on adding the first element");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, 'a');
    push(&testStack2, 'b');
    push(&testStack2, 'c');
    char testElement2 = testStack2->element;
    if (testElement2 != 'c') {
        printf("Push Failed on adding element (not the first)");
        return false;
    }
    return true;
}

bool popTests() {
    Node *testStack1 = NULL;
    int errorCode1 = 0;
    pop(&testStack1, &errorCode1);
    if(errorCode1 != -1) {
        printf("Pop Failed when trying to pop an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    int errorCode2 = 0;
    push(&testStack2, 'a');
    if (pop(&testStack2, &errorCode2) != 'a') {
        printf("Pop Failed when trying to pop the first element");
        return false;
    }

    Node *testStack3 = NULL;
    int errorCode3 = 0;
    push(&testStack3, 'a');
    push(&testStack3, 'b');
    push(&testStack3, 'c');
    push(&testStack3, 'd');
    if(pop(&testStack3, &errorCode3) != 'd') {
        printf("Pop Failed when trying to pop some element");
        return false;
    }
    return true;
}

bool isEmptyTests() {
    Node *testStack1 = NULL;
    if (isEmpty(testStack1) == false) {
        printf("IsEmpty failed on an empty stack");
        return false;
    }
    Node *testStack2 = NULL;
    push(&testStack2, 'a');
    if (isEmpty(testStack2) != false) {
        printf("IsEmpty failed on not an empty stack");
        return false;
    }
    return true;
}

bool peekTests() {
    Node *testStack1 = NULL;
    if (peek(testStack1) != '0') {
        printf("peek failed on trying to peek an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, 'a');
    if (peek(testStack2) != 'a') {
        printf("peek failed on trying to peek a stack of one element");
        return false;
    }

    Node *testStack3 = NULL;
    push(&testStack3, 'a');
    push(&testStack3, 'b');
    push(&testStack3, 'c');
    if (peek(testStack3) != 'c') {
        printf("peek failed on trying to peek a stack of more than one element");
        return false;
    }
    return true;
}

bool clearTests() {
    Node *testStack1 = NULL;
    clear(&testStack1);
    if (peek(testStack1) != '0') {
        printf("Clear failed on an empty stack");
        return false;
    }

    Node *testStack2 = NULL;
    push(&testStack2, 'a');
    push(&testStack2, 'b');
    push(&testStack2, 'c');
    clear(&testStack2);
    if (peek(testStack2) != '0') {
        printf("Clear failed");
        return false;
    }
    return true;
}

bool stackTests() {
    return clearTests() && pushTests() && popTests() && isEmptyTests() && peekTests();
}