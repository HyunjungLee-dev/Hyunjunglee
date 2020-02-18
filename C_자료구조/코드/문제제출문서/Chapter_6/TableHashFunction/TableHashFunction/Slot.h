#ifndef __SLOT_H__
#define __SLOT_H__

#include "Animal.h"

typedef int		Key;	
typedef Animal* Value;	

//�����Ͱ� ��������� ������, ���� ����� ��������, ��ȿ�� �����Ͱ� ����Ǿ��ִ���.
enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot
{
	Key				key;
	Value			val;
	enum SlotStatus status; // ������ ���¸� ��Ÿ����.
} Slot;

#endif
