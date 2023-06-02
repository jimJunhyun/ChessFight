#include "Stage.h"
#include <fstream>
#include <iostream>
using namespace std;

Stage::Stage() :startPos{}, endPos{}, stage{}
{
}

Stage::~Stage()
{
}

bool Stage::Init(const char* fileName)
{
	ifstream read;
	if (read.is_open()) {
		return false;
	}
	read.open(fileName);
	for (int i = 0; i < MAPY; i++)
	{
		read.clear();
		read.getline(stage[i], MAPX + 1);
		for (int j = 0; j < MAPX; j++)
		{
			if (stage[i][j] == (int)StageData::START) {
				startPos.x = j;
				startPos.y = i;
			}
			if (stage[i][j] == (int)StageData::END) {
				endPos.x = j;
				endPos.y = i;
			}
		}
	}

	return true;
}

void Stage::Render()
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (stage[i][j] == (int)StageData::WALL) {
				cout << "#";
			}
			if (stage[i][j] == (int)StageData::ROAD) {
				cout << " ";
			}
			if (stage[i][j] == (int)StageData::START) {
				cout << "¡Ú";
			}
			if (stage[i][j] == (int)StageData::END) {
				cout << "¡Ù";
			}
			if (stage[i][j] == (int)StageData::COIN) {
				cout << "¡Ý";
			}

		}
		cout << '\n';
	}
}
