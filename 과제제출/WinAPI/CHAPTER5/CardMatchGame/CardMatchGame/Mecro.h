#pragma once
#include<Windows.h>
#include<string>
#include <vector>
#include<cstdlib>
#include<time.h>
#include<iostream>
using namespace std;

#define CARD_MAX 20

enum IMG_TYP
{
	IMG_TYP_START,
	IMG_TYP_DOG = 0,
	IMG_TYP_TIGER,
	IMG_TYP_DUCK,
	IMG_TYP_ELEPHANT,
	IMG_TYP_COW,
	IMG_TYP_HORSE,
	IMG_TYP_CAT,
	IMG_TYP_MONKEY,
	IMG_TYP_FROG,
	IMG_TYP_CHICKEN,
	IMG_TYP_BLACK,
	IMG_TYP_CARDEND = 11,
	IMG_TYP_END
};

enum CARDSTATE
{
	CARDSTATE_OPEN,
	CARDSTATE_MATCH,
	CARDSTATE_CLOSE,
	CARDSTATE_END,

};


enum MATCH
{
	MATCH_FIRST = 0,
	MATCH_SECOND,
	MATCH_END,
	MATCH_ING

};
