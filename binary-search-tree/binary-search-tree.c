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