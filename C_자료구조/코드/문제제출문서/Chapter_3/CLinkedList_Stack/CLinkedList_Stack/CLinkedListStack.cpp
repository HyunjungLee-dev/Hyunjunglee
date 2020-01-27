#include <stdio.h>
#include <stdlib.h>
#include "CLinkedListStack.h"

void StackInit(Stack * pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist); 
}

int SIsEmpty(Stack * pstack)
{
	if (LCount(pstack->plist) == 0) // 스택이 비었으면 TRUE 
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	LInsertFront(pstack->plist, data); 
}

Data SPop(Stack * pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}

Data SPeek(Stack * pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}