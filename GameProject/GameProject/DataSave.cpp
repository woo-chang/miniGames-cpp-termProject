#include "DataSave.h"

/*
매개변수 설명
game은 몇번째 게임이냐를 전달(0. 퐁, 1. 매치, 2. 뱀 게임, 3. 장애물 피하기)
score은 해당 게임에서 획득한 점수
name은 게임을 현재 진행중인 플레이어의 이름

반환값 설명
0: 기존의 점수보다, 이번의 점수가 더 높음
1: 기존의 점수가, 이번의 점수보다 더 높음
*/

int DataSave::save(int game, int score, string name) {
	//사용자의 이름.txt 파일로 데이터를 저장하고 관리합니다.
	string file = name + ".txt";
	ifstream in(file);
	int saveScore[4] = { 0, 0, 0, 0 };
	int result = 1;

	if (!in) {//파일이 없는 경우
		saveScore[game] = score;
		result = 0;
	}
	else {//파일이 있는경우
		//파일에 저장된 스코어(게임 1부터 4까지)를 읽어옵니다.
		for (int i = 0; i < 4; i++) {
			in >> saveScore[i];
		}
		if (score > saveScore[game]) {
			saveScore[game] = score;
			result = 0;
		}
	}
	in.close();


	ofstream out(file);
	for (int i = 0; i < 4; i++)
		out << saveScore[i] << endl;
	out.close();
	return result;
}