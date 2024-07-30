#include <stdio.h>
#include <stdlib.h>
#include "circbuf.h"

// this is the buffer prototype
// remember to update both pointers if read and write have the same valu
// remember that you don't have to set the values to zero, they will be overwritten
//
// typedef struct CircularBuffer {
//     int *buffer;
//     int read;
//     int write;
//     const int MAX_SIZE;
// } CircularBuffer;

// CircularBuffer *makeBuffer(const int MAX_SIZE);
// int enqueue(CircularBuffer *buffer, int val);
// int dequeue(CircularBuffer *buffer);
// void printBuffer(CircularBuffer *buffer);
// void freeBuffer(CircularBuffer *buffer);