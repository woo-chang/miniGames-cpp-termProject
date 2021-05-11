#include "match.h"

CardGame::CardGame() : reverse_count(0), match_count(0), flip_count(0)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			reverseCard[i][j] = '#';
		}
	}
	now_pos.x = 0;
	now_pos.y = 0;
	reverse_pos.x = 0;
	reverse_pos.y = 0;
}

void CardGame::init()
{
	system("mode con:cols=100 lines=30 | title Card Matching Game"); // 콘솔 창의 크기와 제목을 설정합니다.
	showExplain();
	gameStart();
}

void CardGame::movePos(int x, int y) 
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void CardGame::showExplain()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
	movePos(30, 5);
	cout << "<Follow the Sequence of Alphabet>";
	movePos(29, 6);
	cout << "☆ A부터 Y까지 순서대로 찾아보세요 ☆";
	movePos(38, 10);
	cout << "UP";
	movePos(38, 11);
	cout << "△";
	movePos(34, 12);
	cout << "LEFT ◁    ▷ RIGHT";
	movePos(38, 13);
	cout << "▽";
	movePos(38, 14);
	cout << "DOWN";
	movePos(35, 17);
	cout << "CLICK : SPACE";
}

void CardGame::gameStart()
{
	int keyBoard = 0;
	while (true) {
		keyBoard = getInput();
		if (keyBoard == 224) // 방향키가 입력 되었을 때
		{
			changePos();
		}
		if (keyBoard == 32) // 스페이스바가 입력 되었을 때
		{
			openCard();
		}
		showNow();
		Sleep(100);
		checkNow();
	}
}

int CardGame::getInput()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void CardGame::changePos()
{
	movePos(1 + (now_pos.x * 3), 1 + (now_pos.y * 2) + 1);
	printf("  ");
	switch (_getch())
	{
	case 75:
		--now_pos.x;
		if (now_pos.x <= 0) now_pos.x = 0;
		break;
	case 77:
		++now_pos.x;
		if (now_pos.x >= 4) now_pos.x = 4;
		break;
	case 72:
		--now_pos.y;
		if (now_pos.y <= 0) now_pos.y = 0;
		break;
	case 80:
		++now_pos.y;
		if (now_pos.y >= 4) now_pos.y = 4;
		break;
	}
}

void CardGame::openCard()
{
	if (reverseCard[now_pos.x][now_pos.y] != '#') return;
	if (flip_count > 1) return;
	reverse_pos.x = now_pos.x;
	reverse_pos.y = now_pos.y;
	reverseCard[now_pos.x][now_pos.y] = gameCard[now_pos.x][now_pos.y];
	++flip_count;
}

void CardGame::showNow()
{
	char c = '\0';
	for (int y = 0; y < 5; y++) {
		movePos(1, 1 + (2 * y));
		for (int x = 0; x < 5; x++) {
			c = reverseCard[x][y];
			printf("[%c]   ", c);
		}
	}
	movePos(1 + (now_pos.x * 3), 1 + (now_pos.y * 2) + 1);
	printf(" ^");
	movePos(30, 20);
	printf("Count : %d", reverse_count);
}

void CardGame::checkNow()
{
	if (flip_count == 1) {
		char c = '#';
		if (gameCard[now_pos.x][now_pos.y] == alpha[match_count]) {
			c = gameCard[now_pos.x][now_pos.y];
			++match_count;
		}
		else {
			Sleep(500);
		}
		reverseCard[now_pos.x][now_pos.y] = c;
		flip_count = 0;
		++reverse_count;
		if (match_count >= 25) {
			Sleep(500);
			system("cls");
			init();
		}
	}
}