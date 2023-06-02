#pragma once
#include "Defines.h"

class Stage;
class MapManager
{
private:
	MapManager();
	~MapManager();

	static MapManager* instance;

	Stage* stages[3];

	int curStage;
public:

	static MapManager* GetInst() {
		if (instance == nullptr)
			instance = new MapManager;
		return instance;
	}

	void DestroyInst() {
		SAFEDELPTR(instance);
	}

	bool Init();
	void Run(int stNum);

	Stage* GetCurStage() { return stages[curStage]; }
	int GetStageNum() { return curStage; }
};

