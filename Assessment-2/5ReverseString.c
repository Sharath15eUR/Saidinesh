#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

void reverseString(char* inputString) {
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(inputString); i++) {
        push(&stack, inputString[i]);
    }

    int index = 0;
    while (!isEmpty(&stack)) {
        inputString[index++] = pop(&stack);
    }
}

int main() {
    char inputString[] = "LetsLearn";

    reverseString(inputString);

    printf("Reversed String: %s\n", inputString);

    return 0;
}
