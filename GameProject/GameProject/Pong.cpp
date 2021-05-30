#include "Pong.h"
#include "DataSave.h"

Pong::Pong(string user) {
	userID = user;
}

void Pong::init()
{
	//������ ����, ������ ����, Ÿ��Ʋ�� �̸� ����
	system("mode con:cols=100 lines=30 | title ��");

	//Ŀ���� ����� �ڵ�
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//Ŀ���� ���ϴ� ��ġ�� �̵���Ű�� �Լ�
void Pong::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

//Ÿ��Ʋ ȭ���� ����� ����ϴ� �Լ�
int Pong::title()
{
	system("cls"); //�ܼ�â ��ü�� ���� �Լ�
	titleDraw();
	menuDraw();

	int curP[3] = { 19, 20, 21 };
	int curStatus = 0;
	int c;
	gotoxy(41, curP[curStatus]);
	printf(">");

	while (1)
	{
		c = _getch(); //����� Ű���� �Է�

		if (c == 224) //����Ű���� Ư��Ű�� 224 XX�� 2����Ʈ �Է��� ����
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
	printf("                        �����       ����      ��      ��      ����\n");
	printf("                        ��     ��    ��      ��    ���    ��    ��\n");
	printf("                        �����     ��      ��    ��  ��  ��    ��    ���\n");
	printf("                        ��           ��      ��    ��    ���    ��      ��\n");
	printf("                        ��             ����      ��      ��      ����\n");
}

//Ÿ��Ʋ ȭ���� ����� ����ϴ� �Լ�
void Pong::menuDraw()
{
	gotoxy(43, 19);
	printf("�� �� �� ��");
	gotoxy(43, 20);
	printf("�� �� �� ��");
	gotoxy(43, 21);
	printf("   �� ��  ");
}

//�������� ȭ���� ����� ����ϴ� �Լ�
void Pong::info()
{
	system("cls");
	printf("\n\n\n");
	printf(" ���� : ���ؿ�\n");
	printf(" �Ҽ� : �λ���б� ��ǻ�Ͱ��а�\n");
	printf(" �����Ͻ� : 2021 - 03 - 26\n");
	printf(" ver 1.0\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(1000);
	printf(" ���� �޴��� ���ư��� �ʹٸ� �ƹ� ��ư�̳� ��������\n");
	int c = _getch();
}

//�Ʒ��δ� ������ ��� ������ ���õ� �Լ����� ���ԵǾ� ����
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
			printf("��");

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
		cout << "�ְ� ����� �����߽��ϴ�!" << endl;
		cout << "�̹��� ���: " << score << endl;
	}
	else {
		cout << "���� ����� �� �����ϴ�!" << endl;
		cout << "������ ���: " << result << endl;
		cout << "�̹��� ���: " << score << endl;
	}
}

void Pong::gameScore(int s1, int s2)
{
	gotoxy(40, 1);
	printf("S1 : %d", s1);
	gotoxy(53, 1);
	printf("S2 : %d", s2);
}