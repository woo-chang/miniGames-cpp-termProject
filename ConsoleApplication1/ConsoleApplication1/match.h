#include <iostream>
#include <windows.h> // 콘솔 창에 적절한 출력을 위한 헤더파일입니다.
#include <conio.h> // 사용자의 키보드 입력을 위한 헤더파일입니다.

using namespace std;

// 커서의 위치를 나타내는 구조체 변수입니다.
struct Pos {
	int x;
	int y;
};

// Game 진행을 위한 클래스입니다.
class CardGame
{
private:
	char reverseCard[5][5]; // 게임을 진행할 5X5 보드판을 나타냅니다.
	Pos now_pos; // 현재 커서의 위치를 저장할 변수입니다.
	Pos reverse_pos; // 뒤집은 카드 위치를 저장할 변수입니다.
	int reverse_count; // 뒤집은 횟수를 저장할 변수입니다.
	int match_count; // 맞춘 카드 개수를 저장할 변수입니다.
public:
	CardGame();
	void init(); // 초기 게임 세팅을 설정해주고 게임을 시작하는 함수입니다.
	void movePos(int x, int y); // 커서의 위치를 이동시켜주는 함수입니다.
	void showExplain(); // 게임 설명을 콘솔창에 그려주는 함수입니다.
	void gameStart(); // 본 게임을 시작하는 함수입니다.
	int getInput(); // 키보드의 입력을 확인하고 이를 반환하는 함수입니다.
};