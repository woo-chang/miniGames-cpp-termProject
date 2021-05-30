#ifndef __PONG__
#define __PONG__

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

class Pong {
private:
	string userID;
public:
	Pong(string user);
	~Pong() {};
	void init();
	void gotoxy(int x, int y);
	int title();
	void titleDraw();
	void menuDraw();
	void info();
	void game();
	void gameScore(int s1, int s2);
};

#endif