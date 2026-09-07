#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stdlib.h>

#include "utils.h"
#include "list.h"

#define ARRAY_SIZE 1000

typedef struct HashMapObj *HashMap;

// constructor
HashMap newHashMap();

// destructor
void freeHashMap(HashMap *hashmapptr);

// put
void hashmapput(HashMap hashmap, int key, int val);

// get
int hashmapget(HashMap hashmap, int key);

// remove
void hashmapremove(HashMap hashmap, int key);

#endif