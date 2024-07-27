#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *makeStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->array = (int *) malloc(sizeof(int) * 10);
    stack->size = 0;
    stack->max_size = 10;
    return stack;
}

Stack *stackResize(Stack *stack) {
    stack->array = (int *) realloc(stack, sizeof(int) * stack->max_size * 2);
    stack->max_size *= 2;
    return stack;
}

Stack *stackDownsize(Stack *stack) {
    stack->array = (int *) realloc(stack, sizeof(int) * (stack->max_size / 2));
    stack->max_size /= 2;
    return stack;
}

int push(Stack *stack, int val) {
    if (stack->size + 1 > stack->max_size) {
        stack = stackResize(stack);
    }
    stack->array[stack->size] = val;
    stack->size++;
    return 1;
}

int pop(Stack *stack) {
    if (stack->size - 1 == stack->max_size / 2) {
        stack = stackDownsize(stack);
    }
    int retval = stack->array[stack->size];
    stack->size--;
    return retval;
}

void print(Stack *stack) {
    printf("[ ");
    for (int i = 0; i < stack->size; i++) {
        i + 1 == stack->size ? printf("%d ]\n", stack->array[i]) : printf("%d, ", stack->array[i]);
    }
    return;
}

// void freeStack(Stack *stack);