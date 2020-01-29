#include <stdio.h>
#include <stdlib.h>
#include "DLListQueue.h"

void QueueInit(Queue * pq)
{
	ListInit(pq);
}

int QIsEmpty(Queue * pq)
{
	if (LCount(pq) == 0)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	LInsert(pq, data);
}

Data Dequeue(Queue * pq)
{
	Data data;
	LFirst(pq, &data);
	LRemove(pq);
	return data;
}

Data QPeek(Queue * pq)
{
	Data data;
	LFirst(pq, &data);
	return data;
}