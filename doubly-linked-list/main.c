#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

int main() {
  list *list = createList();

  int value = 1;

  printf("\nAdicionando valor %d...", value);
  pushFront(list, &value);

  value = 5;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, &value);

  value = 3;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, &value);

  value = 7;
  printf("\nAdicionando valor %d...", value);
  pushFront(list, &value);
}