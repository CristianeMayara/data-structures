#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Tree;

Tree *addElement(Tree* tree, int value);
Tree *findElement(Tree * tree, int value);
Tree *findParent(Tree * tree, int value);
Tree *findMinimum(Tree *tree);
Tree *removeElement(Tree *tree, int value);
void freeTree(Tree *tree);
void printInOrder(Tree* tree);
void printPreOrder(Tree* tree);
void printPostOrder(Tree* tree);

#endif // BINARY_SEARCH_TREE_H
