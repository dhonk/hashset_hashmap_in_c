#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// struct definitions
typedef struct NodeObj* Node;

typedef struct NodeObj {
    int key;
    int val;
    Node next;
    Node prev;
} NodeObj;

typedef struct ListObj* List;

typedef struct ListObj {
    Node head;
} ListObj;

// constructors
Node newNode(int key, int val) {
    Node new = malloc(sizeof(NodeObj));
    new->key = key;
    new->val = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

List newList() {
    List new = malloc(sizeof(ListObj));
    new->head = NULL;
    return new;
}

// destructors
void freeNode(Node* nodeptr) {
    if (nodeptr != NULL && *nodeptr != NULL) {
        free(*nodeptr);
        *nodeptr = NULL;
    }
}

void freeList(List* listptr) {
    if (listptr != NULL && *listptr != NULL) {
        Node cursor = (*listptr)->head;
        while (cursor != NULL) {
            Node temp = cursor;
            cursor = cursor->next;
            freeNode(&temp);
        }

        free(*listptr);
        *listptr = NULL;
    }
}

// find node in list by key, if not found, return NULL
Node find(List list, int key) {
    Node cursor = list->head;
    while (cursor != NULL) {
        if (cursor->key == key) {
            return cursor;
        } 
        cursor = cursor->next;
    }
    return NULL;
}

// get the val of a node, -1 if not found
int getval(List list, int key) {
    Node node = find(list, key);
    if (node == NULL) {
        return -1;
    } else {
        return node->val;
    }
}

// change val of node, if not found, then prepend.
void changeval(List list, int key, int val) {
    Node node = find(list, key);
    if (node == NULL) {
        prepend(list, key, val);
    } else {
        node->val = val;
    }
}

// delete node by key - needs stitching
void deletekey(List list, int key) {
    Node node = find(list, key);
    if (node == NULL) {
        exit(EXIT_FAILURE);
    } else {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            list->head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        }
    }

    freeNode(&node);
}

// prepend node to list
void prepend(List list, int key, int val) {
    Node new = newNode(key, val);
    if (list->head == NULL) {
        list->head = new;
        return;
    }
    
    list->head->prev = new;
    new->next = list->head;
    list->head = new;
}

// print list for debug
void printList(List list) {
    printf("List: ");
    Node cursor = list->head;
    while (cursor) {
        printf("(%d, %d), ", cursor->key, cursor->val);
        cursor = cursor->next;
    }
    printf("\n");
}