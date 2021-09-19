#include "Stack.h"

void initstack(Stack* p)
{
	Sdata* temp = (Sdata*)malloc(4 * sizeof(Sdata));
	p->st = temp;
	p->capacity = 4;
	p->top = 0;
}

void stackPush(Stack* p, Sdata x)
{
	assert(p);

	if (p->top == p->capacity)
	{
		Sdata* temp = (Sdata*)realloc(p, sizeof(Sdata)* 2 * p->capacity);
		p->st = temp;
	}

	p->st[p->top] = x;
	p->top++;
}

void stackPop(Stack* p)
{
	assert(p);
	assert(p->top > 0);

	p->top--;
}

bool isempty(Stack* p)
{
	assert(p);
	return p->top == 0;
}

void stackdestroy(Stack* p)
{
	assert(p);
	free(p->st);
	p->st = NULL;
	p->capacity = p->top = 0;
}