#include <stdio.h>
#include <stdlib.h>

struct item {
  int value;
  struct item *next;
};

typedef struct item item;

int main() {
  printf("Hello\n");

  item a;
  item *list;
  a.next = NULL;
  list = &a;
}