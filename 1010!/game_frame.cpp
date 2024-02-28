#include "stdafx.h"
#include "game_frame.h"


game_frame::game_frame()
{
}


game_frame::~game_frame()
{
}

void game_frame::game_board(CPaintDC* dc)
{
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			dc->Rectangle((x + 1)*width + 15, (y + 1)*width + 15, (x + 2)*width + 16, (y + 2)*width + 16);
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 14; x < 19; x++) {
			dc->Rectangle((x + 1) * 15 + 300, (y + 1) * 15 + 25, (x + 2) * 15 + 301, (y + 2) * 15 + 26);
		}
	}
}

void game_frame::pre_figure(CPaintDC* dc, int num)
{
	if (num == 1) {
		CBrush my_brush(RGB(255, 0, 0));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(525, 70, 541, 86);
		dc->Rectangle(540, 70, 556, 86);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(585, 70, 601, 86);
	}
	else if (num == 2) {
		CBrush my_brush(RGB(0, 255, 0));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(540, 85, 556, 101);
	}
	else if (num == 3) {
		CBrush my_brush(RGB(0, 0, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(570, 85, 586, 101);

	}
	else if (num == 4) {
		CBrush my_brush(RGB(0, 255, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(555, 55, 571, 71);
	}
	CBrush my_brush(RGB(255, 255, 0));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	dc->Ellipse(557, 72, 569, 84);
}

void game_frame::turn_figrue(CClientDC* dc, int num, int shift)
{
	for (int y = 0; y < 5; y++) {
		for (int x = 14; x < 19; x++) {
			CBrush my_brush(RGB(255, 255, 255));
			CBrush *p_old_brush = dc->SelectObject(&my_brush);
			dc->Rectangle((x + 1) * 15 + 300, (y + 1) * 15 + 25, (x + 2) * 15 + 301, (y + 2) * 15 + 26);
		}
	}
	if (num == 1) {
		CBrush my_brush(RGB(255, 0, 0));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		if (shift % 2 == 0) {
			dc->Rectangle(525, 70, 541, 86);
			dc->Rectangle(540, 70, 556, 86);
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(570, 70, 586, 86);
			dc->Rectangle(585, 70, 601, 86);
		}
		else {
			dc->Rectangle(555, 40, 571, 56);
			dc->Rectangle(555, 55, 571, 71);
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(555, 85, 571, 101);
			dc->Rectangle(555, 100, 571, 116);
		}

	}
	else if (num == 2) {
		CBrush my_brush(RGB(0, 255, 0));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		if (shift % 2 == 0) {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(570, 70, 586, 86);
			dc->Rectangle(555, 85, 571, 101);
			dc->Rectangle(540, 85, 556, 101);
		}
		else {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(570, 70, 586, 86);
			dc->Rectangle(555, 55, 571, 71);
			dc->Rectangle(570, 85, 586, 101);
		}
	}
	else if (num == 3) {
		CBrush my_brush(RGB(0, 0, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(570, 85, 586, 101);
	}
	else if (num == 4) {
		CBrush my_brush(RGB(0, 255, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		if (shift % 4 == 0) {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(555, 55, 571, 71);
			dc->Rectangle(555, 85, 571, 101);
			dc->Rectangle(570, 70, 586, 86);
		}
		else if (shift % 4 == 1) {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(570, 70, 586, 86);
			dc->Rectangle(540, 70, 556, 86);
			dc->Rectangle(555, 55, 571, 71);
		}
		else if (shift % 4 == 2) {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(555, 85, 571, 101);
			dc->Rectangle(540, 70, 556, 86);
			dc->Rectangle(555, 55, 571, 71);
		}
		else if (shift % 4 == 3) {
			dc->Rectangle(555, 70, 571, 86);
			dc->Rectangle(555, 85, 571, 101);
			dc->Rectangle(540, 70, 556, 86);
			dc->Rectangle(570, 70, 586, 86);
		}
	}
	CBrush my_brush(RGB(255, 255, 0));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	dc->Ellipse(557, 72, 569, 84);
}
