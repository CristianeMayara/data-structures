#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

int main() {
  Tree *tree = NULL;

  tree = addElement(tree, 8);
  tree = addElement(tree, 3);
  tree = addElement(tree, 10);
  tree = addElement(tree, 14);
  tree = addElement(tree, 7);
  tree = addElement(tree, 13);
  tree = addElement(tree, 4);
  tree = addElement(tree, 6);
  tree = addElement(tree, 1);

  printInOrder(tree); printf("\n\n");
  printPreOrder(tree); printf("\n\n");
  printPostOrder(tree);

  if (findElement(tree, 35) == NULL)
    printf("\n\nElemento não encontrado.\n\n");
  else
    printf("\n\nElemento encontrado.\n\n");

  tree = removeElement(tree, 14);
  printInOrder(tree);

  Tree *aux = findInOrderSuccessor(tree, 7);
  if (aux != NULL)
    printf("\n\nO sucessor de 7 e: %d.\n", aux->value);
  else
    printf("\n\nO valor não tem sucessor.\n");

  printf("\nO pai de 3 e: %d.\n", findParent(tree, 3)->value);

  freeTree(tree);
}