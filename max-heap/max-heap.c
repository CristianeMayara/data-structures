/*
  Generic heap that uses comparison function. Vector with start in position 1.
*/

#include <stdio.h>
#include <stdlib.h>

#define LEFT ((i) << 1)
#define RIGHT (( (i) << 1 ) + 1)
#define PARENT ((i) >> 1)
#define LAST_PARENT (n >> 1)

/*
  This method used to maintain the heap property while deleting an element.
*/
void heapifyDown (void *a [], int n, int i, function_ptr function){
  int largest;
  void *aux;

  aux = a[i];
  while (i <= LAST_PARENT){
    largest = LEFT;
    if ( (RIGHT <= n) && (function (a[RIGHT], a[LEFT]) > 0) ){ // check the largest of the children
      largest = RIGHT;
    }
    if (function (a[largest], aux) > 0){
      a[i] = a[largest];
      i = largest; // i receives child
    }
    else break;
  }
  a[i] = aux;
}

/*
  This method used to maintain the heap property while inserting an element.
*/
void heapifyUp (void *a [], int i, function_ptr function){
  void *aux;

  while (i >= 2){ // PARENT >= 1
    if ( function (&a[PARENT], &a[i]) < 0 ){ // compares with the parent
      aux = a[PARENT];
      a[PARENT] = a[i];
      a[i] = aux;
      i = PARENT; // i receives parent
    }
    else break;
  }
}

/*
  This method will insert new element in to heap.
*/
void insert (void *a [], int n, void *x, function_ptr function){
    n++;
    a[n] = x;
    heapifyUp (a, n, function);
}

/*
  This method will remove the element at n index.
*/
void removeElement (void *a [], int n, function_ptr function){
  void *aux;

  aux = a[1];
  a[1] = a[n];
  a[n] = aux;
  n--;
  heapifyDown (a, n, 1, function);
}

/*
  Build a Max Heap given an array of numbers.
*/
void build (void *a [], int n, function_ptr function){
  int i;

  for (i = LAST_PARENT; i >= 1; i--){
    heapifyDown (a, n, i, function);
  }
}