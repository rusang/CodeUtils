#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

deque_type *
deque_alloc()
{
	deque_type *d = malloc(sizeof(deque_type));

	if (d != NULL)
		d->head = d->tail = NULL;

	return d;
}

void
deque_free(deque_type *d)
{
	free(d);
}

bool
deque_is_empty(deque_type *d)
{
	return d->head == NULL;
}

void
deque_push_front(deque_type *d, deque_val_type v)
{
	struct node_struct *n = malloc(sizeof(struct node_struct));
	assert(n != NULL);
	n->val = v;
	n->next = d->head;
	n->prev = NULL;

	if (d->tail == NULL)
		d->head = d->tail = n;

	else {
		d->head->prev = n;
		d->head = n;
	}
}

void
deque_push_back(deque_type *d, deque_val_type v)
{
	struct node_struct *n = malloc(sizeof(struct node_struct));
	assert(n != NULL);
	n->val = v;
	n->prev = d->tail;
	n->next = NULL;

	if (d->head == NULL)
		d->head = d->tail = n;

	else {
		d->tail->next = n;
		d->tail = n;
	}
}

deque_val_type
deque_pop_front(deque_type *d)
{
	deque_val_type v = d->head->val;
	struct node_struct *n = d->head;

	if (d->head == d->tail)
		d->head = d->tail = NULL;
	else
		d->head = n->next;

	free(n);
	return v;
}

deque_val_type
deque_pop_back(deque_type *d)
{
	deque_val_type v = d->tail->val;
	struct node_struct *n = d->tail;

	if (d->head == d->tail)
		d->head = d->tail = NULL;
	else
		d->tail = n->prev;

	free(n);
	return v;
}

deque_val_type
deque_peek_front(deque_type *d)
{
	return d->head->val;
}

deque_val_type
deque_peek_back(deque_type *d)
{
	return d->tail->val;
}
