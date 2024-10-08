#include <stdio.h>
#include <stdlib.h>
#include "circbuf.h"

int main(int argc, char **argv) {

    CircularBuffer *buffer = makeBuffer(10);
    for (int i = 0; i < buffer->MAX_SIZE; i++) {
        enqueue(buffer, i * 10);
    }
    printBuffer(buffer);

    return EXIT_SUCCESS;
}