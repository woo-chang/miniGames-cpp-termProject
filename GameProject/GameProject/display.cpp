#include "display.h"
#include "game.h"

//생성자 
Display::Display(): width(60), height(30){}

// 길이 가져오기  
const int Display::get_width() const 
{
	return width;
}

const int Display::get_height() const
{
	return height;
}

// 글 출력하기  
void Display::draw_msg(const char * msg)
{
	goto_xy(0, 12);
	for (int i = 0; i < 60; i++)
		cout << "-";
	
	goto_xy(0,14);
	for (int i = 0; i < 60; i++)
		cout << "-";
	
	goto_xy(30 - strlen(msg)/2, 13);
	printf("%s", msg);
}

// 벽 만들기 
void Display::draw_wall()
{
	// 상단 벽  
	for(int x = 0, y = 0; x < get_width(); x++)
	{

		move_xy_draw(x,y, '+');
	}
	// 하단 벽  
	for(int x = 0, y = get_height(); x < get_width(); x++)
	{

		move_xy_draw(x,y, '+');
	}
	
	// 좌측 벽  
	for(int x = 0, y = 1; y < get_height(); y++)
	{

		move_xy_draw(x,y, '+');
	}
	// 우측 벽
	for(int x = get_width(), y = 0; y <= get_height(); y++)
	{

		move_xy_draw(x,y, '+');
	}
}

// 먹이 출력  
void Display::draw_food(Position pos)
{

	goto_xy(pos.X, pos.Y);
	cout <<  "$";
}
// 뱀 그리기  
void Display::draw_snake(Snake snake)
{
	list<Position>::const_iterator iter = snake.body().begin();

	move_xy_draw(iter->X, iter->Y, 'O');
	
	while(++iter != snake.body().end())
	{
		move_xy_draw(iter->X, iter->Y, 'o');
	}

	
}

void Display::clear()
{
	system("cls");
}

void Display::draw_bomb(Position pos)
{
	goto_xy(pos.X, pos.Y);
	cout <<  "X";
}

void Display::draw_option()
{
	goto_xy(61,25);
	cout << " 방향키 이동( 왼쪽 : ←, 오른쪽 : →, 위 : ↑, 아래 : ↓)";
	goto_xy(61,26);
	cout << " 일시중지 : ESC"; 
}








