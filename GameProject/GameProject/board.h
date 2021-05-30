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
	RETURN_EXIT = -1, // ���� 
	RETURN_FATAL = -1, // ���� 
	RETURN_SUCCESS = 0, // ���� 
	RETURN_FAIL = 1, // ���� 
	RETURN_UNKNOWN,
	RETURN_RESUME, // �ٽý��� 
	RETURN_NEWGAME, // �� ���� 
	RETURN_STOP, //���� ���� 
	RETURN_FOOD, // ���� ���� 
	RETURN_WALL, //���� �ε��� 
}ReturnCode;

typedef enum //Ű���� �Է� 
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27
}Key;

typedef COORD Position;


void goto_xy(int x, int y); // Ŀ���̵�
void move_xy_draw(int x, int y, char ch);// Ŀ���̵� �� �Է�  
#endif

