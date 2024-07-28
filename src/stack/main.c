#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv) {

    Stack *stack = makeStack();
    for (int i = 1; i <= 10; i++) {
        push(stack, i);
    }
    print(stack);
    printf("The size of the stack is: %d, while the max size: %d\n", stack->size, stack->max_size);
    push(stack, 11);
    push(stack, 12);
    printf("The size of the stack is: %d, while the max size: %d\n", stack->size, stack->max_size);
    printf("The value of the popped node is: %d\n", pop(stack));
    printf("The value of the popped node is: %d\n", pop(stack));
    printf("The size of the stack is: %d, while the max size: %d\n", stack->size, stack->max_size);

    return EXIT_SUCCESS;
}