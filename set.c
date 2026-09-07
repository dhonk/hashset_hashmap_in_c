#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "set.h"
#include "list.h"

typedef struct SetObj* Set;

typedef struct SetObj {
    List data[ARRAY_SIZE];
} SetObj;

// constructor
Set newSet() {
    Set set = malloc(sizeof(SetObj));
    for (int i=0; i<ARRAY_SIZE; i++) {
        set->data[i] = newList();
    }
    return set;
}

// destructor
void freeSet(Set *setptr) {
    if (setptr != NULL && *setptr != NULL) {
        for (int i=0; i<ARRAY_SIZE; i++) {
            freeList(&(*setptr)->data[i]);
        }

        free(*setptr);
        *setptr = NULL;
    }
}

// add to set
void setadd(Set set, int key) {
    int idx = getidx(key);
    changeval(set->data[idx], key, 0);
}

// check if the set contains an element
bool setcontains(Set set, int key) {
    int idx = getidx(key);
    return getval(set->data[idx], key) >= 0;
}

// remove an element from the set
void setremove(Set set, int key) {
    int idx = getidx(key);
    deletekey(set->data[idx], key);
}