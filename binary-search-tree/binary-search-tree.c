#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

Tree *addElement(Tree *tree, int value) {
  if (tree == NULL) {
    tree = (Tree *) malloc(sizeof (Tree));
    if (tree == NULL) return NULL;

    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
  }

  if (tree->value > value) {
      tree->left = addElement(tree->left, value);
  } else {
      tree->right = addElement(tree->right, value);
  }

  return tree;
}

Tree *findElement(Tree *tree, int value) {
  if (tree == NULL) return NULL;
  if (tree->value == value) return tree;
  if (tree->value > value)
    return findElement(tree->left, value);

  return findElement(tree->right, value);
}

Tree *findParent(Tree *tree, int value) {
  if (tree == NULL) return NULL;

  if ((tree->left != NULL) && (tree->left->value == value)) return tree;
  if ((tree->right != NULL) && (tree->right->value == value)) return tree;

  if (tree->value > value) return findParent(tree->left, value);
  return findParent(tree->right, value);
}

Tree *findMinimum(Tree *tree) {
  if (tree == NULL) return tree;
  if (tree->left == NULL) return tree;
  return findMinimum(tree->left);
}

Tree *findInOrderSuccessor(Tree *tree, int value) {
  Tree *aux, *parent;
  aux = tree;
  
  // Case 0:
  if (tree == NULL) return NULL;

  aux = findElement(tree, value);

  // Case 1:
  if (aux->right != NULL) return findMinimum(aux->right);
  
  // Case 2:
  parent = findParent(tree, aux->value);

  while((parent != NULL) && (aux == parent->right)) {
    aux = parent;
    parent = findParent(tree, parent->value);
  }
  return parent;
}

Tree *removeElement(Tree *tree, int value) {
  Tree *aux;

  if (tree == NULL) return tree;

  if (value < tree->value) {
    tree->left = removeElement(tree->left, value);

  } else if (value > tree->value) {
    tree->right = removeElement(tree->right, value);

  } else if (tree->left && tree->right) {
    aux = findMinimum(tree->right);
    tree->value = aux->value;
    tree->right = removeElement(tree->right, tree->value);
    
  } else {
    aux = tree;
    if (tree->left == NULL) {
      tree = tree->right;
    } else if (tree->right == NULL) {
      tree = tree->left;
    }
    free(aux);
  }
  return tree;
}

void freeTree(Tree *tree) {
  if (tree == NULL) return;

  freeTree(tree->left);
  freeTree(tree->right); 
  free(tree);
}

void printInOrder(Tree *tree) {
  if (tree == NULL) return;

  printInOrder(tree->left);
  printf("%d ", tree->value);
  printInOrder(tree->right);
}

void printPreOrder(Tree *tree) {
  if (tree == NULL) return;

  printInOrder(tree->left);
  printInOrder(tree->right);
  printf("%d ", tree->value);
}

void printPostOrder(Tree *tree) {
  if (tree == NULL) return;

  printf("%d ", tree->value);
  printInOrder(tree->left);
  printInOrder(tree->right);
}