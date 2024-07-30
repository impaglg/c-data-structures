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

// TODO: this function allows for the removal of any node in the tree
Node *pick(BinaryTree *bintree, int val) {
    Node *current = bintree->root;
    while (current) {
        if (current->val == val) {
            if (isLeaf(current)) {
                // do the thing
                break;
            } else if (hasSingleChild(current)) {
                // do the thing again
                break;
            } else {
                // do that other thing
                break;
            }
        }
        if (current->val > val) {
            current = current->left;
        }
        if (current->val < val) {
            current = current->right;
        }
    }
    return current;
}

int empty(BinaryTree *bintree) {
    return bintree->size == 0;
}

int size(BinaryTree *bintree) {
    return bintree->size;
}

int isLeaf(Node *node) {
    return !node->left && !node->right;
}

int hasSingleChild(Node *node) {
    return node->left && !node->right || node->right && !node->left;
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

void printBFS(BinaryTree *bintree) {
    Node *current;
    Queue *queue = makeQueue(bintree);
    enqueue(queue, bintree->root);
    int count = 1;
    printf("[ ");
    while (!qempty(queue)) {
        current = dequeue(queue);
        count == bintree->size ? printf("%d ]\n", current->val) : printf("%d, ", current->val);
        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
        count++;
    }
}

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

static Queue *makeQueue(BinaryTree *bintree) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->list = (Node **) malloc(sizeof(Node **) * bintree->size);
    queue->len = 0;
    queue->front = 0;
    return queue;
}

static int enqueue(Queue *queue, Node *node) {
    queue->list[queue->len] = node;
    queue->len++;
    return 1;
}

static Node *dequeue(Queue *queue) {
    Node *ret = queue->list[0];
    for (int i = 1; i < queue->len + 1; i++) {
        queue->list[i - 1] = queue->list[i];
    }
    queue->len--;
    return ret;
}

static int qempty(Queue *queue) {
    return queue->len == 0;
}

// void freeBinaryTree(BinaryTree *bintree);