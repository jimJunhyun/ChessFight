#pragma once
#include "Defines.h"




class Core
{
private:
	Core();
	~Core();

	static Core* instance;
public:

	static Core* GetInstance() {
		if(instance == nullptr)
			instance = new Core;
		return instance;
	}

	static void DeleteInst() {
		SAFEDELPTR(instance);
	}

	bool Init();
	void Run();
	int MenuRender();
};

