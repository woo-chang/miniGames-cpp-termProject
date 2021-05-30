#include "Pong.h"
#include "DataSave.h"

Pong::Pong(string user) {
	userID = user;
}

void Pong::init()
{
	//가로의 길이, 세로의 길이, 타이틀의 이름 설정
	system("mode con:cols=100 lines=30 | title 퐁");

	//커서를 숨기는 코드
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//커서를 원하는 위치를 이동시키는 함수
void Pong::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

//타이틀 화면의 출력을 담당하는 함수
int Pong::title()
{
	system("cls"); //콘솔창 전체를 비우는 함수
	titleDraw();
	menuDraw();

	int curP[3] = { 19, 20, 21 };
	int curStatus = 0;
	int c;
	gotoxy(41, curP[curStatus]);
	printf(">");

	while (1)
	{
		c = _getch(); //사용자 키보드 입력

		if (c == 224) //방향키등의 특수키는 224 XX의 2바이트 입력이 들어옴
		{
			c = _getch();
			gotoxy(41, curP[curStatus]);
			printf(" ");

			switch (c)
			{
			case 72: curStatus == 0 ? curStatus = 2 : curStatus--; break;
			case 80: curStatus == 2 ? curStatus = 0 : curStatus++; break;
			}

			gotoxy(41, curP[curStatus]);
			printf(">");
		}

		if (c == 13)
		{
			switch (curStatus)
			{
			case 0: return 1;
			case 1: return 2;
			case 2: return 3;
			}
		}
	}

}

void Pong::titleDraw()
{
	printf("\n\n\n\n\n\n\n");
	printf("                        □□□□       □□□      □      □      □□□\n");
	printf("                        □     □    □      □    □□    □    □\n");
	printf("                        □□□□     □      □    □  □  □    □    □□\n");
	printf("                        □           □      □    □    □□    □      □\n");
	printf("                        □             □□□      □      □      □□□\n");
}

//타이틀 화면의 출력을 담당하는 함수
void Pong::menuDraw()
{
	gotoxy(43, 19);
	printf("게 임 시 작");
	gotoxy(43, 20);
	printf("게 임 정 보");
	gotoxy(43, 21);
	printf("   종 료  ");
}

//게임정보 화면의 출력을 담당하는 함수
void Pong::info()
{
	system("cls");
	printf("\n\n\n");
	printf(" 제작 : 정해원\n");
	printf(" 소속 : 부산대학교 컴퓨터공학과\n");
	printf(" 제작일시 : 2021 - 03 - 26\n");
	printf(" ver 1.0\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(1000);
	printf(" 메인 메뉴로 돌아가고 싶다면 아무 버튼이나 누르세요\n");
	int c = _getch();
}

//아래로는 게임의 기능 구현에 관련된 함수들이 포함되어 있음
void Pong::game()
{
	system("cls");

	int s1 = 0, s2 = 0;
	gameScore(s1, s2);
	gotoxy(0, 3);
	//printf("----------------------------------------------------------------------------------------------------");

	int p1 = 15, p2 = 15, bx, by, xVec, yVec;

	while (s1 < 5 && s2 < 5)
	{
		bx = 49, by = 15, xVec = 1, yVec = 1;
		while (1) {
			if (GetAsyncKeyState(0x57) && p1 > 5)
				p1--;
			if (GetAsyncKeyState(0x53) && p1 < 22)
				p1++;
			if (GetAsyncKeyState(VK_UP) && p2 > 5)
				p2--;
			if (GetAsyncKeyState(VK_DOWN) && p2 < 22)
				p2++;

			for (int i = 0; i < 7; i++)
			{
				gotoxy(8, p1 - 2 + i);
				if (i != 0 && i != 6)
					printf("|");
				else
					printf(" ");
				gotoxy(90, p2 - 2 + i);
				if (i != 0 && i != 6)
					printf("|");
				else
					printf(" ");
			}

			gotoxy(bx, by);
			printf("  ");


			if (by == 4 || by == 24)
				yVec = -yVec;
			if ((bx == 8 && (p1 <= by+1 && p1 >= by-3)) || (bx == 89 && (p2 <= by+1 && p2 >= by-3)))
				xVec = -xVec;
			bx += xVec;
			by += yVec;

			gotoxy(bx, by);
			printf("○");

			if (bx == 0 || bx == 98)
			{
				if (bx == 0)
				{
					s2++;
				}
				if (bx == 98)
				{
					s1++;
				}
				system("cls");
				gameScore(s1, s2);
				break;
			}
			Sleep(50);
		}
	}
	int score = (s1 - s2) * 100;
	if (score < 0)
		score = 0;

	DataSave save;
	int result = save.save(0, score, userID);
	if (result == -1) {
		cout << "최고 기록을 갱신했습니다!" << endl;
		cout << "이번의 기록: " << score << endl;
	}
	else {
		cout << "기존 기록이 더 좋습니다!" << endl;
		cout << "기존의 기록: " << result << endl;
		cout << "이번의 기록: " << score << endl;
	}
}

void Pong::gameScore(int s1, int s2)
{
	gotoxy(40, 1);
	printf("S1 : %d", s1);
	gotoxy(53, 1);
	printf("S2 : %d", s2);
}