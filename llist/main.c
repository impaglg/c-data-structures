#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char **argv) {

    LinkedList *list = makeList();
    for (int i = 1; i <= 10; i++) {
        insertNode(list, makeNode(i));
    }
    printList(list);
    for (int i = 0; i < 3; i++) {
        removeNode(list);
    }
    printList(list);
    removeNodeAt(list, 1);
    printList(list);
    printf("The size of the list is: %d\n", size(list));
    removeNodeAt(list, 6);
    printList(list);
    reverse(list);
    printList(list);
    for (int i = 1; i > -3; i--) {
        insertNode(list, makeNode(i));
    }
    printList(list);
    printf("The size of the list is: %d\n", size(list));

    return EXIT_SUCCESS;

}