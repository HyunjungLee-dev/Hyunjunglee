#include<stdio.h>
#include"BinarySearchTree.h"

int main()
{
	BTreeNode * bstRoot;
	BTreeNode * searchNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 10);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 1);

	searchNode = BSTSearch(bstRoot, 4);
	if (searchNode == NULL)
		printf("실패\n");
	else
		printf("성공 키 값 : %d \n", BSTGetNodeData(searchNode));

	searchNode = BSTSearch(bstRoot, 2);
	if (searchNode == NULL)
		printf("실패\n");
	else
		printf("성공 키 값 : %d \n", BSTGetNodeData(searchNode));


	searchNode = BSTSearch(bstRoot, 10);
	if (searchNode == NULL)
		printf("실패\n");
	else
		printf("성공 키 값 : %d \n", BSTGetNodeData(searchNode));

	return 0;
}