#include <stdio.h>
#include <stdlib.h>
#include "doubly-circular-linked-list.h"

int main() {
  list *list = createList();

  int value = 1;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, value);

  value = 5;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, value);

  value = 3;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, value);

  value = 7;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, value);

  printf("\n\nLista:\n");
  printList(list);
  printf("\n\n");

  isEmpty(list) ? printf("Lista vazia.\n") : printf("Lista com elementos.\n");

  printf("\nRemovendo valor %d...", list->head->value);
  removeFront(list);

  printf("\n\nLista:\n");
  printList(list);
  printf("\n");

  value = 3;
  findOccurrence(list, 3)
    ? printf("\nO valor %d esta na lista.\n", value) 
    : printf("\nO valor %d nao esta na lista.\n", value);

  value = 1;
  printf("\nRemovendo valor %d...", value);
  removeElement(list, value);

  printf("\n\nLista:\n");
  printList(list);
  printf("\n\n");
  
}