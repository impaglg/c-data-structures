#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node *makeNode(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Queue *makeQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->back = NULL;
    queue->len = 0;
    return queue;
}

int enqueue(Queue *queue, Node *node) {
    if (empty(queue)) {
        queue->front = node;
        queue->back = node;
        queue->len++;
        return 1;
    }
    queue->back->next = node;
    queue->back = node;
    queue->len++;
    return 1;
}

Node *dequeue(Queue *queue) {
    Node *temp;
    if (empty(queue)) {
        return NULL;
    }
    if (len(queue) == 1) {
        temp = queue->front;
        queue->front = NULL;
        queue->back = NULL;
        queue->len--;
        return temp;
    }
    temp = queue->front;
    queue->front = temp->next;
    temp->next = NULL;
    queue->len--;
    return temp;
}

int empty(Queue *queue) {
    return queue->len == 0;
}

int len(Queue *queue) {
    return queue->len;
}

void print(Queue *queue) {
    Node *current = queue->front;
    printf("[ ");
    while (current) {
        current->next ? printf("%d, ", current->val) : printf("%d ]\n", current->val);
        current = current->next;
    }
}

// TODO: check if the queue and all it's nodes actually get freed
void freeQueue(Queue *queue) {
    Node *temp;
    Node *current = queue->front;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
    return;
}