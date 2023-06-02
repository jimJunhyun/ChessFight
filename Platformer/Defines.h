#pragma once
#include <Windows.h>

#define SAFEDELPTR(p)	if(p){ delete p; p = nullptr;}

const int MAPX = 50;
const int MAPY = 10;

enum class StageData {
	WALL = '0',
	ROAD,
	START,
	END,
	COIN,
};