#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define LEFT ((i) << 1)
#define RIGHT (( (i) << 1 ) + 1)
#define PARENT ((i) >> 1)
#define LAST_PARENT (n >> 1)

typedef int (*function_ptr) (const void *, const void *);
int compareInt (const int *a, const int *b);
int compareDbl (const int *a, const int *b);
int compareChar (const char *a, const char *b);
void heapifyDown (void *a [], int n, int i, function_ptr function);
void heapifyUp (void *a [], int i, function_ptr function);
void insert (void *a [], int n, void *x, function_ptr function);
void removeElement (void *a [], int n, function_ptr function);
void build (void *a [], int n, function_ptr function);
void heapsort (void *a [], int n, function_ptr function);
void printInt (int *a [], int n);
void printDbl (double *a [], int n);
void printChar (char *a [], int n);
void printStr (char *a [], int n);

#endif // MAX_HEAP_H