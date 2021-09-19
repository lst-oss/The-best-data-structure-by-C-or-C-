#include "Slist.h"

List* creat_space(ctype x)
{
	List* newnode = (List*)malloc(sizeof(List));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = x;

	return newnode;
}

List* ListInit()
{
	List* phead = creat_space(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListPushback(List* phead, ctype x)
{
	List* newnode = creat_space(x);
	List* prev = phead->prev;

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPushfront(List*phead, ctype x)
{
	List* newnode = creat_space(x);
	List* next = phead->next;

	next->prev = newnode;
	newnode->next = next;
	newnode->prev = phead;
	phead->next = newnode;
}

void ListPopback(List* phead)
{
	List* tail = phead->prev;
	List* prev_tail = tail->prev;
	phead->prev = prev_tail;
	prev_tail->next = phead;

	free(tail);
}

void ListPopfront(List* phead)
{
	List* fir = phead->next;
	List* sec = fir->next;
	phead->next = sec;
	sec->prev = phead;
	free(fir);
}

void ListErase(List* pos)
{
	List* prev = pos->prev;
	List* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
}

List* Listfind(List* phead, ctype x)
{
	List* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
			cur = cur->next;
	}
	return NULL;
}

void ListPrint(List* phead)
{
	List* cur = phead->next;
	while (cur != phead)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

int ListSize(List* phead)
{
	int res = 0;
	List* cur = phead;
	while (cur->next != phead)
	{
		cur = cur->next;
		res++;
	}

	return res;
}