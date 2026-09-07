#ifndef __LIST_H__
#define __LIST_H__

typedef struct ListObj* List;

// constructor
List newList();

// destructor
void freeList(List* listptr);

// get val of node, -1 if not found
int getval(List list, int key);

// change val of node, if not found, then prepend
void changeval(List list, int key, int val);

// delete node by key - needs stitching
void deletekey(List list, int key);

// prepend a new element to the list
void prepend(List list, int key, int val);

// prints
void printList(List list);

#endif