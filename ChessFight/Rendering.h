#pragma once

class Pieces;
class Buttons;
class Rendering
{
public:

	static Rendering* GetInst() {
		static Rendering instance;
		return &instance;
	}

	void RenderStartScreen();
	void RenderEndScreen();
	void RenderOverScreen();
	void EraseAll();
	void RenderBoard( Pieces* board[][BXSIZE], const Pieces& curSel);
	void RenderPreview(vector<POS> pres);
	void RenderPreviewDetail(POS sel);
	void RenderButton(vector<Buttons*> buttons);

	void RenderBossHpBar(int amt);

	int GetEndFlag() { return end; }
	void SetEndFlag(int val) { end = val; }

private:
	Rendering();
	~Rendering();

	int end;
};

