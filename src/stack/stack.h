typedef struct Stack {
    int *array;
    int size;
    int max_size;
} Stack;

Stack *makeStack();
Stack *stackResize(Stack *stack);
Stack *stackDownsize(Stack *stack);
int push(Stack *stack, int val);
int pop(Stack *stack);
void print(Stack *stack);
// void freeStack(Stack *stack);