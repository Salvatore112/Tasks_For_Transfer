#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

bool isClosedBracket(Node **stack, char openBracket) {
    if (peek(*stack) == openBracket) {
        int errorCode = 0;
        pop(stack, &errorCode);
        return true;
    }
    return false;
}

// Function that checks if the bracket sequence is balanced, it treats an empty sequence is balanced.
bool isBalanced(char string[], int length) {
    Node* stack = NULL;
    for (int i = 0; i < length; i++) {
        switch (string[i]) {
            case '(':
            case '[':
            case '{':
                push(&stack, string[i]);
                break;
            case ')':
                if (!(isClosedBracket(&stack, '('))) {
                    return false;
                }
                break;
            case ']':
                if (!(isClosedBracket(&stack, '['))) {
                    return false;
                }
                break;
            case '}':
                if (!(isClosedBracket(&stack, '{'))) {
                    return false;
                }
                break;
        }
    }
    bool result = peek(stack) == '0';
    deleteStack(stack);
    return result;
}

bool tests() {
    char testString1[] = "([)]";
    if (isBalanced(testString1, 4)) {
        printf("Failed on the test \"([)]\"\n");
        return false;
    }

    char testString2[] = "[()]";
    if (!isBalanced(testString2, 4)) {
        printf("Failed on the test \"[()]\"\n");
        return false;
    }

    char testString3[] = "{{{{{{{}}}";
    if (isBalanced(testString3, 6)) {
        printf("Failed on the test \"{{{{{{{}}}\"\n");
        return false;
    }

    char testString4[] = "[[[[[[[]]";
    if (isBalanced(testString4, 6)) {
        printf("Failed on the test \"[[[[[[[]]\"\n");
        return false;
    }

    char testString5[] = "[({[{()]})]";
    if (isBalanced(testString5, 11)) {
        printf("Failed on the test \"[({[{()]})]\"\n");
        return false;
    }

    char testString6[] = "[({[()]})]";
    if (!isBalanced(testString6, 10)) {
        printf("Failed on the test \"[({[()]})]\"\n");
        return false;
    }
    return true;
}

int main(void) {
    if(!(tests() && stackTests())) {
        return 1;
    }

    return 0;
}