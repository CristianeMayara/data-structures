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

  item *findedR = findElementRecursively(1, list);
  (findedR != NULL) ? printf("\nElemento encontrado: %d\n", findedR->value) : printf("\nElemento não encontrado\n");

  printf("\n");
  findAndRemoveElement(1, list);
  printList(list);
}
