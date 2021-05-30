#ifndef __DATASAVE__
#define __DATASAVE__

#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DataSave
{
public:
	DataSave() {};
	~DataSave() {};
	int save(int game, int score, string name);
};

#endif