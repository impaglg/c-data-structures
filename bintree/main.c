#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(int argc, char **argv) {

    BinaryTree *bintree = makeBinaryTree();
    append(bintree, makeNode(9));
    append(bintree, makeNode(4));
    append(bintree, makeNode(7));
    printDFS(bintree);

    return EXIT_SUCCESS;
}