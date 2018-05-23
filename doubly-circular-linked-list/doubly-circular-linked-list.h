#ifndef DOUBLY_CIRCULAR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_LINKED_LIST_H

typedef struct node {
  struct node *prev;
  struct node *next;
  int value;
} node;

typedef struct list {
  struct node* head;
  int size;
} list;

list *createList(void);
node *createNode(int value);
void pushFront(list *list, int value);
void printList(list *list);
int isEmpty(list *list);
node *findOccurrence(list *list, int value);
void freeNode(node *node);
void removeFront(list *list);

#endif // DOUBLY_CIRCULAR_LINKED_LIST_H
