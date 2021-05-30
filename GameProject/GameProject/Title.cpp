#include "Title.h"

void Title::showRecord(string userName) {
	string file = userName + ".txt";
	ifstream in(file);

	if (!in) {
		cout << "���� ������ �÷��� �� ����� �����ϴ�!" << endl;
		Sleep(1500);
		return;
	}

	int arr[4] = { 0, 0, 0, 0 };

	for (int i = 0; i < 4; i++) {
		in >> arr[i];
	}

	string str = userName + "���� ����� ������ �����ϴ�."
		+ "\n1. ��: " + to_string(arr[0])
		+ "\n2. ī���ġ: " + to_string(arr[1])
		+ "\n3. �� ����: " + to_string(arr[2])
		+ "\n4. ��ֹ� �޸���: " + to_string(arr[3]);

	system("cls");
	cout << str << endl;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(1000);
	printf(" ���� �޴��� ���ư��� �ʹٸ� �ƹ� ��ư�̳� ��������\n");
	int c = _getch();

	in.close();
}

string Title::makeID() {
	system("cls");
	printf("���̵� ����\n\n\n");
	printf("�� ���̵� �Է��ϼ���: ");
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

	cout << "���ο������ �̸��� " << newID << "�Դϴ�.\n" << endl;
	printf("\n\n\n\n���̵� ������ ���� �Ǿ����ϴ�.");
	Sleep(500);
	printf("\n���ο� ���̵�� ������ �����մϴ�.");
	Sleep(1000);
	return newID;
}

string Title::selectID() {
	system("cls");
	string file = "userData.txt";
	ifstream in(file);

	if (!in) {//userData.txt ������ �������� �ʴ� ���
		printf("������ save������ �������� �ʽ��ϴ�.\n");
		printf("������ ���� �����մϴ�!\n");
		Sleep(1000);
		in.close();
		return makeID();
	}

	int userCnt;
	in >> userCnt;

	if(userCnt == 0){
		printf("�����Ǿ��ִ� ���̵� �����ϴ�.\n");
		printf("���̵� �����մϴ�...!\n");
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

		printf("������ ������ִ� ���̵��� ����Դϴ�.\n");
		list <string>::iterator output;
		int tmp = 0;
		for (output = userList.begin(); output != userList.end(); output++) {
			cout << tmp << ": " << *output << endl;
			tmp++;
		}

		printf("�Է��Ͻ� ��ȣ�� ���̵�� ���õ˴ϴ�.\n");
		cout << "0�������� " << userCnt - 1 << "������ ���� �Է��� �ּ���: ";
		
		int c;
		while (true) {
			cin >> c;
			if (c < 0 || c > userCnt - 1)
				cout << "\n�ٽ� �Է��� �ֽʽÿ�: ";
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

		cout << "�����Ͻ� ���̵�� " << selectID << "�Դϴ�\n";
		Sleep(1000);

		return selectID;
	}
}