#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max-heap.h"

int main(){
  int i;

  int *vet [10];

  for (i = 0; i < 10; i++){
      vet[i] = (int*) malloc( sizeof(int) );
  }

  *vet[1] = 3;
  *vet[2] = 5;
  *vet[3] = 1;
  *vet[4] = 20;
  *vet[5] = 11;
  *vet[6] = 4;
  *vet[7] = 8;
  *vet[8] = 9;

  
  printInt(vet, 8);
  heapsort4 ((void*)vet, 8, (function_ptr) compareInt);
  printf("\n\n");
  printInt(vet, 8);
  printf("\n\n");

  return(0);
}
