#include <iostream>

using namespace std;

int cardArr[10] = { 0, };

bool triple_flag = false;
bool run_flag = false;

void Check() {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (cardArr[i] >= 3) {
			cardArr[i] -= 3; // �ش� ī���� �˻��� ������ ���ؼ��� ����
			triple_flag = true;
			i--;	// �ٷ� �������� ��˻�
		}
		// 1�� ������ ī�带 ������ ���ӵ� 3���� ī�忡 1�̻��� ������ �ִ��� �Ǵ�
		if ((cardArr[i] >= 1) && (cardArr[i + 1] >= 1) && (cardArr[i + 2] >= 1)) {
			// �ش� ī���� �˻��� ������ ���ؼ��� ����
			cardArr[i] -= 1;
			cardArr[i + 1] -= 1;
			cardArr[i + 2] -= 1;
			run_flag = true;
			i--;
		}
	}
}
int main() {
	int T;
	cin >> T; // �׽�Ʈ ���̽� �Է�
	int card = 0;
	

	for (int i = 0; i < T; i++) {
		cin >> card;
		for (int j = 0; j < 6; j++) {
			cardArr[(card % 10)]++;
			card /= 10;
		}
		Check();

		if (triple_flag) {
			if (run_flag)
				cout << "Baby Gin" << endl;
			else
				cout << "Lose" << endl;
		}

	}
}