#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


typedef struct PQueue {
	int n,maxsize;
	int * keys;
} pq;

void *emalloc(size_t n);
int extractmin(pq * Q);
pq init(int n);
void insert(pq * Q, int key);
void show(pq * Q, int n);
void swap(pq * Q, int i, int j);