#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

int main() {
    printf("List0 tests: \n");
    // list tests
    // construction
    List list0 = newList();
    assert(list0 != NULL);

    // destruction
    freeList(&list0);
    assert(list0 == NULL);

    printf("\nList1 tests: \n");
    // try adding dummy key vals
    List list1 = newList();
    assert(list1 != NULL);

    prepend(list1, 0, 0);
    prepend(list1, 1, 1);
    prepend(list1, 2, 2);
    printList(list1);

    freeList(&list1); // also check for freeing with values attached
    assert(list1 == NULL);

    printf("\nList2 tests: \n");
    // try adding dummies and then deleting
    List list2 = newList();
    assert(list2 != NULL);

    prepend(list2, 0, 0);
    prepend(list2, 1, 1);
    printList(list2);

    deletekey(list2, 0);
    printList(list2);

    freeList(&list2);
    assert(list2 == NULL);

    printf("\nList3 tests: \n");
    // try adding dummies and then getting
    List list3 = newList();
    assert(list3 != NULL);

    prepend(list3, 0, 0);
    prepend(list3, 1, 1);
    printList(list3);

    printf("get result: %d\n", getval(list3, 1));

    // try changing existing
    changeval(list3, 1, 10);
    printf("get result: %d\n", getval(list3, 1));

    // try changing new
    changeval(list3, 2, 2);
    printList(list3);

    deletekey(list3, 1);
    printf("get result: %d\n", getval(list3, 1));


    freeList(&list3);
    assert(list3 == NULL);
}
