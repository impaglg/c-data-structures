#include <stdio.h>
#include <stdlib.h>
#include "circbuf.h"

CircularBuffer *makeBuffer(const int size) {
    CircularBuffer *buffer = (CircularBuffer *) malloc(sizeof(CircularBuffer));    
    buffer->buffer = (int *) malloc(sizeof(int) * size);
    buffer->read = 0;
    buffer->write = 0;
    buffer->size = 0;
    buffer->MAX_SIZE = size;
    return buffer;
}

int enqueue(CircularBuffer *buffer, int val) {
    buffer->buffer[buffer->write] = val;
    if (buffer->write == buffer->read && buffer->size != 0) {
        buffer->read = updateRead(buffer);
    }
    buffer->write = updateWrite(buffer);
    buffer->size++;
    return 1;
}

int dequeue(CircularBuffer *buffer) {
    int val = buffer->buffer[buffer->read];
    updateRead(buffer);
    buffer->size--;
    return val;
}

int updateRead(CircularBuffer *buffer) {
    buffer->read++;
    if (buffer->read == buffer->MAX_SIZE) {
        buffer->read /= buffer->MAX_SIZE;
    }
    return buffer->read;
}

int updateWrite(CircularBuffer *buffer) {
    buffer->write++;
    if (buffer->write == buffer->MAX_SIZE) {
        buffer->write /= buffer->MAX_SIZE;
    }
    return buffer->write;
}

// TODO: print an empty array if the array is empty -- DUH!!!
void printBuffer(CircularBuffer *buffer) {
    printf("[ ");
    for (int i = buffer->read; i < buffer->write + buffer->size - 1; i++) {
        i + 1 == buffer->write + buffer->size - 1 ? printf("%d ]\n", buffer->buffer[i]) : printf("%d, ", buffer->buffer[i]);
    }
}

void freeBuffer(CircularBuffer *buffer) {
    for (int i = 0; i < buffer->MAX_SIZE; i++) {
        buffer->buffer[i] = 0;
    }
    free(buffer->buffer);
    free(buffer);
}