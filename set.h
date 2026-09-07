#ifndef __SET_H__
#define __SET_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "list.h"

#define ARRAY_SIZE 1000

typedef struct SetObj* Set;

// constructor
Set newSet();

// destructor
void freeSet(Set *setptr);

// add to the set
void setadd(Set set, int key);

// check if in set
bool setcontains(Set set, int key);

// remove element from set
void setremove(Set set, int key);

#endif