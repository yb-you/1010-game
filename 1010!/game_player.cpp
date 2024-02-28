#include "stdafx.h"
#include "game_player.h"


game_player::game_player()
{
}

game_player::~game_player()
{
}

int game_player::get_score()
{
	return this->score;
}

void game_player::add_score(int score)
{
	this->score = this->score + score;
}

void game_player::set_score(int score)
{
	this->score = score;
}

void game_player::set_senter(int center_x, int center_y, int center_xnum, int center_ynum)
{
	this->center_x = center_x, this->center_y = center_y, this->center_xnum = center_xnum, this->center_ynum = center_ynum;
}

bool game_player::check_block1_region(int shift)
{
	if (shift==0) {
		if (((center_xnum - 1) != -1) && ((center_xnum - 2) != -1) && ((center_xnum + 1) != 10) && ((center_xnum + 2) != 10)) return true;
		else return false;
	}
	else {
		if (((center_ynum - 1) != -1) && ((center_ynum - 2) != -1) && ((center_ynum + 1) != 10) && ((center_ynum + 2) != 10)) return true;
		else return false;
	}
}

bool game_player::check_block1_available(int shift)
{
	if (shift==0) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                          //일자블럭영역안 다른 블럭
			(block[center_xnum - 1][center_ynum]) != 1 &&
			(block[center_xnum - 2][center_ynum]) != 1 &&
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum + 2][center_ynum]) != 1)
			return true;
		else return false;
	}
	else {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                          //sift_일자블럭영역안 다른 블럭
			(block[center_xnum][center_ynum - 1]) != 1 &&
			(block[center_xnum][center_ynum - 2]) != 1 &&
			(block[center_xnum][center_ynum + 1]) != 1 &&
			(block[center_xnum][center_ynum + 2]) != 1)
			return true;
		else return false;
	}
}

void game_player::put_block1(CClientDC * dc, int shift)
{
	CBrush my_brush(RGB(255, 0, 0));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	if (shift==0) {
		dc->Rectangle(center_x - 75, center_y - 15, center_x - 44, center_y + 16);
		dc->Rectangle(center_x - 45, center_y - 15, center_x - 14, center_y + 16);
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x + 45, center_y - 15, center_x + 76, center_y + 16);

		block[center_xnum][center_ynum] = 1;
		block[center_xnum - 1][center_ynum] = 1;
		block[center_xnum - 2][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum + 2][center_ynum] = 1;
	}
	else {
		dc->Rectangle(center_x - 15, center_y - 75, center_x + 16, center_y - 44);
		dc->Rectangle(center_x - 15, center_y - 45, center_x + 16, center_y - 14);
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 45);
		dc->Rectangle(center_x - 15, center_y + 45, center_x + 16, center_y + 76);

		block[center_xnum][center_ynum] = 1;
		block[center_xnum][center_ynum - 1] = 1;
		block[center_xnum][center_ynum - 2] = 1;
		block[center_xnum][center_ynum + 1] = 1;
		block[center_xnum][center_ynum + 2] = 1;
	}

}
bool game_player::check_block2_region(int shift)
{
	if (shift == 0) {
		if (((center_xnum + 1) != 10) && ((center_ynum + 1) != 10) && (center_xnum - 1) != -1) return true;
		else return false;
	}
	else {
		if (((center_ynum - 1) != -1) && ((center_xnum + 1) != 10) && (center_ynum + 1) != 10) return true;
		else return false;
	}
}

bool game_player::check_block2_available(int shift)
{
	if (shift == 0) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //이상한블럭영역안 다른 블럭
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum][center_ynum + 1]) != 1 &&
			(block[center_xnum - 1][center_ynum + 1]) != 1)
			return true;
		else return false;
	}
	else {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //sift_이상한블럭영역안 다른 블럭
			(block[center_xnum][center_ynum - 1]) != 1 &&
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum + 1][center_ynum + 1]) != 1)
			return true;
		else return false;
	}
}

void game_player::put_block2(CClientDC * dc, int shift)
{
	CBrush my_brush(RGB(0, 255, 0));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	if (shift == 0) {

		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 46);
		dc->Rectangle(center_x - 45, center_y + 15, center_x - 14, center_y + 46);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum][center_ynum + 1] = 1;
		block[center_xnum - 1][center_ynum + 1] = 1;
	}
	else {
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x - 15, center_y - 45, center_x + 16, center_y - 14);
		dc->Rectangle(center_x + 15, center_y + 15, center_x + 46, center_y + 46);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum][center_ynum - 1] = 1;
		block[center_xnum + 1][center_ynum + 1] = 1;
	}

}
bool game_player::check_block3_region()
{
	if (((center_xnum + 1) != 10) && ((center_ynum + 1) != 10)) return true;
	else return false;
}

