#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max-heap.h"

int main(){
  int i;

  int *array [10];

  for (i = 0; i < 10; i++){
      array[i] = (int*) malloc( sizeof(int) );
  }

  *array[1] = 3;
  *array[2] = 5;
  *array[3] = 1;
  *array[4] = 20;
  *array[5] = 11;
  *array[6] = 4;
  *array[7] = 8;
  *array[8] = 9;

  
  printInt(array, 8);
  heapsort ((void*)array, 8, (function_ptr) compareInt);
  printf("\n\n");
  printInt(array, 8);
  printf("\n\n");

  return(0);
}
