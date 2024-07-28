// Binary tree data structures definitions
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinaryTree {
    struct Node *root;
    int size;
} BinaryTree;

// Stack and queue implementation definition
typedef struct Stack {
    Node **list;
    int size;
} Stack;

typedef struct Queue {
    Node **list;
    int size;
} Queue;

BinaryTree *makeBinaryTree();
Node *makeNode(int val);
int append(BinaryTree *bintree, Node *node);
Node *pick(BinaryTree *bintree);
int empty(BinaryTree *bintree);
int size(BinaryTree *bintree);
void printDFS(BinaryTree *bintree);
void printBFS(BinaryTree *bintree);
static Stack *makeStack(BinaryTree *bintree);
static int push(Stack *stack, Node *node);
static Node *pop(Stack *stack);
static int sempty(Stack *stack);
static Queue *makeQueue();
static int enqueue(Queue *queue, Node *node);
static Node *dequeue(Queue *queue, int index);
static int qempty(Queue *queue);
void freeBinaryTree(BinaryTree *bintree);