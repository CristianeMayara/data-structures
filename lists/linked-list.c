#include <stdio.h>
#include <stdlib.h>

struct item {
  int value;
  struct item *next;
};

typedef struct item item;

void insertAtStart(int value, item *element) {
  item *new;
  new = malloc(sizeof(item));
  new->value = value;
  new->next = element->next;
  element->next = new;
}

void printList(item *list) {
  item *aux;
  aux = list->next;

  while (aux != NULL) {
    printf("%i", aux->value);
    aux = aux->next;
  }
}

int main() {
  item a;
  item *list;
  a.next = NULL;
  list = &a;

  insertAtStart(1, list);
  insertAtStart(2, list);
  insertAtStart(3, list);
  insertAtStart(4, list);
  insertAtStart(5, list);

  printList(list);
}