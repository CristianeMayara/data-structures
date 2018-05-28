#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

itemH *createElement(int value) {
  itemH *node = (itemH *)malloc(sizeof(itemH));
  node->value = value;
  return node;
}

int hashFunction(int value) {
  return value % HASH_SIZE;
}

void addElement(Hash *hash, int value) {
  pushFront(&(hash->array[hashFunction(value)]), create_node_hash(value));
}

void freeHash(Hash *hash) {
  for(int i = 0; i < HASH_SIZE; i++ ) {
    for(int j = 0; i < hash->array->length; j++) {
      free(hash->array[i].head->item);
      removeElement(&(hash->array[i]), hash->array->head);
    }
  }
}