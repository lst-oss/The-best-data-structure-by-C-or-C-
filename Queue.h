#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
using namespace std;

#define Qdata int

struct ListQueue{
	ListQueue* next;
	Qdata data;
};

struct Queue{
	ListQueue* head;
	ListQueue* tail;
};

void QueueInit(Queue* p);
void QueuePush(Queue* p, Qdata x);
void QueuePop(Queue* p);
bool QueueEmpty(Queue* p);
void QueueDestroy(Queue* p);
int QueueSize(Queue* p);
Qdata QueueFront(Queue* p);
Qdata QueueLast(Queue* p);