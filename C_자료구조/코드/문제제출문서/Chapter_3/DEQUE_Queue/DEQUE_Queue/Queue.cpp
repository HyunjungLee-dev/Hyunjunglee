#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void QueueInit(Queue * pq)
{
	DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
	return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
	DQAddFirst(pq, data);
}

Data Dequeue(Queue * pq)
{
	Data data;
	data = DQGetLast(pq);
	DQRemoveLast(pq);
	return data;
}

Data QPeek(Queue * pq)
{
	Data data;
	data = DQGetLast(pq);
	return data;
}