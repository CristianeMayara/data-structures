#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

itemH *createElement(int value) {
  itemH *node = (itemH *)malloc(sizeof(itemH));
  node->value = value;
  return node;
}

int hashFunction(int value) {
  return value % SIZE_HASH;
}

void addElement(Hash *hash, int value) {
  pushFront(&(hash->array[hashFunction(value)]), create_node_hash(value));
}