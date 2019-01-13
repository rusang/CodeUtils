#include "priorityqueue.h"


/*
	Priority Queue
*/

void *emalloc(size_t n) {
	void *p;
	p = malloc(n);
	if (p == NULL) {
		fprintf(stderr, "emalloc of %u bytes failed", (unsigned int) n);
		exit(1);
	}
	return p;
}
int extractmin(pq * Q) {
	int i,c;
	int t = Q->keys[1];
	Q->keys[1]=Q->keys[Q->n--];
	for(i=1;(c=2*i)<=Q->n;i=c)
	{
		if( ( c + 1 <= Q->n ) && ( Q->keys[c+1] < Q->keys[c] ) ) {
			c++;
		}
		if( Q->keys[i] <= Q->keys[c] ) {
			break;
		}
		swap(Q,c,i);
	}
	return t;
}
pq init(int n) {
	pq Q;
	Q.maxsize = n*3;
	Q.keys = (int *) emalloc((Q.maxsize+1)*(sizeof(int *)));
	Q.n=0;
	return Q;
}
void insert(pq * Q, int key) {
	int i,p;
	Q->n++;
	Q->keys[Q->n] = key;
	for(i = Q->n;( i > 1) && (Q->keys[p=i/2] > Q->keys[i]); i=p)
	{
		swap(Q,p,i);
	}
}
void swap(pq * Q, int i, int j) 
{
	int temp = Q->keys[i];
	Q->keys[i] = Q->keys[j];
	Q->keys[j] = temp;
}
int main (int argc, char const *argv[])
{
	return 0;
}