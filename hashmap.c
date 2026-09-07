#include <stdlib.h>

#include "hashmap.h"
#include "list.h"

typedef struct HashMapObj *HashMap;

typedef struct HashMapObj {
    List data[ARRAY_SIZE];
} HashMapObj;

// constructor
HashMap newHashMap() {
    HashMap new = malloc(sizeof(HashMapObj));
    for (int i=0; i<ARRAY_SIZE; i++) {
        new->data[i] = newList();
    }
    return new;
}

// destructor
void freeHashMap(HashMap *hashmapptr) {
    if (hashmapptr != NULL && *hashmapptr != NULL) {
        for (int i=0; i<ARRAY_SIZE; i++) {
            freeList(&(*hashmapptr)->data[i]);
        }
        free(*hashmapptr);
        *hashmapptr = NULL;
    }
}

// put - insert key, val into the hashmap
void hashmapput(HashMap hashmap, int key, int val) {
    int idx = getidx(key);
    changeval(hashmap->data[idx], key, val);
}

// get - find a value by key, return -1 if not found
int hashmapget(HashMap hashmap, int key) {
    int idx = getidx(key);
    return getval(hashmap->data[idx], key);
}

// remove - delete a value by key, return -1 if not found
void hashmapremove(HashMap hashmap, int key) {
    int idx = getidx(key);
    if (getval(hashmap->data[idx], key) < 0) {
        return;
    }
    deletekey(hashmap->data[idx], key);
}