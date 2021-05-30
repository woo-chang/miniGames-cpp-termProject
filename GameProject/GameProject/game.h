#ifndef __SNAKE_GAME__
#define __SNAKE_GAME__

#include "board.h"
#include "display.h"
#include "snake.h"
#include <string>
#include "DataSave.h"

class SnakeGame
{
	private:
		Snake snake_;
		Position food_pos;
		Position bomb_pos;
		Display display;
		int score;
		int GAME_SPEED;
		int level;
		bool check;
		string userID;
	public:
		SnakeGame(string ID);
		
		void Initialize();
		
		bool is_no_food();
		bool is_no_bomb();
		bool is_vaild_food_position(int x, int y);
		bool is_vaild_bomb_position(int x, int y);
		ReturnCode pause();
		ReturnCode start();
		ReturnCode play();
		ReturnCode stop();
		
		void make_food();
		void make_bomb();

};

#endif
