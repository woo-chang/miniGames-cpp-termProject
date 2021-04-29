#include "match.h"

CardGame::CardGame() : reverse_count(0), match_count(0)
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
	movePos(30, 2);
	cout << "<Follow the Sequence of Alphabet>";
	movePos(29, 3);
	cout << "☆ A부터 X까지 순서대로 찾아보세요 ☆";
	movePos(38, 7);
	cout << "UP";
	movePos(38, 8);
	cout << "△";
	movePos(34, 9);
	cout << "LEFT ◁    ▷ RIGHT";
	movePos(38, 10);
	cout << "▽";
	movePos(38, 11);
	cout << "DOWN";
	movePos(35, 14);
	cout << "CLICK : SPACE";
	int a;
	cin >> a;
	cout << a;
}

void CardGame::gameStart()
{

}

int CardGame::getInput()
{
	return 0;
}