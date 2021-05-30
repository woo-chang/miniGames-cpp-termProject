#include "Title.h"

void Title::showRecord(string userName) {
	string file = userName + ".txt";
	ifstream in(file);

	if (!in) {
		cout << "아직 게임을 플레이 한 기록이 없습니다!" << endl;
		Sleep(1500);
		return;
	}

	int arr[4] = { 0, 0, 0, 0 };

	for (int i = 0; i < 4; i++) {
		in >> arr[i];
	}

	string str = userName + "님의 기록은 다음과 같습니다."
		+ "\n1. 퐁: " + to_string(arr[0])
		+ "\n2. 카드매치: " + to_string(arr[1])
		+ "\n3. 뱀 게임: " + to_string(arr[2])
		+ "\n4. 장애물 달리기: " + to_string(arr[3]);

	system("cls");
	cout << str << endl;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(1000);
	printf(" 메인 메뉴로 돌아가고 싶다면 아무 버튼이나 누르세요\n");
	int c = _getch();

	in.close();
}

string Title::makeID() {
	system("cls");
	printf("아이디 생성\n\n\n");
	printf("새 아이디를 입력하세요: ");
	string newID = "";
	cin >> newID;

	string file = "userData.txt";
	ifstream in(file);

	int userCnt = 0;
	in >> userCnt;

	if (userCnt == 0) {
		userCnt = 1;
		in.close();

		ofstream out(file);
		out << userCnt << endl;
		out << newID << endl;

		out.close();
	}
	else {
		list <string> userList;
		for (int i = 0; i < userCnt; i++) {
			string tmp;
			in >> tmp;
			userList.push_back(tmp);
		}

		in.close();
		userList.push_back(newID);
		userCnt++;

		ofstream out(file);
		out << userCnt << endl;
		list <string>::iterator output;
		for (output = userList.begin(); output != userList.end(); output++)
			out << *output << endl;
		out.close();
	}

	cout << "새로운계정의 이름은 " << newID << "입니다.\n" << endl;
	printf("\n\n\n\n아이디 정보가 저장 되었습니다.");
	Sleep(500);
	printf("\n새로운 아이디로 게임을 시작합니다.");
	Sleep(1000);
	return newID;
}

string Title::selectID() {
	system("cls");
	string file = "userData.txt";
	ifstream in(file);

	if (!in) {//userData.txt 파일이 존재하지 않는 경우
		printf("기존의 save파일이 존재하지 않습니다.\n");
		printf("계정을 새로 생성합니다!\n");
		Sleep(1000);
		in.close();
		return makeID();
	}

	int userCnt;
	in >> userCnt;

	if(userCnt == 0){
		printf("생성되어있는 아이디가 없습니다.\n");
		printf("아이디를 생성합니다...!\n");
		Sleep(1000);
		in.close();
		return makeID();
	}
	else {
		list<string> userList;
		for (int i = 0; i < userCnt; i++) {
			string tmp;
			in >> tmp;
			userList.push_back(tmp);
		}

		printf("기존에 저장되있던 아이디의 목록입니다.\n");
		list <string>::iterator output;
		int tmp = 0;
		for (output = userList.begin(); output != userList.end(); output++) {
			cout << tmp << ": " << *output << endl;
			tmp++;
		}

		printf("입력하신 번호의 아이디로 선택됩니다.\n");
		cout << "0에서부터 " << userCnt - 1 << "사이의 수를 입력해 주세요: ";
		
		int c;
		while (true) {
			cin >> c;
			if (c < 0 || c > userCnt - 1)
				cout << "\n다시 입력해 주십시오: ";
			else
				break;
		}

		string selectID;
		output = userList.begin();
		for (int i = 0; i < userCnt; i++) {
			if (i == c) {
				selectID = *output;
			}
			output++;
		}

		cout << "선택하신 아이디는 " << selectID << "입니다\n";
		Sleep(1000);

		return selectID;
	}
}