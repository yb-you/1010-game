#pragma once
#include "1010!Dlg.h"
class game_player :
	public CMy1010Dlg
{	
	int score;
	int block[10][10];
	int center_x;
	int center_y;
	int center_xnum;
	int center_ynum;
	int width = 30;
public:
	static bool reset;

	game_player();
	~game_player();

	int get_score();
	void add_score(int score);
	void set_score(int score);

	void set_senter(int center_x, int center_y, int center_xnum, int center_ynum);

	bool check_block1_region(int shift);
	bool check_block1_available(int shift);
	void put_block1(CClientDC* dc, int shift);

	bool check_block2_region(int shift);
	bool check_block2_available(int shift);
	void put_block2(CClientDC* dc, int shift);

	bool check_block3_region();
	bool check_block3_available();
	void put_block3(CClientDC* dc);

	bool check_block4_region(int shift);
	bool check_block4_available(int shift);
	void put_block4(CClientDC* dc, int shift);

	void clear(CClientDC* dc);
	bool check_gamemode(CClientDC* dc,int num);
	void player_reset(CClientDC* dc);

};