#include "SList.h"

void STLListPushBack(NLTList** phead, type x)
{
	NLTList* newnode = (NLTList*)malloc(sizeof(NLTList));
	newnode->data = x;
	newnode->next = NULL;

	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		NLTList* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void STLListPushFront(NLTList** phead, type x)
{
	NLTList* newnode = (NLTList*)malloc(sizeof(NLTList));
	newnode->data = x;
	newnode->next = NULL;

	newnode->next = *phead;
	*phead = newnode;
}

void STLListPopFront(NLTList** phead)
{
	if (*phead == NULL)
	{
		return;
	}
	NLTList* next = (*phead)->next;
	free(*phead);
	*phead = next;
}

void STLListPopBack(NLTList** phead)
{
	NLTList* prev = NULL;
	NLTList* tail = *phead;
	if (*phead == NULL)
		return;
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}

type STLListFind(NLTList* phead, type x)
{
	NLTList* temp = phead;
	while (temp->next != NULL)
	{
		if (temp->data == x)
		{
			return x;
		}
		temp = temp->next;
	}
	return -1;
}

void STLListPrint(NLTList* phead)
{
	NLTList* tail = phead;
	while (tail != NULL)
	{
		cout << tail->data << "->";
		tail = tail->next;
	}
	cout << "NULL" << endl;
}