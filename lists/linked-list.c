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

void printListRecursive(item *list) {
  item *aux;
  aux = list->next;
  if (aux != NULL) {
    printf("%i", aux->value);
    printListRecursive(aux);
  }
}

int isEmpty(item *list) {
  if (list->next == NULL)
    return 1;
  return 0;
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
  printListRecursive(list);
  
  isEmpty(list) ? printf("Vazia") : printf("Tem elemento");
}