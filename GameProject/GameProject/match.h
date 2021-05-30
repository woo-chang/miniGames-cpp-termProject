#include <iostream>
#include <windows.h> // �ܼ� â�� ������ ����� ���� ��������Դϴ�.
#include <conio.h> // ������� Ű���� �Է��� ���� ��������Դϴ�.

#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
// vector�� ���� ���� �ϱ� ���� ��������Դϴ�.

#include <string>
#include "DataSave.h"
#define INIT_POS_3 10
#define INIT_POS_4 9
#define INIT_POS_5 7


using namespace std;

// Ŀ���� ��ġ�� ��Ÿ���� ����ü �����Դϴ�.
struct Pos {
	int x;
	int y;
};

const char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXY";
const char num[10] = "123456789";
const char hexa[17] = "0123456789ABCDEF";

// Game ������ ���� Ŭ�����Դϴ�.
class CardGame
{
private:
	char gameCard5[5][5]; // ������ ���� ���ĺ� 2���� �迭 �����Դϴ�.
	char reverseCard5[5][5]; // ������ ������ 5X5 �������� ��Ÿ���ϴ�.
	char gameCard3[3][3]; // ������ ���� 2���� �迭 �����Դϴ�.
	char reverseCard3[3][3]; // ������ ������ 3X3 �������� ��Ÿ���ϴ�.
	char gameCard4[4][4]; // ������ ���� 2���� �迭 �����Դϴ�.
	char reverseCard4[4][4]; // ������ ������ 4X4 �������� ��Ÿ���ϴ�.
	Pos now_pos; // ���� Ŀ���� ��ġ�� ������ �����Դϴ�.
	Pos reverse_pos; // ������ ī�� ��ġ�� ������ �����Դϴ�.
	int flip_count; // ������ ī�� ������ ������ �����Դϴ�.
	int reverse_count; // ������ Ƚ���� ������ �����Դϴ�.
	int match_count5; // 5X5 ������ ���� ī�� ������ ������ �����Դϴ�.
	int match_count3; // 3X3 ������ ���� ī�� ������ ������ �����Դϴ�.
	int match_count4; // 4X4 ������ ���� ī�� ������ ������ �����Դϴ�.
	int score_state; // ������ UI�� ��ȭ�� �ֱ� ���� �����Դϴ�.
	int my_score5; // 5X5 ������ ���� ������ ��Ÿ���� ���� �����Դϴ�.
	int my_score3; // 3X3 ������ ���� ������ ��Ÿ���� ���� �����Դϴ�.
	int my_score4; // 4X4 ������ ���� ������ ��Ÿ���� ���� �����Դϴ�.
	int yourSelect; // ���� ������ ���� �����Դϴ�.
	string userID;
public:
	CardGame(string userID);
	void init(); // �ʱ� ���� ������ �������ְ� ������ �����ϴ� �Լ��Դϴ�.
	void movePos(int x, int y); // Ŀ���� ��ġ�� �̵������ִ� �Լ��Դϴ�.
	void showExplain(); // ���� ������ �ܼ�â�� �׷��ִ� �Լ��Դϴ�.
	void gameStart(); // �� ������ �����ϴ� �Լ��Դϴ�.
	int getInput(); // Ű������ �Է��� Ȯ���ϰ� �̸� ��ȯ�ϴ� �Լ��Դϴ�.
	void changePos(); // �����¿� �ش� Ű���� �Է¿� ���� ��ġ�� �̵��ϴ� �Լ��Դϴ�.
	void openCard(); // ������ �ִ� ī�带 �����ϴ� �Լ��Դϴ�.
	void showNow(); // ���� ���¸� �׷��ִ� �Լ��Դϴ�.
	int checkNow(); // ���� ���� ��Ȳ�� �˷��ְ� ���� ���� ���θ� �����ϴ� �Լ��Դϴ�.
	void resetGame(); // ������ ����Ǹ� ���� ���ӿ� ����� ������ ���½����ִ� �Լ��Դϴ�.
	void gameClear(); // ������ ����Ǹ� ������ ���� ���� ������ Ȯ���� �� �ִ� �Լ��Դϴ�.
	int getScore(); // ���ӿ��� ȹ���� ������ ��ȯ�ϴ� �Լ��Դϴ�.
	int selectGame(); // �ϰ��� �ϴ� ������ ������ �� �ִ� �Լ��Դϴ�.
};