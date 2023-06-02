#pragma once

class Pieces;
class Rendering
{
public:

	static Rendering* GetInst() {
		static Rendering instance;
		return &instance;
	}

	void RenderStartScreen();
	void EraseAll();
	void RenderBoard(Pieces*  board[][BXSIZE]);

private:
	Rendering();
	~Rendering();

};

