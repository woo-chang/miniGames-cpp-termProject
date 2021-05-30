#ifndef __JUMPGAME__
#define __JUMPGAME__

#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <string>

#define TREE_BOTTOM_X 80
#define TREE_BOTTOM_Y 36
#define DINO_BOTTOM_Y 27

using namespace std;

class JumpGame{
private:
	string userID;
public:
	JumpGame(string ID) { userID = ID; };
	int input_k();
	void init();  	
	int menu(); 
	void gotoxy(int,int); 
	int game_start(); 
	void Dino_draw(int);
	void tree(int);
	void DrawGameOver(const int);
	bool gameover(const int, const int);
};

#endif
