#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(const char * str1, const char * str2)
{
	return strlen(str2) - strlen(str1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Follow me");
	PEnqueue(&pq, "I think so");
	PEnqueue(&pq, "feel too sleepy");
	PEnqueue(&pq, "I don't feel like it");
	PEnqueue(&pq, "Excuse me");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
