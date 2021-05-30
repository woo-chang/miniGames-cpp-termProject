#include "Title.h"
#include "pong.h"
#include "match.h"
#include "game.h"
#include "jumpGame.h"
using namespace std;

int pongMain(string userID);
int matchMain(string userID);
int snakeMain(string userID);
int jumpMain(string userID);

void goToMyPos(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setMyMainScreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goToMyPos(6, 5);
	cout << "□        □  □□□  □        □  □□□      □□□□        □        □        □  □□□□□";
	goToMyPos(6, 6);
	cout << "□□    □□    □    □□      □    □      □               □ □      □□    □□  □";
	goToMyPos(6, 7);
	cout << "□  □□  □    □    □  □    □    □      □    □□□    □   □     □  □□  □  □□□□□";
	goToMyPos(6, 8);
	cout << "□        □    □    □    □  □    □      □        □   □□□ □    □        □  □";
	goToMyPos(6, 9);
	cout << "□        □    □    □      □□    □      □        □  □       □   □        □  □";
	goToMyPos(6, 10);
	cout << "□        □  □□□  □        □  □□□      □□□□   □         □  □        □  □□□□□";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int main(void) {
	Title title;
	string userID = title.selectID();

	cout << "1" << endl;

	while (true) {
		system("cls");
		int select = 0;
		system("mode con:cols=120 lines=30 | title Collection of MINI GAMES"); // 콘솔 창의 크기와 제목을 설정합니다.

		setMyMainScreen();

		goToMyPos(24, 15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "현재 계정 : " << userID << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		goToMyPos(24, 17);
		cout << "1 : 퐁";
		goToMyPos(24, 18);
		cout << "2 : 카드찾기";
		goToMyPos(24, 19);
		cout << "3 : 뱀게임";
		goToMyPos(24, 20);
		cout << "4 : 점프게임";
		goToMyPos(24, 21);
		cout << "5 : 종료";
		goToMyPos(24, 22);
		cout << "6 : 기록보기";
		goToMyPos(24, 23);
		cout << "7 : 계정 바꾸기";
		goToMyPos(24, 24);
		cout << "8 : 새 계정 만들기" << endl;
		goToMyPos(24, 26);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Your Choice ? ";
		cin >> select;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		switch (select)
		{
		case 1: pongMain(userID); break;
		case 2: matchMain(userID); break;
		case 3: snakeMain(userID); break;
		case 4: jumpMain(userID); break;
		case 5: return 0; break;
		case 6: title.showRecord(userID); break;
		case 7: userID = title.selectID(); break;
		case 8: userID = title.makeID(); break;
		}
	}

	return 0;
}

int pongMain(string userID) {
	Pong pong(userID);
	pong.init();

	while (true)
	{
		int screen = pong.title();
		switch (screen)
		{
		case 1: pong.game(); break;
		case 2: pong.info(); break;
		case 3: return 0;
		}
	}
}

int matchMain(string userID) {
	CardGame* cardgame = new CardGame(userID);
	cardgame->init();
	delete(cardgame);

	return 0;
}

int snakeMain(string userID) {
	system("mode con cols=120 lines=31 | title no");
	SnakeGame game(userID);
	ReturnCode ret;

	while (true)
	{
		ret = game.start();
		if (ret != RETURN_SUCCESS)
		{
			return 0;
		}

		ret = game.play();
		if (ret == RETURN_NEWGAME)
			continue;
		else if (ret == RETURN_EXIT)
			return 0;
		else if ((ret != RETURN_STOP) && (ret != RETURN_SUCCESS))
			return 0;

		game.stop();

		break;
	}

	return 0;
}

int jumpMain(string userID) {
	int score;
	JumpGame j(userID);
	int end = 0;
	j.init();
	int menu_select = j.menu();
	if (menu_select == 0) {
		score = j.game_start();
		DataSave save;
		save.save(3, score, userID);
	}
	else if (menu_select == 1) {
		return 0;
	}

	return 0;
}