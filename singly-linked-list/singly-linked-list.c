#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

item *newList() {
  item *head = (item*)malloc(sizeof(item));
  head->next = NULL;

  return head;
}

void pushFront(int value, item *element) {
  item *new;
  new = malloc(sizeof(item));
  new->value = value;
  new->next = element->next;
  element->next = new;
}

item *findElement(int value, item *list) {
  item *aux;
  aux = list;

  while((aux != NULL) && (aux->value != value)) {
    aux = aux->next;
  }
  return aux;
}

item *findElementRecursively(int value, item *list) {
  if (list == NULL) return list;
  if (list->value == value) return list;
  return findElementRecursively (value, list->next);
}

void removeElement(item *previous) {
  item *trash;
  trash = previous->next;
  previous->next = trash->next;
  free(trash);
}

void findAndRemoveElement(int value, item *list) {
  item *previous, *trash;
  previous = list;
  trash = list->next;

  while((trash != NULL) && (trash->value != value)) {
    previous = trash;
    trash = trash->next;
  }
  
  if(trash != NULL)
    removeElement(previous);
}

void findAndRemoveElementRecursively(int value, item *list) {
  if (list == NULL) return;
  if (list->next == NULL) return;
  if (list->next->value == value) removeElement(list);

  return findAndRemoveElementRecursively (value, list->next);
}

void printList(item *list) {
  item *aux;
  aux = list->next;

  while (aux != NULL) {
    printf("%i", aux->value);
    aux = aux->next;
  }
}

void printListRecursively(item *list) {
  item *aux;
  aux = list->next;
  if (aux != NULL) {
    printf("%i", aux->value);
    printListRecursively(aux);
  }
}

int isEmpty(item *list) {
  if (list->next == NULL)
    return 1;
  return 0;
}

void freeList(item *list) {
  if (list == NULL) free(list);

  item *current, *next;
  current = list;
  next = list->next;

  while(next != NULL) {
    free(current);
    current = next;
    next = next->next;
  }

  list->next = NULL;
  free(list);
}
