#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "set.h"

int main() {
    // test construction
    Set set = newSet();
    assert(set != NULL);

    freeSet(&set);
    assert(set == NULL);

    // more tests
    Set set1 = newSet();
    
    setadd(set1, 0);
    setadd(set1, 1);
    setadd(set1, 2);

    assert(setcontains(set1, 0));
    assert(!setcontains(set1, 3));

    setremove(set1, 0);

    assert(!setcontains(set1, 0));
    assert(setcontains(set1, 2));

    freeSet(&set1);
    return 0;
}