#ifndef HASH_H
#define HASH_H

#include "singly-linked-list/singly-linked-list.h"
#define HASH_SIZE 20000

typedef struct itemH {
  int value;
} itemH;

typedef struct Hash {
  list array[HASH_SIZE];   
} Hash;

itemH *createElement(int value);
int hashFunction(int value);
void addElement(Hash *hash, int value);

#endif // HASH_H
