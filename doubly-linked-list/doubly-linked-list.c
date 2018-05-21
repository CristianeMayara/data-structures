#include <stdlib.h>
#include <stdio.h>
#include "doubly-linked-list.h"

list *createList(void) {
  list *list = malloc(sizeof(list));
  list->head = NULL;
  list->size = 0;
  return list;
}

node *createNode(void* value) {
  node *node = malloc(sizeof(node));
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void pushFront(list *list, void *value) {
  node *new = createNode(value);

  if (!list->size) {
    new->next = new;
    new->prev = new;

  } else {
    node *head = list->head;
    node *prev = head->prev;

    new->next = head;
    new->prev = head->prev;

    head->prev = new;
    prev->next = new;
  }
  
  list->head = new;
  list->size++;
}