bool game_player::check_block3_available()
{

	if ((block[center_xnum][center_ynum]) != 1 &&                                                                           //사각블럭영역안 다른 블럭
		(block[center_xnum + 1][center_ynum]) != 1 &&
		(block[center_xnum][center_ynum + 1]) != 1 &&
		(block[center_xnum + 1][center_ynum + 1]) != 1)
		return true;
	else return false;

}

void game_player::put_block3(CClientDC * dc)
{
	CBrush my_brush(RGB(0, 0, 255));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
	dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
	dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 46);
	dc->Rectangle(center_x + 15, center_y + 15, center_x + 46, center_y + 46);
	block[center_xnum][center_ynum] = 1;
	block[center_xnum + 1][center_ynum] = 1;
	block[center_xnum][center_ynum + 1] = 1;
	block[center_xnum + 1][center_ynum + 1] = 1;


}
bool game_player::check_block4_region(int shift)
{
	if (shift == 0) {
		if (((center_xnum + 1) != 10) && ((center_ynum + 1) != 10) && (center_ynum - 1) != -1) return true;
		else return false;
	}
	else if (shift==1){
		if (((center_xnum + 1) != 10) && ((center_xnum - 1) != -1) && (center_ynum - 1) != -1) return true;
		else return false;
	}
	else if (shift == 2) {
		if (((center_xnum - 1) != -1) && ((center_ynum - 1) != -1) && (center_ynum + 1) != 10) return true;
		else return false;
	}
	else if (shift == 3) {
		if (((center_xnum - 1) != -1) && ((center_xnum + 1) != 10) && (center_ynum + 1) != 10) return true;
		else return false;
	}
}

bool game_player::check_block4_available(int shift)
{
	if (shift == 0) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //ㅏ블럭영역안 다른 블럭
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum][center_ynum + 1]) != 1 &&
			(block[center_xnum][center_ynum - 1]) != 1)
			return true;
		else return false;
	}
	else if (shift == 1) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //이상한블럭영역안 다른 블럭
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum - 1][center_ynum]) != 1 &&
			(block[center_xnum][center_ynum - 1]) != 1)
			return true;
		else return false;
	}
	else if (shift == 2) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //이상한블럭영역안 다른 블럭
			(block[center_xnum - 1][center_ynum]) != 1 &&
			(block[center_xnum][center_ynum - 1]) != 1 &&
			(block[center_xnum][center_ynum + 1]) != 1)
			return true;
		else return false;
	}
	else if (shift == 3) {
		if ((block[center_xnum][center_ynum]) != 1 &&                                                                         //이상한블럭영역안 다른 블럭
			(block[center_xnum - 1][center_ynum]) != 1 &&
			(block[center_xnum + 1][center_ynum]) != 1 &&
			(block[center_xnum][center_ynum + 1]) != 1)
			return true;
		else return false;
	}
}

void game_player::put_block4(CClientDC * dc, int shift)
{
	CBrush my_brush(RGB(0, 255, 255));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	if (shift == 0) {
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 46);
		dc->Rectangle(center_x - 15, center_y - 45, center_x + 16, center_y - 14);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum][center_ynum + 1] = 1;
		block[center_xnum][center_ynum - 1] = 1;
	}
	else if (shift == 1) {
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x - 45, center_y - 15, center_x - 14, center_y + 16);
		dc->Rectangle(center_x - 15, center_y - 45, center_x + 16, center_y - 14);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum - 1][center_ynum] = 1;
		block[center_xnum][center_ynum - 1] = 1;
	}
	else if (shift == 2) {
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x - 45, center_y - 15, center_x - 14, center_y + 16);
		dc->Rectangle(center_x - 15, center_y - 45, center_x + 16, center_y - 14);
		dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 46);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum - 1][center_ynum] = 1;
		block[center_xnum][center_ynum - 1] = 1;
		block[center_xnum][center_ynum + 1] = 1;
	}
	else if (shift == 3) {
		dc->Rectangle(center_x - 15, center_y - 15, center_x + 16, center_y + 16);
		dc->Rectangle(center_x - 45, center_y - 15, center_x - 14, center_y + 16);
		dc->Rectangle(center_x + 15, center_y - 15, center_x + 46, center_y + 16);
		dc->Rectangle(center_x - 15, center_y + 15, center_x + 16, center_y + 46);
		block[center_xnum][center_ynum] = 1;
		block[center_xnum - 1][center_ynum] = 1;
		block[center_xnum + 1][center_ynum] = 1;
		block[center_xnum][center_ynum + 1] = 1;
	}

}

