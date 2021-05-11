#include <iostream>
#include <windows.h> // 콘솔 창에 적절한 출력을 위한 헤더파일입니다.
#include <conio.h> // 사용자의 키보드 입력을 위한 헤더파일입니다.

using namespace std;

// 커서의 위치를 나타내는 구조체 변수입니다.
struct Pos {
	int x;
	int y;
};

// 게임을 위한 알파벳 2차원 배열 구성입니다.
const char gameCard[5][5] = { {'A', 'B', 'C', 'D', 'E'},
							 {'F', 'G', 'H', 'I', 'J'},
							 {'K', 'L', 'M', 'N', 'O'},
							 {'P', 'Q', 'R', 'S', 'T'},
							 {'U', 'V', 'W', 'X', 'Y'} };

const char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXY";

// Game 진행을 위한 클래스입니다.
class CardGame
{
private:
	char reverseCard[5][5]; // 게임을 진행할 5X5 보드판을 나타냅니다.
	Pos now_pos; // 현재 커서의 위치를 저장할 변수입니다.
	Pos reverse_pos; // 뒤집은 카드 위치를 저장할 변수입니다.
	int flip_count; // 뒤집은 카드 개수를 저장할 변수입니다.
	int reverse_count; // 뒤집은 횟수를 저장할 변수입니다.
	int match_count; // 맞춘 카드 개수를 저장할 변수입니다.
public:
	CardGame();
	void init(); // 초기 게임 세팅을 설정해주고 게임을 시작하는 함수입니다.
	void movePos(int x, int y); // 커서의 위치를 이동시켜주는 함수입니다.
	void showExplain(); // 게임 설명을 콘솔창에 그려주는 함수입니다.
	void gameStart(); // 본 게임을 시작하는 함수입니다.
	int getInput(); // 키보드의 입력을 확인하고 이를 반환하는 함수입니다.
	void changePos(); // 상하좌우 해당 키보드 입력에 따라 위치를 이동하는 함수입니다.
	void openCard(); // 뒤집혀 있는 카드를 오픈하는 함수입니다.
	void showNow(); // 현재 상태를 그려주는 함수입니다.
	void checkNow(); // 현재 진행 상황을 알려주고 게임 진행 여부를 결정하는 함수입니다.
};