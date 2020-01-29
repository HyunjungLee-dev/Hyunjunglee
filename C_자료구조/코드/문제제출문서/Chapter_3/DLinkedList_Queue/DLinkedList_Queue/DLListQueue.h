#ifndef __DLLIST_QUEUE_H__
#define __DLLIST_QUEUE_H__

#define TRUE	1
#define FALSE	0
#include"DLinkedList.h"

typedef int Data;

typedef List Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif