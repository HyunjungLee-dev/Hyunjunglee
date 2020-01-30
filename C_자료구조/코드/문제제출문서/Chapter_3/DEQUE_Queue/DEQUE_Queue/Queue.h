#ifndef __QUEUE_H__
#define __QUEUE_H__
#include"Deque.h"

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef Deque Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif