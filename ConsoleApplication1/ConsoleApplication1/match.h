#include <iostream>
#include <windows.h> // �ܼ� â�� ������ ����� ���� ��������Դϴ�.
#include <conio.h> // ������� Ű���� �Է��� ���� ��������Դϴ�.

using namespace std;

// Ŀ���� ��ġ�� ��Ÿ���� ����ü �����Դϴ�.
struct Pos {
	int x;
	int y;
};

// Game ������ ���� Ŭ�����Դϴ�.
class CardGame
{
private:
	char reverseCard[5][5]; // ������ ������ 5X5 �������� ��Ÿ���ϴ�.
	Pos now_pos; // ���� Ŀ���� ��ġ�� ������ �����Դϴ�.
	Pos reverse_pos; // ������ ī�� ��ġ�� ������ �����Դϴ�.
	int reverse_count; // ������ Ƚ���� ������ �����Դϴ�.
	int match_count; // ���� ī�� ������ ������ �����Դϴ�.
public:
	CardGame();
	void init(); // �ʱ� ���� ������ �������ְ� ������ �����ϴ� �Լ��Դϴ�.
	void movePos(int x, int y); // Ŀ���� ��ġ�� �̵������ִ� �Լ��Դϴ�.
	void showExplain(); // ���� ������ �ܼ�â�� �׷��ִ� �Լ��Դϴ�.
	void gameStart(); // �� ������ �����ϴ� �Լ��Դϴ�.
	int getInput(); // Ű������ �Է��� Ȯ���ϰ� �̸� ��ȯ�ϴ� �Լ��Դϴ�.
};