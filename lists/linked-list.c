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

item *findElement(int value, item *list) {
  item *aux;
  aux = list;

  while((aux != NULL) && (aux->value != value)) {
    aux = aux->next;
  }
  return aux;
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

  printf("\nLista: ");
  printList(list);
  printListRecursively(list);

  isEmpty(list) ? printf("\nLista vazia\n") : printf("\nTem elemento na lista\n");

  item *finded = findElement(1, list);
  (finded != NULL) ? printf("\nElemento encontrado: %d\n", finded->value) : printf("\nElemento não encontrado\n");
}
