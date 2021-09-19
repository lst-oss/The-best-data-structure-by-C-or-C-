#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
using namespace std;

#define Sdata int

struct STLStack{
	Sdata* st;
	int top;
	int capacity;
};

typedef struct STLStack Stack;

void initstack(Stack* p);
void stackPush(Stack* p, Sdata x);
void stackPop(Stack* p);
void stackdestroy(Stack* p);
bool isempty(Stack* p);

