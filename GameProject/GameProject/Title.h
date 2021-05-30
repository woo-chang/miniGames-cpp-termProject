#ifndef __TITLE__
#define __TITLE__

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <list>
using namespace std;

class Title
{
public:
	Title() {};
	~Title() {};
	void titleMain() {};
	void showRecord(string userName);
	string makeID();
	string selectID();
};

#endif