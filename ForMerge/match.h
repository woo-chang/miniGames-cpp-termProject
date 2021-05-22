#include <iostream>
#include <windows.h> // �ܼ� â�� ������ ����� ���� ��������Դϴ�.
#include <conio.h> // ������� Ű���� �Է��� ���� ��������Դϴ�.

#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
// vector�� ���� ���� �ϱ� ���� ��������Դϴ�.
#define INIT_POS 7

using namespace std;

// Ŀ���� ��ġ�� ��Ÿ���� ����ü �����Դϴ�.
struct Pos {
	int x;
	int y;
};

const char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXY";

// Game ������ ���� Ŭ�����Դϴ�.
class CardGame
{
private:
	char gameCard[5][5]; // ������ ���� ���ĺ� 2���� �迭 �����Դϴ�.
	char reverseCard[5][5]; // ������ ������ 5X5 �������� ��Ÿ���ϴ�.
	Pos now_pos; // ���� Ŀ���� ��ġ�� ������ �����Դϴ�.
	Pos reverse_pos; // ������ ī�� ��ġ�� ������ �����Դϴ�.
	int flip_count; // ������ ī�� ������ ������ �����Դϴ�.
	int reverse_count; // ������ Ƚ���� ������ �����Դϴ�.
	int match_count; // ���� ī�� ������ ������ �����Դϴ�.
	int score_state; // ������ UI�� ��ȭ�� �ֱ� ���� �����Դϴ�.
	int my_score; // ���� ������ ��Ÿ���� ���� �����Դϴ�.
public:
	CardGame();
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
};