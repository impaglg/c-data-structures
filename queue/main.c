#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char **argv) {

    Queue *queue = makeQueue();
    for (int i = 1; i <= 10; i++) {
        enqueue(queue, makeNode(i));
    }
    print(queue);
    for (int i = 0; i < 3; i++) {
        Node *front_node = dequeue(queue);
        printf("The value of the front node is: %d\n", front_node->val);
    }
    print(queue);
    printf("The length of the queue is: %d\n", len(queue));
    freeQueue(queue);

    return EXIT_SUCCESS;
}