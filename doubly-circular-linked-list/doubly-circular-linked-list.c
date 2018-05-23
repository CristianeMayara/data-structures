#include <stdlib.h>
#include <stdio.h>
#include "doubly-circular-linked-list.h"

list *createList(void) {
  list *list = malloc(sizeof(list));
  list->head = NULL;
  list->size = 0;
  return list;
}

node *createNode(int value) {
  node *node = malloc(sizeof(node));
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void pushFront(list *list, int value) {
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

void printList(list *list) {
  node *aux;
  aux = list->head;

  int i;
  for (i = 0; i < list->size; i++) {
    printf("%d ", aux->value);
    aux = aux->next;
  }
}

int isEmpty(list *list) {
  return list->size == 0;
}

node *findOccurrence(list *list, int value) {
  node *aux;
  aux = list->head;

  int i;
  for (i = 0; i < list->size; i++) {
    if (aux->value == value) return aux;
  }
  return NULL;
}

void freeNode(node *node) {
  free(node->prev);
  free(node->next);
  free(node);
}

void removeFront(list *list) {
  node *head = list->head;

  if (isEmpty(list)) return;

  if (list->size == 1) {
    list->head = NULL;

  } else {
    node *next = head->next;
    node *prev = head->prev;

    list->head = next;

    next->prev = prev;
    prev->next = next;
  }

  freeNode(head);

  list->size--;
}