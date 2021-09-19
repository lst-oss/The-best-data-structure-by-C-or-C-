#include "Queue.h"

void QueueInit(Queue* p)
{
	p->head = p->tail = NULL;
}

void QueuePush(Queue* p, Qdata x)
{
	assert(p);

	ListQueue* newnode = (ListQueue*)malloc(sizeof(ListQueue));
	newnode->data = x;
	newnode->next = NULL;

	if (!p->head)
	{
		p->head = p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		// p->tail = p->tail->next;
		p->tail = newnode;
	}
}

void QueuePop(Queue* p)
{
	assert(p);
	assert(p->head);
	if (p->head->next == NULL)
	{
		p->head = p->tail = NULL;
	}
	else
	{
		ListQueue* next = p->head->next;
		free(p->head);
		p->head = next;
	}
}

bool QueueEmpty(Queue* p)
{
	assert(p);
	return p->tail == NULL;
}

void QueueDestroy(Queue* p)
{
	assert(p);
	while (p->tail)
	{
		ListQueue* temp = p->head->next;
		free(p->head);
		p->head = temp;
	}
	p->head = p->tail = NULL;
}

int QueueSize(Queue* p)
{
	int num = 0;
	ListQueue* cur = p->head;
	while (cur)
	{
		++num;
		cur = cur->next;
	}
	return num;
}

Qdata QueueFront(Queue* p)
{
	assert(p);
	assert(p->head);
	return p->head->data;
}

Qdata QueueLast(Queue* p)
{
	assert(p);
	assert(p->tail);
	return p->tail->data;
}