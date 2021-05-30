#include <iostream>
#include <windows.h> // 콘솔 창에 적절한 출력을 위한 헤더파일입니다.
#include <conio.h> // 사용자의 키보드 입력을 위한 헤더파일입니다.

#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
// vector를 랜덤 셔플 하기 위한 헤더파일입니다.

#include <string>
#include "DataSave.h"
#define INIT_POS_3 10
#define INIT_POS_4 9
#define INIT_POS_5 7


using namespace std;

// 커서의 위치를 나타내는 구조체 변수입니다.
struct Pos {
	int x;
	int y;
};

const char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXY";
const char num[10] = "123456789";
const char hexa[17] = "0123456789ABCDEF";

// Game 진행을 위한 클래스입니다.
class CardGame
{
private:
	char gameCard5[5][5]; // 게임을 위한 알파벳 2차원 배열 구성입니다.
	char reverseCard5[5][5]; // 게임을 진행할 5X5 보드판을 나타냅니다.
	char gameCard3[3][3]; // 게임을 위한 2차원 배열 구성입니다.
	char reverseCard3[3][3]; // 게임을 진행할 3X3 보드판을 나타냅니다.
	char gameCard4[4][4]; // 게임을 위한 2차원 배열 구성입니다.
	char reverseCard4[4][4]; // 게임을 진행할 4X4 보드판을 나타냅니다.
	Pos now_pos; // 현재 커서의 위치를 저장할 변수입니다.
	Pos reverse_pos; // 뒤집은 카드 위치를 저장할 변수입니다.
	int flip_count; // 뒤집은 카드 개수를 저장할 변수입니다.
	int reverse_count; // 뒤집은 횟수를 저장할 변수입니다.
	int match_count5; // 5X5 보드판 맞춘 카드 개수를 저장할 변수입니다.
	int match_count3; // 3X3 보드판 맞춘 카드 개수를 저장할 변수입니다.
	int match_count4; // 4X4 보드판 맞춘 카드 개수를 저장할 변수입니다.
	int score_state; // 점수판 UI의 변화를 주기 위한 변수입니다.
	int my_score5; // 5X5 보드판 게임 점수를 나타내기 위한 변수입니다.
	int my_score3; // 3X3 보드판 게임 점수를 나타내기 위한 변수입니다.
	int my_score4; // 4X4 보드판 게임 점수를 나타내기 위한 변수입니다.
	int yourSelect; // 게임 선택을 위한 변수입니다.
	string userID;
public:
	CardGame(string userID);
	void init(); // 초기 게임 세팅을 설정해주고 게임을 시작하는 함수입니다.
	void movePos(int x, int y); // 커서의 위치를 이동시켜주는 함수입니다.
	void showExplain(); // 게임 설명을 콘솔창에 그려주는 함수입니다.
	void gameStart(); // 본 게임을 시작하는 함수입니다.
	int getInput(); // 키보드의 입력을 확인하고 이를 반환하는 함수입니다.
	void changePos(); // 상하좌우 해당 키보드 입력에 따라 위치를 이동하는 함수입니다.
	void openCard(); // 뒤집혀 있는 카드를 오픈하는 함수입니다.
	void showNow(); // 현재 상태를 그려주는 함수입니다.
	int checkNow(); // 현재 진행 상황을 알려주고 게임 진행 여부를 결정하는 함수입니다.
	void resetGame(); // 게임이 종료되면 이전 게임에 사용한 값들을 리셋시켜주는 함수입니다.
	void gameClear(); // 게임이 종료되면 게임을 통해 얻은 점수를 확인할 수 있는 함수입니다.
	int getScore(); // 게임에서 획득한 점수를 반환하는 함수입니다.
	int selectGame(); // 하고자 하는 게임을 선택할 수 있는 함수입니다.
};