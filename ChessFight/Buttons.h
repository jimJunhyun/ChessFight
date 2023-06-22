#pragma once

class Board;
class Buttons
{
public:
	Buttons(Board* board, const POS& pos, BUTTONTYPE type, int dam = 10);
	~Buttons();


	bool CheckPieceOn();


	const POS& GetPosition() { return p; }
	wchar_t GetIcon() { return icon; }
private:
	Board* b;
	POS p;
	wchar_t icon;

	function<void (void)> onPressed;
	
};

