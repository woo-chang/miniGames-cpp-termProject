#ifndef __BOARD__
#define __BOARD__

#include <ctime>
#include <list>
#include<conio.h>
#include<cstdlib>
#include<iostream> 
#include<windows.h>

typedef enum
{
	RETURN_EXIT = -1, // 종료 
	RETURN_FATAL = -1, // 에러 
	RETURN_SUCCESS = 0, // 성공 
	RETURN_FAIL = 1, // 실패 
	RETURN_UNKNOWN,
	RETURN_RESUME, // 다시시작 
	RETURN_NEWGAME, // 새 게임 
	RETURN_STOP, //게임 종료 
	RETURN_FOOD, // 먹이 먹음 
	RETURN_WALL, //벽에 부딪힘 
}ReturnCode;

typedef enum //키보드 입력 
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27
}Key;

typedef COORD Position;


void goto_xy(int x, int y); // 커서이동
void move_xy_draw(int x, int y, char ch);// 커서이동 후 입력  
#endif

