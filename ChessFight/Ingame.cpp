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

	Rendering::GetInst()->RenderBoard(b.GetBoardInfo(), b.GetCurSelPieceAt());
	Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
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
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
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

					b.SetDetail(b.PredMove(b.GetCurSelPieceAt()));
					b.ResetDetail();
					Rendering::GetInst()->RenderPreview(b.PredMove(b.GetCurSelPieceAt()));
					Rendering::GetInst()->RenderPreviewDetail(b.GetCurSelDetail());
				}
			}
			else {
				prevSpace = false;
			}
		}
	}
}
