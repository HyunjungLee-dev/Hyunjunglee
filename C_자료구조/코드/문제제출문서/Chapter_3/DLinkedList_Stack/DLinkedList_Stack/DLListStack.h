#ifndef   __DLLIST_STACK_H__
#define __DLLIST_STACK_H__
#include"DLinkedList.h"

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _listStack
{
	List * plist;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif