#include "match.h"

CardGame::CardGame() : reverse_count(0), match_count5(0), flip_count(0), score_state(0), my_score5(600), yourSelect(0)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			reverseCard5[i][j] = '#';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			reverseCard3[i][j] = '#';
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			reverseCard4[i][j] = '#';
		}
	}

	now_pos.x = 0;
	now_pos.y = 0;
	reverse_pos.x = 0;
	reverse_pos.y = 0;

	match_count3 = 0;
	my_score3 = 300;

	match_count4 = 0;
	my_score4 = 450;
}

void CardGame::init()
{
	system("mode con:cols=100 lines=30 | title Card Matching Game"); // 콘솔 창의 크기와 제목을 설정합니다.
	yourSelect = selectGame();
	system("cls"); // 콘솔창 지우기
	if (yourSelect == 4) return;
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
	if (yourSelect == 1) {
		cout << "<Follow the Sequence of Number>";
	}
	if (yourSelect == 2) {
		cout << "<Follow the Sequence of Hexadecimal>";
	}
	if (yourSelect == 3) {
		cout << "<Follow the Sequence of Alphabet>";
	}
	movePos(29, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 콘솔 창의 글자색을 설정합니다.
	if (yourSelect == 1) {
		cout << "★ 1부터 9까지 순서대로 찾아보세요 ★";
	}
	if (yourSelect == 2) {
		cout << "★ 0부터 F까지 순서대로 찾아보세요 ★";
	}
	if (yourSelect == 3) {
		cout << "★ A부터 Y까지 순서대로 찾아보세요 ★";
	}
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
	if (yourSelect == 1) {
		cout << "Score = 300 - (4 x Click Count)";
	}
	if (yourSelect == 2) {
		cout << "Score = 450 - (4 x Click Count)";
	}
	if (yourSelect == 3) {
		cout << "Score = 600 - (4 x Click Count)";
	}
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
		if (checkNow() == 1)
			break;
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
	if (yourSelect == 1) {
		movePos(INIT_POS_3 + (now_pos.x * 3), INIT_POS_3 + (now_pos.y * 2) + 1);
		printf("  ");
		switch (_getch())
		{
		case 75:
			--now_pos.x;
			if (now_pos.x <= 0) now_pos.x = 0;
			break;
		case 77:
			++now_pos.x;
			if (now_pos.x >= 2) now_pos.x = 2;
			break;
		case 72:
			--now_pos.y;
			if (now_pos.y <= 0) now_pos.y = 0;
			break;
		case 80:
			++now_pos.y;
			if (now_pos.y >= 2) now_pos.y = 2;
			break;
		}
	}
	if (yourSelect == 2) {
		movePos(INIT_POS_4 + (now_pos.x * 3), INIT_POS_4 + (now_pos.y * 2) + 1);
		printf("  ");
		switch (_getch())
		{
		case 75:
			--now_pos.x;
			if (now_pos.x <= 0) now_pos.x = 0;
			break;
		case 77:
			++now_pos.x;
			if (now_pos.x >= 3) now_pos.x = 3;
			break;
		case 72:
			--now_pos.y;
			if (now_pos.y <= 0) now_pos.y = 0;
			break;
		case 80:
			++now_pos.y;
			if (now_pos.y >= 3) now_pos.y = 3;
			break;
		}
	}
	if (yourSelect == 3) {
		movePos(INIT_POS_5 + (now_pos.x * 3), INIT_POS_5 + (now_pos.y * 2) + 1);
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
}

void CardGame::openCard()
{
	if (yourSelect == 1) {
		if (reverseCard3[now_pos.x][now_pos.y] != '#') return;
		if (flip_count > 1) return;
		reverse_pos.x = now_pos.x;
		reverse_pos.y = now_pos.y;
		reverseCard3[now_pos.x][now_pos.y] = gameCard3[now_pos.x][now_pos.y];
		++flip_count;
	}
	if (yourSelect == 2) {
		if (reverseCard4[now_pos.x][now_pos.y] != '#') return;
		if (flip_count > 1) return;
		reverse_pos.x = now_pos.x;
		reverse_pos.y = now_pos.y;
		reverseCard4[now_pos.x][now_pos.y] = gameCard4[now_pos.x][now_pos.y];
		++flip_count;
	}
	if (yourSelect == 3) {
		if (reverseCard5[now_pos.x][now_pos.y] != '#') return;
		if (flip_count > 1) return;
		reverse_pos.x = now_pos.x;
		reverse_pos.y = now_pos.y;
		reverseCard5[now_pos.x][now_pos.y] = gameCard5[now_pos.x][now_pos.y];
		++flip_count;
	}
}

void CardGame::showNow()
{
	if (yourSelect == 1) {
		char c = '\0';
		for (int y = 0; y < 3; y++) {
			movePos(INIT_POS_3, INIT_POS_3 + (2 * y));
			for (int x = 0; x < 3; x++) {
				c = reverseCard3[x][y];
				if (c != '#') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 콘솔 창의 글자색을 설정합니다.
				printf("[%c]   ", c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
			}
		}
		movePos(INIT_POS_3 + (now_pos.x * 3), INIT_POS_3 + (now_pos.y * 2) + 1);
		printf(" ^");
		movePos(9, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		if (score_state == 0) {
			printf("★☆Score : %d☆★", my_score3);
			movePos(33, 20);
			printf("★☆Click Count : %d☆★", reverse_count);
			score_state = 1;
		}
		else {
			printf("☆★Score : %d★☆", my_score3);
			movePos(33, 20);
			printf("☆★Click Count : %d★☆", reverse_count);
			score_state = 0;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (yourSelect == 2) {
		char c = '\0';
		for (int y = 0; y < 4; y++) {
			movePos(INIT_POS_4, INIT_POS_4 + (2 * y));
			for (int x = 0; x < 4; x++) {
				c = reverseCard4[x][y];
				if (c != '#') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 콘솔 창의 글자색을 설정합니다.
				printf("[%c]   ", c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
			}
		}
		movePos(INIT_POS_4 + (now_pos.x * 3), INIT_POS_4 + (now_pos.y * 2) + 1);
		printf(" ^");
		movePos(9, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		if (score_state == 0) {
			printf("★☆Score : %d☆★", my_score4);
			movePos(33, 20);
			printf("★☆Click Count : %d☆★", reverse_count);
			score_state = 1;
		}
		else {
			printf("☆★Score : %d★☆", my_score4);
			movePos(33, 20);
			printf("☆★Click Count : %d★☆", reverse_count);
			score_state = 0;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	if (yourSelect == 3) {
		char c = '\0';
		for (int y = 0; y < 5; y++) {
			movePos(INIT_POS_5, INIT_POS_5 + (2 * y));
			for (int x = 0; x < 5; x++) {
				c = reverseCard5[x][y];
				if (c != '#') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 콘솔 창의 글자색을 설정합니다.
				printf("[%c]   ", c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 콘솔 창의 글자색을 설정합니다.
			}
		}
		movePos(INIT_POS_5 + (now_pos.x * 3), INIT_POS_5 + (now_pos.y * 2) + 1);
		printf(" ^");
		movePos(9, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		if (score_state == 0) {
			printf("★☆Score : %d☆★", my_score5);
			movePos(33, 20);
			printf("★☆Click Count : %d☆★", reverse_count);
			score_state = 1;
		}
		else {
			printf("☆★Score : %d★☆", my_score5);
			movePos(33, 20);
			printf("☆★Click Count : %d★☆", reverse_count);
			score_state = 0;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

int CardGame::checkNow()
{
	if (yourSelect == 1) {
		if (flip_count == 1) {
			char c = '#';
			if (gameCard3[now_pos.x][now_pos.y] == num[match_count3]) {
				c = gameCard3[now_pos.x][now_pos.y];
				++match_count3;
			}
			else {
				Sleep(250);
			}
			reverseCard3[now_pos.x][now_pos.y] = c;
			flip_count = 0;
			++reverse_count;
			my_score3 = my_score3 - 4;
			if (match_count3 >= 9) {
				gameClear();
				Sleep(3000);
				system("cls"); // 콘솔창 지우기
				return 1;
			}
			return 0;
		}
	}
	if (yourSelect == 2) {
		if (flip_count == 1) {
			char c = '#';
			if (gameCard4[now_pos.x][now_pos.y] == hexa[match_count4]) {
				c = gameCard4[now_pos.x][now_pos.y];
				++match_count4;
			}
			else {
				Sleep(250);
			}
			reverseCard4[now_pos.x][now_pos.y] = c;
			flip_count = 0;
			++reverse_count;
			my_score4 = my_score4 - 4;
			if (match_count4 >= 16) {
				gameClear();
				Sleep(3000);
				system("cls"); // 콘솔창 지우기
				return 1;
			}
			return 0;
		}
	}
	if (yourSelect == 3) {
		if (flip_count == 1) {
			char c = '#';
			if (gameCard5[now_pos.x][now_pos.y] == alpha[match_count5]) {
				c = gameCard5[now_pos.x][now_pos.y];
				++match_count5;
			}
			else {
				Sleep(250);
			}
			reverseCard5[now_pos.x][now_pos.y] = c;
			flip_count = 0;
			++reverse_count;
			my_score5 = my_score5 - 4;
			if (match_count5 >= 25) {
				gameClear();
				Sleep(3000);
				system("cls"); // 콘솔창 지우기
				return 1;
			}
			return 0;
		}
	}
}

void CardGame::resetGame()
{
	now_pos.x = 0;
	now_pos.y = 0;
	reverse_pos.x = 0;
	reverse_pos.y = 0;

	reverse_count = 0;
	flip_count = 0;
	score_state = 0;

	random_device rd; // random shuffle을 위한 변수입니다.
	mt19937 g(rd());

	if (yourSelect == 1) {
		vector<char> v = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

		shuffle(v.begin(), v.end(), g);

		int index = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameCard3[i][j] = v[index];
				index++;
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				reverseCard3[i][j] = '#';
			}
		}

		match_count3 = 0;
		my_score3 = 300;

	}

	if (yourSelect == 2) {
		vector<char> v = { '0', '1', '2', '3', '4',
						  '5', '6', '7', '8', '9',
						  'A', 'B', 'C', 'D', 'E', 'F' };

		shuffle(v.begin(), v.end(), g);

		int index = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				gameCard4[i][j] = v[index];
				index++;
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				reverseCard4[i][j] = '#';
			}
		}

		match_count4 = 0;
		my_score4 = 450;
	}

	if (yourSelect == 3) {
		vector<char> v = { 'A', 'B', 'C', 'D', 'E',
					  'F', 'G', 'H', 'I', 'J',
					  'K', 'L', 'M', 'N', 'O',
					  'P', 'Q', 'R', 'S', 'T',
					  'U', 'V', 'W', 'X', 'Y' }; // shuffle을 진행함으로 매 게임마다 새로운 게임판을 설정하기 위한 vector입니다.

		shuffle(v.begin(), v.end(), g);

		int index = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				gameCard5[i][j] = v[index];
				index++;
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				reverseCard5[i][j] = '#';
			}
		}
		
		match_count5 = 0;
		my_score5 = 600;
	}
}

void CardGame::gameClear()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	movePos(7, 10);
	cout << "=============================";
	movePos(7, 11);
	cout << "========= C L E A R =========";
	movePos(7, 12);
	if (yourSelect == 1) {
		printf("======GAME SCORE : %d=======", my_score3);
	}
	if (yourSelect == 2) {
		printf("======GAME SCORE : %d=======", my_score4);
	}
	if (yourSelect == 3) {
		printf("======GAME SCORE : %d=======", my_score5);
	}
	movePos(7, 13);
	cout << "=============================";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int CardGame::getScore()
{
	if (yourSelect == 1) {
		return my_score3;
	}
	if (yourSelect == 2) {
		return my_score4;
	}
	if (yourSelect == 3) {
		return my_score5;
	}
	if (yourSelect == 4) {
		return 0;
	}
}

int CardGame::selectGame()
{
	movePos(19, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "◇Welcome to Card Game◇";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	movePos(20, 11);
	cout << "1. 3 X 3 Card Game";
	movePos(20, 12);
	cout << "2. 4 X 4 Card Game";
	movePos(20, 13);
	cout << "3. 5 X 5 Card Game";
	movePos(20, 14);
	cout << "4. Exit";

	int yourSelect;

	while (true) {
		movePos(20, 16);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "Your Select ? ";	
		cin >> yourSelect;
		if (yourSelect > 0 && yourSelect < 5) break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	return yourSelect;
}