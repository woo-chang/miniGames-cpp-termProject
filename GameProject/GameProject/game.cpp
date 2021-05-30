#include "game.h"

SnakeGame::SnakeGame(string userID) : userID(userID)
{
	Initialize();
}

// 먹이와 위치 초기화  
void SnakeGame::Initialize()
{
	check = true;
	food_pos.X = 0;
	food_pos.Y = 0;
	GAME_SPEED = 160;
	level = 0;
	score = 0;
}

//시작 전 처리 
ReturnCode SnakeGame::start()
{
	this->Initialize(); // 점수, 위치, 스피드 초기화 
	snake_.Initialize(); // 뱀 길이, 위치 초기화
	
	display.clear(); 
	display.draw_msg("게임을 시작하시겠습니까? (y / n)");
	
	int key;
	do
	{
		key = _getch();
	}
	while(key != 'y' && key != 'Y' && key != 'n' && key != 'N');
	
	switch (key)
	{
		case 'y':
		case 'Y':
			make_food();
			make_bomb();
			display.clear();
			goto_xy(80,13);
			cout << "SCORE : " << score;
			goto_xy(80,14);
			cout << "LEVEL : " << level+1;
			display.draw_option();
			display.draw_wall();
			display.draw_snake(snake_);
			display.draw_food(food_pos);
			display.draw_bomb(bomb_pos);
			return RETURN_SUCCESS;
		case 'n':
		case 'N':
			return RETURN_EXIT;
		default:
			return RETURN_UNKNOWN; 
	}
	 
}

// 실제 게임 실행 
ReturnCode SnakeGame::play()
{
	int key;
	while(true)
	{
		if(_kbhit())
		{
			key = _getch();
			if(key == 224)
			{
				key = _getch();
				switch(key)
				{
					case UP:
					case DOWN:
					case LEFT:
					case RIGHT:
						snake_.SetDirection((Key)key);
						break;
					default:
						return RETURN_FAIL; 
				}
			}
			else if (key == ESC)
			{
				switch(pause())
				{
					case RETURN_RESUME:
						display.clear();
						goto_xy(80,13);
						cout << "SCORE : " << score;
						goto_xy(80,14);
						cout << "LEVEL : " << level+1;
						display.draw_option();
						display.draw_wall();
						display.draw_snake(snake_);
						display.draw_food(food_pos);
						display.draw_bomb(bomb_pos);
						break;
					case RETURN_NEWGAME:
						return RETURN_NEWGAME;
					case RETURN_STOP:
						return RETURN_STOP;
					case RETURN_EXIT:
						return RETURN_EXIT;
					default:
						return RETURN_UNKNOWN;
						
				}
			}
		}
		
		
		if (score%3 == 0 && score != 0 && check)
		{
			
			if (GAME_SPEED > 0)
			{
				GAME_SPEED -= 20;
			}
			level += 1;
			goto_xy(80,14);
			cout << "LEVEL : " << level+1;
			check = false;
		}
		
		Sleep(GAME_SPEED);
		
		snake_.Move();
		
		if(snake_.head().X == 0 || snake_.head().X == 59 || snake_.head().Y == 0 || snake_.head().Y == 30 )
		{
			return RETURN_STOP; 
		} 
		// 자기 몸에 머리가 닿음  
		else if(snake_.is_bitten() == true)
		{
			return RETURN_STOP;
		}
		// 먹이 먹음  
		else if (snake_.head().X == food_pos.X && snake_.head().Y == food_pos.Y)
		{
			move_xy_draw(snake_.head().X, snake_.head().Y, 'o');
			move_xy_draw(bomb_pos.X, bomb_pos.Y, ' ');
			check = true;
			score++;
			food_pos.X = 0;
			food_pos.Y = 0;
			goto_xy(80,13);
			cout << "SCORE : " << score;
			bomb_pos.X = 0;
			bomb_pos.Y = 0;
		}
		// 폭탄 부딪힘 
		else if (snake_.head().X == bomb_pos.X && snake_.head().Y == bomb_pos.Y)
		{
			return RETURN_STOP;
		}
		else
		{
			move_xy_draw(snake_.head().X, snake_.head().Y, 'O');
			move_xy_draw(snake_.tail().X, snake_.tail().Y, ' ');
			snake_.body().pop_back();
		}
		
		if (is_no_food() == true)
		{
			make_food();
			display.draw_food(food_pos);
		}
		
		if (is_no_bomb() == true)
		{
			make_bomb();
			display.draw_bomb(bomb_pos);
		}
		
		
	}
		
	return RETURN_SUCCESS;
 } 
 
 ReturnCode SnakeGame::pause()
 {
 	display.draw_msg("(R)esume, (N)ew game, (S)top, (E)xit");
 	
 	int key;
 	do
 	{
 		key = _getch();	
	}
	while(key != 'r' && key != 'R' && key != 'n' && key != 'N' && key != 's' && key != 'S' && key != 'e' && key != 'E');
	
	switch(key)
	{
		case 'r':
		case 'R':
        	return RETURN_RESUME;
    	case 'n': 
		case 'N':
        	return RETURN_NEWGAME;
    	case 's': 
		case 'S':
        	return RETURN_STOP;
    	case 'e': 
		case 'E':
        	return RETURN_EXIT;
    	default:
        	return RETURN_UNKNOWN;
	}
 }
 
 ReturnCode SnakeGame::stop()
{
	display.clear();
	
	string tmp = "Score: " + to_string(score);
	const char* msg = tmp.c_str();
	display.draw_msg(msg);
	
	DataSave save;
	save.save(2, score, userID);
	
	goto_xy(55, 24);
	cout << "Press [Enter] to quit...";
	while (_getch() != ENTER);
		
	
	return RETURN_SUCCESS; 
}

void SnakeGame::make_food()
{
	int x, y;
	
	srand((unsigned int)time(NULL));
	do
	{
		x = rand()%59+1;
		y = rand()%29+1;
	}
	while(is_vaild_food_position(x,y) == false);
	
	food_pos.X = x;
	food_pos.Y = y;
 }
 
 void SnakeGame::make_bomb()
{
	int x, y;
	
	srand((unsigned int)time(NULL)*2);
	do
	{
		x = rand()%59+1;
		y = rand()%29+1;
	}
	while(is_vaild_bomb_position(x,y) == false);
	
	bomb_pos.X = x;
	bomb_pos.Y = y;
 }
 
bool SnakeGame::is_vaild_food_position(int x, int y)
{
 	list<Position>::const_iterator iter = snake_.body().begin();
 	while(iter != snake_.body().end())
 	{
 		if((x == iter->X) && (y == iter->Y))
 			return false;
 		iter++;
	}
	return true;
}

bool SnakeGame::is_vaild_bomb_position(int x, int y)
{
 	list<Position>::const_iterator iter = snake_.body().begin();
 	if (food_pos.X == x && food_pos.Y == y)
 	{
		 return false;
	}
	else
	{
			while(iter != snake_.body().end())
	 	{
	 		if((x == iter->X) && (y == iter->Y))
	 			return false;
	 		iter++;
		}
		return true;
		
	}
}
 
bool SnakeGame::is_no_food()
{
 	if(food_pos.X == 0 || food_pos.Y == 0)
 		return true;
 	else
 		return false;
}

bool SnakeGame::is_no_bomb()
{
 	if(bomb_pos.X == 0 || bomb_pos.Y == 0)
 		return true;
 	else
 		return false;
}
 
