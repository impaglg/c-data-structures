// list node definition
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// linked list definition
typedef struct LinkedList {
    struct Node *head;
    int size;
} LinkedList;

Node *makeNode(int val);
LinkedList *makeList();
int insertNode(LinkedList *list, Node *node);
int removeNode(LinkedList *list);
int removeNodeAt(LinkedList *list, int index);
int removeNodeFromTo(LinkedList *list, int start, int end);
int reverse(LinkedList *list);
int reverseFromTo(LinkedList *list, int start, int end);
int empty(LinkedList *list);
int size(LinkedList *list);
void printList(LinkedList *list);