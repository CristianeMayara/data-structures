#include <stdlib.h>
#include <stdio.h>
#include "doubly-linked-list.h"

list *createList(void) {
  list *l = malloc(sizeof(list));
  l->head = NULL;
  l->size = 0;
  return l;
}

node *createNode(void* data) {
  node *n = malloc(sizeof(node));
  n->data = data;
  n->prev = NULL;
  n->next = NULL;
  return n;
}