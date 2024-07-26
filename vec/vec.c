#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec.h"

Vector *makeVec() {
    Vector *vec = (Vector *) malloc(sizeof(Vector));
    vec->array = (int *) malloc(sizeof(int) * 10);
    vec->size = 0;
    vec->max_size = 10;
    return vec;
}

int insertElement(Vector *vec, int val) {
    if (vec->size + 1 > vec->max_size) {
        vec = vecResize(vec);
    }
    vec->array[vec->size] = val;
    vec->size++;
    return 1;
}

int removeElement(Vector *vec) {
    vec->array[vec->size - 1] = 0;
    vec->size--;
    if (vec->size == vec->max_size / 2) {
        vec = vecDownsize(vec);
    }
    return 1;
}

Vector *vecResize(Vector *vec) {
    vec->array = (int *) realloc(vec->array, sizeof(int) * vec->max_size * 2);
    vec->max_size = vec->max_size * 2;
    return vec;
}

Vector *vecDownsize(Vector *vec) {
    vec->array = (int *) realloc(vec->array, sizeof(int) * (vec->max_size / 2));
    vec->max_size = vec->max_size / 2;
    return vec;
}

void printVec(Vector *vec) {
    for (int i = 0; i < vec->size; i++) {
        i == vec->size - 1 ? printf("%d ]\n", vec->array[i]) : printf("%d, ", vec->array[i]);
    }
    return;
}