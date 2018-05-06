#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

int main() {
  item *list = newList();

  pushFront(1, list);
  pushFront(2, list);
  pushFront(3, list);
  pushFront(4, list);
  pushFront(5, list);

  printf("\nLista: ");
  printList(list);
  printListRecursively(list);

  isEmpty(list) ? printf("\nLista vazia\n") : printf("\nTem elemento na lista\n");

  item *finded = findElement(1, list);
  (finded != NULL) ? printf("\nElemento encontrado: %d\n", finded->value) : printf("\nElemento não encontrado\n");

  item *findedR = findElementRecursively(1, list);
  (findedR != NULL) ? printf("\nElemento encontrado: %d\n", findedR->value) : printf("\nElemento não encontrado\n");

  printf("\n");
  findAndRemoveElement(1, list);
  printList(list);

  printf("\n");
  findAndRemoveElementRecursively(5, list);
  printList(list);
  printf("\n");

  freeList(list);
}