void game_player::clear(CClientDC * dc)
{
	bool clear_row = false;
	bool clear_column = false;
	int clear_row_num[10] = { -1 };
	int clear_column_num[10] = { -1 };
	int clear_num = 0;
	for (int clear = 0; clear < 10; clear++) {                                 //삭제확인
		if (block[0][clear] == 1 && block[1][clear] == 1 && block[2][clear] == 1 && block[3][clear] == 1 && block[4][clear] == 1 && block[5][clear] == 1 && block[6][clear] == 1 && block[7][clear] == 1 && block[8][clear] == 1 && block[9][clear] == 1) {
			//MessageBox(_T("가로삭제"), _T("오류"), MB_ICONERROR);
			clear_num++;
			clear_row = true;
			clear_row_num[clear] = clear;
		}
		if (block[clear][0] == 1 && block[clear][1] == 1 && block[clear][2] == 1 && block[clear][3] == 1 && block[clear][4] == 1 && block[clear][5] == 1 && block[clear][6] == 1 && block[clear][7] == 1 && block[clear][8] == 1 && block[clear][9] == 1) {
			//MessageBox(_T("세로삭제"), _T("오류"), MB_ICONERROR);
			clear_num++;
			clear_column = true;
			clear_column_num[clear] = clear;
		}
	}

	//score = score + 5;
	if (clear_num > 0)
		score = score + (100 * clear_num);
	for (int n = 1; n < clear_num; n++)
		score = score + (50 * n);
	//SetDlgItemInt(IDC_EDIT1, this->score);                                          //점수출력

	if (clear_row == true) {                                                   //가로삭제시
		CBrush my_brush(RGB(255, 255, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		for (int index = 0; index < 10; index++) {
			if (clear_row_num[index] == index) {
				for (int n = 0; n < 10; n++) {
					dc->Rectangle((n + 1)*width + 15, (clear_row_num[index] + 1)*width + 15, (n + 2)*width + 16, (clear_row_num[index] + 2)*width + 16);
					block[n][clear_row_num[index]] = 0;
				}
			}
		}
		clear_row = false;
	}
	if (clear_column == true) {                                                 //세로삭제시
		CBrush my_brush(RGB(255, 255, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		for (int index = 0; index < 10; index++) {
			if (clear_column_num[index] == index) {
				for (int n = 0; n < 10; n++) {
					dc->Rectangle((clear_column_num[index] + 1)*width + 15, (n + 1)*width + 15, (clear_column_num[index] + 2)*width + 16, (n + 2)*width + 16);
					block[clear_column_num[index]][n] = 0;
				}
			}
		}
		clear_column = false;
	}
}

bool game_player::check_gamemode(CClientDC* dc, int num)
{
	bool gamemode = true;
	bool exitloop = false;

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
		dc->Rectangle(525, 70, 541, 86);
		dc->Rectangle(540, 70, 556, 86);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(585, 70, 601, 86);
		for (int y = 0; y < 10; y++) {
			for (int x = 2; x < 8; x++) {
				if (block[x][y] == 0) {
					if (block[x - 2][y] == 0 && block[x - 1][y] == 0 && block[x + 1][y] == 0 && block[x + 2][y] == 0)
					{
						gamemode = true;
						exitloop = true;
						break;
					}
					else {
						gamemode = false;
						exitloop = false;
					}
				}
			}
			if (exitloop == true)
				break;
		}
		if (gamemode == false) {
			for (int y = 2; y < 8; y++) {
				for (int x = 0; x < 10; x++) {
					if (block[x][y] == 0) {
						if (block[x][y - 2] == 0 && block[x][y - 1] == 0 && block[x][y + 1] == 0 && block[x][y + 2] == 0)
						{
							gamemode = true;
							exitloop = true;
							break;
						}
						else {
							gamemode = false;
							exitloop = false;
						}
					}
				}
				if (exitloop == true)
					break;
			}
		}
	}
	else if (num == 2) {
		CBrush my_brush(RGB(0, 255, 0));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(540, 85, 556, 101);
		for (int y = 0; y < 9; y++) {
			for (int x = 1; x < 9; x++) {
				if (block[x][y] == 0) {
					if (block[x + 1][y] == 0 && block[x][y + 1] == 0 && block[x - 1][y + 1] == 0) {
						gamemode = true;
						exitloop = true;
						break;
					}
					else {
						exitloop = false;
						gamemode = false;
					}
				}

			}
			if (exitloop == true)
				break;
		}
		if (gamemode == false) {
			for (int y = 1; y < 9; y++) {
				for (int x = 0; x < 9; x++) {
					if (block[x][y] == 0) {
						if (block[x][y - 1] == 0 && block[x + 1][y] == 0 && block[x + 1][y + 1] == 0) {
							gamemode = true;
							exitloop = true;
							break;
						}
						else {
							exitloop = false;
							gamemode = false;
						}
					}

				}
				if (exitloop == true)
					break;
			}
		}
	}
	else if (num == 3) {
		CBrush my_brush(RGB(0, 0, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(570, 85, 586, 101);
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				if (block[x][y] == 0) {
					if (block[x + 1][y] == 0 && block[x][y + 1] == 0 && block[x + 1][y + 1] == 0) {
						gamemode = true;
						exitloop = true;
						break;
					}
					else {
						exitloop = false;
						gamemode = false;
					}
				}
			}
			if (exitloop == true)
				break;
		}
	}
	else if (num == 4) {
		CBrush my_brush(RGB(0, 255, 255));
		CBrush *p_old_brush = dc->SelectObject(&my_brush);
		dc->Rectangle(555, 70, 571, 86);
		dc->Rectangle(570, 70, 586, 86);
		dc->Rectangle(555, 85, 571, 101);
		dc->Rectangle(555, 55, 571, 71);
		for (int y = 1; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				if (block[x][y] == 0) {
					if (block[x + 1][y] == 0 && block[x][y + 1] == 0 && block[x][y - 1] == 0) {
						gamemode = true;
						exitloop = true;
						break;
					}
					else {
						exitloop = false;
						gamemode = false;
					}
				}

			}
			if (exitloop == true)
				break;
		}
		if (gamemode == false) {
			for (int y = 1; y < 10; y++) {
				for (int x = 1; x < 9; x++) {
					if (block[x][y] == 0) {
						if (block[x + 1][y] == 0 && block[x - 1][y] == 0 && block[x][y - 1] == 0) {
							gamemode = true;
							exitloop = true;
							break;
						}
						else {
							exitloop = false;
							gamemode = false;
						}
					}

				}
				if (exitloop == true)
					break;
			}
		}
		if (gamemode == false) {
			for (int y = 1; y < 9; y++) {
				for (int x = 1; x < 10; x++) {
					if (block[x][y] == 0) {
						if (block[x - 1][y] == 0 && block[x][y - 1] == 0 && block[x][y + 1] == 0) {
							gamemode = true;
							exitloop = true;
							break;
						}
						else {
							exitloop = false;
							gamemode = false;
						}
					}

				}
				if (exitloop == true)
					break;
			}
		}
		if (gamemode == false) {
			for (int y = 0; y < 9; y++) {
				for (int x = 1; x < 9; x++) {
					if (block[x][y] == 0) {
						if (block[x - 1][y] == 0 && block[x + 1][y] == 0 && block[x][y + 1] == 0) {
							gamemode = true;
							exitloop = true;
							break;
						}
						else {
							exitloop = false;
							gamemode = false;
						}
					}

				}
				if (exitloop == true)
					break;
			}
		}
	}
	CBrush my_brush(RGB(255, 255, 0));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	dc->Ellipse(557, 72, 569, 84);
	return gamemode;
}

void game_player::player_reset(CClientDC * dc)
{
	score = 0;
	for (int n = 0; n < 10; n++)
		for (int m = 0; m < 10; m++)
			block[n][m] = 0;

	CBrush my_brush(RGB(255, 255, 255));
	CBrush *p_old_brush = dc->SelectObject(&my_brush);
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			dc->Rectangle((x + 1)*width + 15, (y + 1)*width + 15, (x + 2)*width + 16, (y + 2)*width + 16);
		}
	}
}