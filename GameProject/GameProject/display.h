#ifndef __SCREEN__
#define __SCREEN__

#include "board.h"
#include "snake.h"


class Display
{
	private:
		const int width; // 가로 
		const int height; // 세로 
	public:
		Display(); // 생성자 
		
		void draw_option();
		void draw_wall(); 
		void draw_food(Position pos);
		void draw_snake(Snake snake);
		void draw_msg(const char * msg);
		void clear();
		void draw_bomb(Position pos);
		
		const int get_width() const;
		const int get_height() const;
		
};

#endif
