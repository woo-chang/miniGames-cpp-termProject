#include "DataSave.h"

/*
�Ű����� ����
game�� ���° �����̳ĸ� ����(0. ��, 1. ��ġ, 2. �� ����, 3. ��ֹ� ���ϱ�)
score�� �ش� ���ӿ��� ȹ���� ����
name�� ������ ���� �������� �÷��̾��� �̸�

��ȯ�� ����
0: ������ ��������, �̹��� ������ �� ����
1: ������ ������, �̹��� �������� �� ����
*/

int DataSave::save(int game, int score, string name) {
	//������� �̸�.txt ���Ϸ� �����͸� �����ϰ� �����մϴ�.
	string file = name + ".txt";
	ifstream in(file);
	int saveScore[4] = { 0, 0, 0, 0 };
	int result = 1;

	if (!in) {//������ ���� ���
		saveScore[game] = score;
		result = 0;
	}
	else {//������ �ִ°��
		//���Ͽ� ����� ���ھ�(���� 1���� 4����)�� �о�ɴϴ�.
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