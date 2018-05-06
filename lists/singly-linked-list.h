#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct item {
  int value;
  struct item *next;
} item;

item *newList();

void pushFront(int value, item *element);

item *findElement(int value, item *list);

item *findElementRecursively(int value, item *list);

void removeElement(item *previous);

void findAndRemoveElement(int value, item *list);

void findAndRemoveElementRecursively(int value, item *list);

void printList(item *list);

void printListRecursively(item *list);

int isEmpty(item *list);

void freeList(item *list);

#endif // SINGLY_LINKED_LIST_H