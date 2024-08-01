#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(int argc, char **argv) {

    BinaryTree *bintree = makeBinaryTree();
    append(bintree, makeNode(9));
    append(bintree, makeNode(4));
    append(bintree, makeNode(7));
    append(bintree, makeNode(21));
    append(bintree, makeNode(2));
    append(bintree, makeNode(13));
    printDFS(bintree);
    printBFS(bintree);
    printf("The size of the binary tree is: %d\n", size(bintree));
    // TODO: this function still has to be debugged...
    Node *pickedNode = pick(bintree, 13);
    printf("The value of the picked node is: %d\n", pickedNode->val);
    printDFS(bintree);
    printf("The size of the binary tree is: %d\n", size(bintree));

    return EXIT_SUCCESS;
}