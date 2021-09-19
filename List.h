#pragma once

#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ctype int

typedef struct List
{
	List* prev;
	List* next;
	ctype data;
}List;

List* creat_space(ctype x);
List* ListInit();
void ListPushback(List* phead, ctype x);
void ListPushfront(List*phead, ctype x);
void ListPopback(List* phead);
void ListPopfront(List* phead);
void ListErase(List* pos);
List* Listfind(List* phead, ctype x);
void ListPrint(List* phead);
int ListSize(List* phead);