#include "board.h"

using namespace std;

void goto_xy(int x, int y)
{
	Position pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void move_xy_draw(int x, int y, char ch)
{
	Position pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	putchar(ch);
}

