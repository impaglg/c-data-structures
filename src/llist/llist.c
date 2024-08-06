#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

Node *makeNode(int val) {
    Node *node = (Node *) malloc(sizeof(node));
    node->val = val;
    node->next = NULL;
    return node;
}

LinkedList *makeList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int insertNode(LinkedList *list, Node *node) {
    if (empty(list)) {
        list->head = node;
        list->size++;
        return 1;
    }
    Node **current = &list->head;
    while (*current) {
        current = &(*current)->next;
    }
    *current = node;
    list->size++;
    return 1;
}

int removeNode(LinkedList *list) {
    if (empty(list)) {
        return -1;
    }
    if (size(list) == 1) {
        list->head = NULL;
        list->size--;
        free(list->head);
        return 1;
    }
    Node *prev;
    Node *current = list->head;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    list->size--;
    current = NULL;
    free(current);
    return 1;
}

int removeNodeAt(LinkedList *list, int index) {
    if (empty(list)) {
        return -1;
    }
    if (index > size(list)) {
        return -1;
    }
    if (index == 1) {
        Node *temp = list->head;
        list->head = temp->next;
        list->size--;
        temp = NULL;
        free(temp);
        return 1;
    }
    int count = 1;
    Node *prev;
    Node *current = list->head;
    Node *next = current->next;
    while (current) {
        if (count == index) {
            Node *temp = current;
            prev->next = next;
            list->size--;
            temp = NULL;
            free(temp);
            return 1;
        }
        prev = current;
        current = next;
        next = current->next;
        count++;
    }
    return -1;
}

int removeNodeFromTo(LinkedList *list, int start, int end) {
    return -1;
}

int reverse(LinkedList *list) {
    if (empty(list)) {
        return -1;
    }
    if (size(list) == 1) {
        return -1;
    }
    Node *prev;
    Node *current = list->head;
    Node *next = current->next;
    while (next) {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
    }
    current->next = prev;
    list->head = current;
    free(next);
    return 1;
}

// TODO: complete the function, maybe the static function is not a good idea though...
// [ 13, 9, 18, 7, 11, 7, 36, 71, 10 ]
int reverseFromTo(LinkedList *list, int start, int end) {
    if (empty(list) || start < 1 || end > list->size) {
        return -1;
    }
    Node *list_anchor_one;
    Node *list_anchor_two;
    Node *sublist_tail;
    Node *sublist_head;
    Node *current = list->head;
    Node *prev;
    Node *next;
    int index = 1;
    while (current) {
        if (index == start) {
            list_anchor_one = prev;
            sublist_head = current;
            current = current->next;
            index++;
            while (index != end) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                index++;
            }
            sublist_tail = current;
            list_anchor_two = next;
            sublist_head->next = list_anchor_two;
            sublist_tail->next = list_anchor_one;
            return 1;
        }
        prev = current;
        current = current->next;
        index++;
    }
    return -1;
}

int empty(LinkedList *list) {
    return size(list) == 0;
}

int size(LinkedList *list) {
    return list->size;
}

void printList(LinkedList *list) {
    if (empty(list)) {
        printf("[ ]\n");
    }
    Node *current = list->head;
    printf("[ ");
    while (current) {
        current->next == NULL ? printf("%d ]\n", current->val) : printf("%d, ", current->val);
        current = current->next;
    }
    return;
}