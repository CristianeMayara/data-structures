#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct node {
  struct node *prev;
  struct node *next;
  void *data;
} node;

typedef struct list {
  struct node* head;
  int size;
} list;

list *createList(void);
node *createNode(void* data);

#endif // DOUBLY_LINKED_LIST_H