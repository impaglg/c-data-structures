#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinaryTree *makeBinaryTree() {
    BinaryTree *bintree = (BinaryTree *) malloc(sizeof(BinaryTree));
    bintree->root = NULL;
    bintree->size = 0;
    return bintree;
}

Node *makeNode(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int append(BinaryTree *bintree, Node *node) {
    if (empty(bintree)) {
        bintree->root = node;
        bintree->size++;
        return 1;
    }
    Node **current = &bintree->root;
    while (*current) {
        if (node->val == (*current)->val) {
            return -1;
        }
        if (node->val < (*current)->val) {
            current = &(*current)->left;
            continue;
        }
        if (node->val > (*current)->val) {
            current = &(*current)->right;
            continue;
        }
    }
    *current = node;
    bintree->size++;
    return 1;
}

// Node *pick(BinaryTree *bintree);

int empty(BinaryTree *bintree) {
    return bintree->size == 0;
}

int size(BinaryTree *bintree) {
    return bintree->size;
}

void printDFS(BinaryTree *bintree) {
    Node *current;
    Stack *stack = makeStack(bintree);
    push(stack, bintree->root);
    int count = 1;
    printf("[ ");
    while (!sempty(stack)) {
        current = pop(stack);
        count == bintree->size ? printf("%d ]\n", current->val) : printf("%d, ", current->val);
        if (current->right) push(stack, current->right);
        if (current->left) push(stack, current->left);
        count++;
    }
}

// void printBFS(BinaryTree *bintree);

static Stack *makeStack(BinaryTree *bintree) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->list = (Node **) malloc(sizeof(Node **) * bintree->size);
    stack->size = 0;
    return stack;
}

static int push(Stack *stack, Node *node) {
    stack->list[stack->size] = node;
    stack->size++;
    return 1;
}

static Node *pop(Stack *stack) {
    Node *ret = stack->list[stack->size - 1];
    stack->size--;
    return ret;
}

static int sempty(Stack *stack) {
    return stack->size == 0;
}

// static Queue *makeQueue();
// static int enqueue(Queue *queue, Node *node);
// static Node *dequeue(Queue *queue, int index);
// static int qempty(Queue *queue);
// void freeBinaryTree(BinaryTree *bintree);