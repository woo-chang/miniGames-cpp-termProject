#include <iostream>
#include <windows.h> // �ܼ� â�� ������ ����� ���� ��������Դϴ�.
#include <conio.h> // ������� Ű���� �Է��� ���� ��������Դϴ�.

using namespace std;

// Ŀ���� ��ġ�� ��Ÿ���� ����ü �����Դϴ�.
struct Pos {
	int x;
	int y;
};

// ������ ���� ���ĺ� 2���� �迭 �����Դϴ�.
const char gameCard[5][5] = { {'A', 'B', 'C', 'D', 'E'},
							 {'F', 'G', 'H', 'I', 'J'},
							 {'K', 'L', 'M', 'N', 'O'},
							 {'P', 'Q', 'R', 'S', 'T'},
							 {'U', 'V', 'W', 'X', 'Y'} };

const char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXY";

// Game ������ ���� Ŭ�����Դϴ�.
class CardGame
{
private:
	char reverseCard[5][5]; // ������ ������ 5X5 �������� ��Ÿ���ϴ�.
	Pos now_pos; // ���� Ŀ���� ��ġ�� ������ �����Դϴ�.
	Pos reverse_pos; // ������ ī�� ��ġ�� ������ �����Դϴ�.
	int flip_count; // ������ ī�� ������ ������ �����Դϴ�.
	int reverse_count; // ������ Ƚ���� ������ �����Դϴ�.
	int match_count; // ���� ī�� ������ ������ �����Դϴ�.
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
	void checkNow(); // ���� ���� ��Ȳ�� �˷��ְ� ���� ���� ���θ� �����ϴ� �Լ��Դϴ�.
};