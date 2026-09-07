#include <stdio.h>
#include <assert.h>

#include "set.h"
#include "hashmap.h"

int main() {
    printf("Testing Hashset:\n");

    Set myHashSet = newSet();
    setadd(myHashSet, 1);
    setadd(myHashSet, 2);
    assert(setcontains(myHashSet, 1));
    assert(!setcontains(myHashSet, 3));
    setadd(myHashSet, 2);
    assert(setcontains(myHashSet, 2));
    setremove(myHashSet, 2);
    assert(!setcontains(myHashSet, 2));
    printf("\tAll tests ran clean!\n");

    freeSet(&myHashSet);
    
    printf("\nTesting Hashmap:\n");

    HashMap myHashMap = newHashMap();
    hashmapput(myHashMap, 1, 1);
    hashmapput(myHashMap, 2, 2);
    assert(hashmapget(myHashMap, 1) == 1);
    assert(hashmapget(myHashMap, 3) == -1);
    hashmapput(myHashMap, 2, 1);
    assert(hashmapget(myHashMap, 2) == 1);
    hashmapremove(myHashMap, 2);
    assert(hashmapget(myHashMap, 2) == -1);
    printf("\tAll tests ran clean!\n");
    
    freeHashMap(&myHashMap);
    
    return 0;
}