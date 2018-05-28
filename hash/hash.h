#ifndef HASH_H
#define HASH_H

#include "doubly-circular-linked-list/doubly-circular-linked-list.h"
#define HASH_SIZE 20000

typedef struct item {
  int value;
} item;

typedef struct Hash {
  list array[HASH_SIZE];   
} Hash;

#endif // HASH_H
