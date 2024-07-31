typedef struct CircularBuffer {
    int *buffer;
    int read;
    int write;
    int size;
    int MAX_SIZE;
} CircularBuffer;

CircularBuffer *makeBuffer(const int MAX_SIZE);
int enqueue(CircularBuffer *buffer, int val);
int dequeue(CircularBuffer *buffer);
int updateRead(CircularBuffer *buffer);
int updateWrite(CircularBuffer *buffer);
void printBuffer(CircularBuffer *buffer);
void freeBuffer(CircularBuffer *buffer);