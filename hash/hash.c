#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

itemH *createElement(int value) {
  itemH *node = (itemH *)malloc(sizeof(itemH));
  node->value = value;
  return node;
}
