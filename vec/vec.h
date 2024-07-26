typedef struct Vector {
    int *array;
    int size;
    int max_size;
} Vector;

Vector *makeVec();
int insertElement(Vector *vec, int val);
int removeElement(Vector *vec);
Vector *vecResize(Vector *vec);
Vector *vecDownsize(Vector *vec);
void printVec(Vector *vec);