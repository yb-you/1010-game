#pragma once
#include "1010!Dlg.h"
class game_frame :
	public CMy1010Dlg
{
	int width = 30;
public:
	game_frame();
	~game_frame();
	void game_board(CPaintDC* dc);
	void pre_figure(CPaintDC* dc, int num);
	void turn_figrue(CClientDC* dc, int num, int shift);
};

