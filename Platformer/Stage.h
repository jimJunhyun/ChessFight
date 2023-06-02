#pragma once
#include "Defines.h"

class Stage
{
public:
	Stage();
	~Stage();

	bool Init(const char* fileName);
	void Render();

	char GetStage(int x, int y) { return stage[y][ x]; }
	POINT GetStartP() { return startPos; }
	POINT GetEndP() { return endPos; }
private:
	char stage[MAPY][MAPX];
	POINT startPos;
	POINT endPos;
};

