#include "Core.h"
#include <iostream>
#include "MapManager.h"

using namespace std;

Core* Core::instance = nullptr;

Core::Core()
{
}

Core::~Core()
{
	
}

bool Core::Init()
{
	
	if (!(MapManager::GetInst()->Init())) {
		return false;
	}
	return true;
}

void Core::Run()
{
	int curStage = MenuRender();
	MapManager::GetInst()->Run(curStage - 1);
}

int Core::MenuRender()
{
	cout << "�������� ���� (4�� ������) : \n";
	int inp;
	cin >> inp;
	system("cls");
	return inp;
}
