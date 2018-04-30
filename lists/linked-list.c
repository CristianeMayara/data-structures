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

int main() {
  item a;
  item *list;
  a.next = NULL;
  list = &a;
}