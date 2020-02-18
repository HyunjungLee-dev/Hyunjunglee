#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#define STR_LEN 50

typedef struct _animal
{
	int		ssn;
	char	name[STR_LEN];
	char breed[STR_LEN];
} Animal;

int GetSSN(Animal* p);
void ShowAniInfo(Animal* p);
Animal* MakeAnimalData(int ssn, const char* name, const char* breed);

#endif
