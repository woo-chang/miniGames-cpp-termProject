#include "match.h"

CardGame::CardGame() : reverse_count(0), match_count(0), flip_count(0), score_state(0), my_score(600)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			reverseCard[i][j] = '#';
		}
	}
	now_pos.x = 0;
	now_pos.y = 0;
	reverse_pos.x = 0;
	reverse_pos.y = 0;
}

void CardGame::init()
{
	system("mode con:cols=100 lines=30 | title Card Matching Game"); // 콘솔 창의 크기와 제목을 설정합니다.
	resetGame();
	showExplain();
	gameStart();
}

void CardGame::movePos(int x, int y) 
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void CardGame::showExplain()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
	movePos(30, 5);
	cout << "<Follow the Sequence of Alphabet>";
	movePos(29, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 콘솔 창의 글자색을 설정합니다.
	cout << "★ A부터 Y까지 순서대로 찾아보세요 ★";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
	movePos(38, 10);
	cout << "UP";
	movePos(38, 11);
	cout << "△";
	movePos(34, 12);
	cout << "LEFT ◁    ▷ RIGHT";
	movePos(38, 13);
	cout << "▽";
	movePos(38, 14);
	cout << "DOWN";
	movePos(35, 17);
	cout << "CLICK : SPACE";
	movePos(31, 24);
	cout << "Score = 600 - (4 x Click Count)";
}

void CardGame::gameStart()
{
	int keyBoard = 0;
	while (true) {
		keyBoard = getInput();
		if (keyBoard == 224) // 방향키가 입력 되었을 때를 의미합니다.
		{
			changePos();
		}
		if (keyBoard == 32) // 스페이스바가 입력 되었을 때를 의미합니다.
		{
			openCard();
		}
		showNow();
		Sleep(100);
		checkNow();
	}
}

int CardGame::getInput()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void CardGame::changePos()
{
	movePos(INIT_POS + (now_pos.x * 3), INIT_POS + (now_pos.y * 2) + 1);
	printf("  ");
	switch (_getch())
	{
	case 75:
		--now_pos.x;
		if (now_pos.x <= 0) now_pos.x = 0;
		break;
	case 77:
		++now_pos.x;
		if (now_pos.x >= 4) now_pos.x = 4;
		break;
	case 72:
		--now_pos.y;
		if (now_pos.y <= 0) now_pos.y = 0;
		break;
	case 80:
		++now_pos.y;
		if (now_pos.y >= 4) now_pos.y = 4;
		break;
	}
}

void CardGame::openCard()
{
	if (reverseCard[now_pos.x][now_pos.y] != '#') return;
	if (flip_count > 1) return;
	reverse_pos.x = now_pos.x;
	reverse_pos.y = now_pos.y;
	reverseCard[now_pos.x][now_pos.y] = gameCard[now_pos.x][now_pos.y];
	++flip_count;
}

void CardGame::showNow()
{
	char c = '\0';
	for (int y = 0; y < 5; y++) {
		movePos(INIT_POS, INIT_POS + (2 * y));
		for (int x = 0; x < 5; x++) {
			c = reverseCard[x][y];
			if (c != '#') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 콘솔 창의 글자색을 설정합니다.
			printf("[%c]   ", c);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
		}
	}
	movePos(INIT_POS + (now_pos.x * 3), INIT_POS + (now_pos.y * 2) + 1);
	printf(" ^");
	movePos(9, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	if (score_state == 0) {
		printf("★☆Score : %d☆★", my_score);
		movePos(33, 20);
		printf("★☆Click Count : %d☆★", reverse_count);
		score_state = 1;
	}
	else {
		printf("☆★Score : %d★☆", my_score);
		movePos(33, 20);
		printf("☆★Click Count : %d★☆", reverse_count);
		score_state = 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void CardGame::checkNow()
{
	if (flip_count == 1) {
		char c = '#';
		if (gameCard[now_pos.x][now_pos.y] == alpha[match_count]) {
			c = gameCard[now_pos.x][now_pos.y];
			++match_count;
		}
		else {
			Sleep(250);
		}
		reverseCard[now_pos.x][now_pos.y] = c;
		flip_count = 0;
		++reverse_count;
		my_score = my_score - 4;
		if (match_count >= 25) {
			gameClear();
			Sleep(5000);
			system("cls");
			init();
		}
	}
}

void CardGame::resetGame()
{
	vector<char> v = { 'A', 'B', 'C', 'D', 'E',
				  'F', 'G', 'H', 'I', 'J',
				  'K', 'L', 'M', 'N', 'O',
				  'P', 'Q', 'R', 'S', 'T',
				  'U', 'V', 'W', 'X', 'Y' }; // shuffle을 진행함으로 매 게임마다 새로운 게임판을 설정하기 위한 vector입니다.

	random_device rd; // random shuffle을 위한 변수입니다.
	mt19937 g(rd());
	shuffle(v.begin(), v.end(), g);

	int index = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gameCard[i][j] = v[index];
			index++;
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			reverseCard[i][j] = '#';
		}
	}

	now_pos.x = 0;
	now_pos.y = 0;
	reverse_pos.x = 0;
	reverse_pos.y = 0;

	reverse_count = 0;
	match_count = 0;
	flip_count = 0;
	score_state = 0;
	my_score = 600;
}

void CardGame::gameClear()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	movePos(7, 10);
	cout << "=============================";
	movePos(7, 11);
	cout << "========= C L E A R =========";
	movePos(7, 12);
	printf("======GAME SCORE : %d=======", my_score);
	movePos(7, 13);
	cout << "=============================";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}