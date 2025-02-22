
// 1010!Dlg.cpp: 구현 파일
//
//#include <atlstr.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <CString>
#include "stdafx.h"
#include "1010!.h"
#include "1010!Dlg.h"
#include "afxdialogex.h"

#include "game_frame.h"
#include "game_player.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <stdio.h>
#include <Windows.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm")

using namespace std;
int width = 30;
int num = (rand() % 4) + 1;
int score = 0;
int shift = 0;
int score_max = 0;
// CMy1010Dlg 대화 상자



CMy1010Dlg::CMy1010Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY1010_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1010Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, rank_score);
	DDX_Control(pDX, IDC_LIST2, rank_max);
}

BEGIN_MESSAGE_MAP(CMy1010Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1010Dlg::OnBnClickedButton1)
//	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy1010Dlg::OnBnClickedButton2)
	ON_COMMAND(ID_32773, &CMy1010Dlg::On32773)
END_MESSAGE_MAP()


// CMy1010Dlg 메시지 처리기

BOOL CMy1010Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy1010Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);                                                                 //시작시 칸 설정
		game_frame game_frame_;
		game_frame_.game_board(&dc);

		game_frame_.pre_figure(&dc, num);

		SetDlgItemInt(IDC_EDIT1, score);
	}

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy1010Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



bool block_true = true;
bool gamemode = true;
bool reset = false;

void CMy1010Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	static game_player player;
	if (reset) { player.player_reset(&dc); reset = false; }
	if (gamemode == true) {
		int center_x = ((point.x + 15) / width)*width;
		int center_y = ((point.y + 15) / width)*width;
		int center_xnum = ((point.x + 15) / width) - 2;
		int center_ynum = ((point.y + 15) / width) - 2;
		player.set_senter(center_x, center_y, center_xnum, center_ynum);

		if (((-1 < center_xnum) && (center_xnum < 10)) && ((-1 < center_ynum) && (center_ynum < 10))) {                                //블럭범위
			if (num == 1) {                                                                                                                //일자블럭
				if (shift % 2 == 0) {
					if (player.check_block1_region(0)) {    //격자에서 일자블럭범위
						if (player.check_block1_available(0)) { player.put_block1(&dc, 0); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }
				}
				else {
					if (player.check_block1_region(1)) {    //격자에서 sift_일자블럭범위
						if (player.check_block1_available(1)) { player.put_block1(&dc, 1); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }
				}
			}
			else if (num == 2) {                                                                                                          //이상한블럭
				if (shift % 2 == 0) {
					if (player.check_block2_region(0)) {                                  //이상한블럭범위
						if (player.check_block2_available(0)) { player.put_block2(&dc, 0); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }
				}
				else
					if (player.check_block2_region(1)) {                                  //격자에서 shift_이상한블럭범위
						if (player.check_block2_available(1)) { player.put_block2(&dc, 1); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }
			}
			else if (num == 3) {                                                                                                            //사각블럭
				if (player.check_block3_region()) {                                                               //사각블럭범위
					if (player.check_block3_available()) { player.put_block3(&dc); block_true = true; }
					else { block_true = false; }
				}
				else { block_true = false; }
			}
			else if (num == 4) {
				if (shift % 4 == 0) {
					if (player.check_block4_region(0)) {                                  //격자에서 ㅏ블럭범위
						if (player.check_block4_available(0)) { player.put_block4(&dc, 0); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }
				}
				else if (shift % 4 == 1) {
					if (player.check_block4_region(1)) {                                  //이상한블럭범위
						if (player.check_block4_available(1)) { player.put_block4(&dc, 1); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }

				}
				else if (shift % 4 == 2) {
					if (player.check_block4_region(2)) {                                  //이상한블럭범위
						if (player.check_block4_available(2)) { player.put_block4(&dc, 2); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }

				}
				else if (shift % 4 == 3) {
					if (player.check_block4_region(3)) {                                  //이상한블럭범위
						if (player.check_block4_available(3)) { player.put_block4(&dc, 3); block_true = true; }
						else { block_true = false; }
					}
					else { block_true = false; }

				}
			}
		}
		else
		{
			MessageBox(_T("이곳에는 놓을 수 없습니다"), _T("오류"), MB_ICONERROR);
			block_true = false;
		}
		if (block_true == true) {                            //블록을 놓았다면, 점수계산, 다음 생성도형예시, 게임진행결정
			player.add_score(5);
			player.clear(&dc);
			SetDlgItemInt(IDC_EDIT1, player.get_score());
			
			PlaySound(_T("click.wav"), NULL, SND_ASYNC);

			num = (rand() % 4) + 1;
			gamemode = player.check_gamemode(&dc, num);
			shift = 0;
		}
	}
	else if (gamemode == false) {
		CString msg;
		msg.Format(_T("게임이 종료되었습니다. \n점수: %d"), player.get_score());
		MessageBox(msg, _T("게임종료"), MB_ICONERROR);
	}
	score = player.get_score();
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
}



void CMy1010Dlg::OnBnClickedButton1()
{
	CClientDC dc(this);
	game_player player;
	
	if (IDYES == AfxMessageBox(L"재시작하시겠습니까?", MB_YESNO)) {
		gamemode = true;
		reset = true;
		player.player_reset(&dc);
		SetDlgItemInt(IDC_EDIT1, player.get_score());
	}
	else {
	}
	
}


/*void CMy1010Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}*/

BOOL CMy1010Dlg::PreTranslateMessage(MSG *pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_SHIFT)
	{
		CClientDC dc(this);
		shift++;
		if (gamemode == true) {                                    //생성도형예시, 게임진행결정
			game_frame game_frame_;
			game_frame_.turn_figrue(&dc, num, shift);
		}		
	}
	return CDialog::PreTranslateMessage(pMsg);
}
void CMy1010Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);	
	shift++;
	if (gamemode == true) {                                    //생성도형예시, 게임진행결정
		game_frame game_frame_;
		game_frame_.turn_figrue(&dc, num, shift);
	}

	//CDialogEx::OnRButtonDown(nFlags, point);
}


void CMy1010Dlg::OnBnClickedButton2()
{
	CString rank_name;
	CString rank_str;
	
	GetDlgItemText(IDC_EDIT2, rank_name);
	rank_str.Format(_T("%s : %d"), rank_name, score);
	rank_score.AddString(rank_str);

	if (score > score_max)
	{
		score_max = score;
		rank_str.Format(_T("%s : %d"), rank_name, score);
		rank_max.ResetContent();
		rank_max.AddString(rank_str);		
	}

		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy1010Dlg::On32773()
{
	MessageBox(_T("프로그래밍 프로젝트\n2017035154 유영빈"), _T("정보"), MB_ICONINFORMATION);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
