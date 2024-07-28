typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front;
    struct Node *back;
    int len;
} Queue;

Node *makeNode(int val);
Queue *makeQueue();
int enqueue(Queue *queue, Node *node);
Node *dequeue(Queue *queue);
int empty(Queue *queue);
int len(Queue *queue);
void print(Queue *queue);
void freeQueue(Queue *queue);