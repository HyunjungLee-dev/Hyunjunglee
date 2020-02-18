#ifndef __SLOT_H__
#define __SLOT_H__

#include "Animal.h"

typedef int		Key;	
typedef Animal* Value;	

//데이터가 저장된적이 없는지, 현재 비워진 상태인지, 유효한 데이터가 저장되어있는지.
enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot
{
	Key				key;
	Value			val;
	enum SlotStatus status; // 슬롯의 상태를 나타낸다.
} Slot;

#endif
