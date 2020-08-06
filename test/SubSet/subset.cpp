#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int sum = 0; // �κ� ������ �� 
	bool ret = false;
	vector<int> vect;
	int i=0, j;
	int Test_case = 0; // �׽�Ʈ ���̽�
	int n = 0; // �迭 ����
	int val = 0;

	cin >> Test_case; // �׽�Ʈ ���̽� �Է� 

	for (int t = 0; t < Test_case; t++) {
		cin >> n; // �迭�� ���� �Է� 
		for (int k = 0; k < n; k++) {
			cin >> val;
			vect.push_back(val);
		}
		// 1<<n : �κ������� ����, 1��Ʈ�� �������� n�� ����Ʈ��
		// �κ� ������ 2x2x2x...xn�� �̹Ƿ� 2^n���� �κ� ������ �����̴�.
		for (j = 1; i < (1 << (n)); i++) { // N=5 �̹Ƿ� 32�� loop
			sum = 0; // ��� �κ������� ���� �˻��� �� �ٽ� 0���� set

			// j�� 0, 1, 01, 101, 100������ ��
			// i�� 1, 10, 101, 100, 101, ..., 11111 ������ ���� ����
			for (j = 0; j < n; j++) {
				if (i & (1 << j)) { // 00000 ~ 11111 ���� ��� �κ�����
					sum += vect[j];
				}
			}
			if (sum == 0) {
				ret = true;
				break;
			}
		}
		n = 0;
	}
	
	
	if (ret)
		cout << "True";
	else
		cout << "False";
	return 0;
}