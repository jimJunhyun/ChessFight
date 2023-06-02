#include "MapManager.h"
#include "Stage.h"
#include "console.h"

MapManager* MapManager::instance = nullptr;

MapManager::MapManager()
{
	for (int i = 0; i < 3; i++)
	{
		stages[i] = nullptr;
	}
}

MapManager::~MapManager()
{
	for (int i = 0; i < 3; i++)
	{
		SAFEDELPTR(stages[i]);
	}
}

bool MapManager::Init()
{
	char* fileNames[3] =
	{
		(char*)"Stage1.txt", 
		(char*)"Stage2.txt", 
		(char*)"Stage3.txt", 
	};
	for (int i = 0; i < 3; i++)
	{
		stages[i] = new Stage;
		if (!stages[i]->Init(fileNames[i])) {
			return false;
		}
	}
	return true;
}

void MapManager::Run(int stNum)
{
	curStage = stNum;
	HideCur(true, 10);
	while (true)
	{
		SetCurPos(0, 0);
		stages[curStage]->Render();
	}
}
