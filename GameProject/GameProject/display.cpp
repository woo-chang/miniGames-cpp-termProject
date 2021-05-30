#include "display.h"
#include "game.h"

//������ 
Display::Display(): width(60), height(30){}

// ���� ��������  
const int Display::get_width() const 
{
	return width;
}

const int Display::get_height() const
{
	return height;
}

// �� ����ϱ�  
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

// �� ����� 
void Display::draw_wall()
{
	// ��� ��  
	for(int x = 0, y = 0; x < get_width(); x++)
	{

		move_xy_draw(x,y, '+');
	}
	// �ϴ� ��  
	for(int x = 0, y = get_height(); x < get_width(); x++)
	{

		move_xy_draw(x,y, '+');
	}
	
	// ���� ��  
	for(int x = 0, y = 1; y < get_height(); y++)
	{

		move_xy_draw(x,y, '+');
	}
	// ���� ��
	for(int x = get_width(), y = 0; y <= get_height(); y++)
	{

		move_xy_draw(x,y, '+');
	}
}

// ���� ���  
void Display::draw_food(Position pos)
{

	goto_xy(pos.X, pos.Y);
	cout <<  "$";
}
// �� �׸���  
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
	cout << " ����Ű �̵�( ���� : ��, ������ : ��, �� : ��, �Ʒ� : ��)";
	goto_xy(61,26);
	cout << " �Ͻ����� : ESC"; 
}








