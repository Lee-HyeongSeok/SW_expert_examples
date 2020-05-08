#include <iostream>
using namespace std;

#define MAX_SIZE 8

int main() {
	int length;
	int cnt;
	char map[MAX_SIZE][MAX_SIZE] = { 0, };
	bool flag;

	int Test_case = 0;	// �׽�Ʈ ���̽�
	cin >> Test_case;	// �׽�Ʈ ���̽� �Է�
	for (int i = 0; i < Test_case; i++) {
		cin >> length;	// ã���� �ϴ� ����
		
		for (int j = 0; j < MAX_SIZE; j++) {
			for (int k = 0; k < MAX_SIZE; k++) {
				cin >> map[j][k];
			}
		}

		cnt = 0;
		for (int j = 0; j < MAX_SIZE; j++) { // ���� �˻� 
			// ������ ���̰� 4���, 8-4+1 = 5
			// k�� 0���� 4���� ����, ��ü ������ �ε����� 0���� 7����
			// �˻��� ������ ������Ű�� for��
			for (int k = 0; k < (MAX_SIZE - length + 1); k++) { 
				flag = true;	// �ʱ� �÷��� 1�� ����
				// ������ ���̰� 4���, m�� 0���� 1���� ����
				// (4, 7)-(5, 6) �̷������� �˻�
				for (int m = 0; m < (length / 2); m++) {
					if (map[j][m + k] != map[j][k + length - m - 1])
						flag = false;  // ���ڰ� ���Ī�� �� false;
				}
				if (flag)
					cnt++;
			}
		}
		for (int j = 0; j < MAX_SIZE; j++) { // ���� �˻�
			for (int k = 0; k < (MAX_SIZE - length + 1); k++) { // �˻��� ���� ����
				flag = true;

				for (int m = 0; m < (length / 2); m++) { // ������ ������ �˻��ϱ� ����
					if (map[m + k][j] != map[k + length - m - 1][j])
						flag = false;
				}
				if (flag)
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;

}