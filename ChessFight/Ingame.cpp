#include "pch.h"
#include "Rendering.h"
#include "Ingame.h"
#include "Board.h"

void Starter()
{

	Rendering::GetInst()->RenderStartScreen();
	while (!_kbhit());
	_getch();
	Rendering::GetInst()->EraseAll();
	Board b;
	b.InitSide(true);
	b.InitSide(false);
	Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
	Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
	
	bool prevLeft = false;
	bool prevRight = false;
	bool prevSpace = false;

	bool selectionMode = false;

	bool turn = true;
	int curnCnt = 0;

	Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
	Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
	Rendering::GetInst()->RenderBossHpBar(BOSSHP);
	while (true)
	{
		if (selectionMode) {
			if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {
				if (!prevLeft) {
					prevLeft = true;
					b.SelectPrevDetail();
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
					Rendering::GetInst()->RenderPreviewDetail(b.GetCurSelDetail());
				}

			}
			else {
				prevLeft = false;
			}
			if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
				if (!prevRight) {
					prevRight = true;
					b.SelectNextDetail();
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
					Rendering::GetInst()->RenderPreviewDetail(b.GetCurSelDetail());
				}
			}
			else {
				prevRight = false;
			}
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) {
				if (!prevSpace) {
					prevSpace = true;
					vector<POS> predPos = b.PredMove(b.GetCurSelPieceAt());
					Rendering::GetInst()->RenderPreview(predPos);
					Rendering::GetInst()->RenderPreviewDetail(b.GetCurSelDetail());
					b.Move((b.GetCurSelPieceAt()), b.GetCurSelDetail());
					selectionMode = false;
					Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
					b.ResetDetail();
				}
			}
			else {
				prevSpace = false;
			}
		}
		else {
			if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {
				if (!prevLeft) {
					prevLeft = true;
					b.SelectPrev();
					Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
				}

			}
			else {
				prevLeft = false;
			}
			if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
				if (!prevRight) {
					prevRight = true;
					b.SelectNext();
					Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
				}
			}
			else {
				prevRight = false;
			}
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) {
				if (!prevSpace) {
					prevSpace = true;
					selectionMode = true;
					Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
					vector<POS> predMoves = b.PredMove(b.GetCurSelPieceAt());
					if (predMoves.size() > 0) {
						b.SetDetail(predMoves);
						b.ResetDetail();
						Rendering::GetInst()->RenderPreview(predMoves);
						Rendering::GetInst()->RenderPreviewDetail(b.GetCurSelDetail());
					}
					else
						selectionMode = false;
				}
			}
			else {
				prevSpace = false;
			}
		}
	}
}
