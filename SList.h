#pragma once

#include <cstdlib>
#include <iostream>
using namespace std;

#define type int

struct NLTList
{
	type data;
	NLTList* next;
};

void STLListPushBack(NLTList** phead, type x);
void STLListPushFront(NLTList** phead, type x);

void STLListPopFront(NLTList** phead);
void STLListPopBack(NLTList** phead);

type STLListFind(NLTList* phead, type x);
void STLListPrint(NLTList* phead);