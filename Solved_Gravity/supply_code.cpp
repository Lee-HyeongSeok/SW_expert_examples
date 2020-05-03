#include <iostream>

using namespace std;

#define EMPTY 0
#define BOX 1
#define MAX_SIZE 100

int main() {
	int testCase;

	int roomWidth, roomHeight; // ����, ����
	int maxFallen;

	int room[MAX_SIZE][MAX_SIZE] = { EMPTY, }; // �ڽ� ���θ� ǥ���ϱ� ���� ��
	int boxTop[MAX_SIZE] = { 0, }; // ���� ������ ��ܿ� �ִ� �ڽ��� �˻��ϱ� ���� �迭
	int countEmptySpace; // �� ���� ������ ���� ����

	cin >> testCase; // �׽�Ʈ ���̽� �Է�

	for (int t = 0; t < testCase; t++) {
		cin >> roomWidth >> roomHeight; // ����, ���� �Է�
		maxFallen = 0;
		for (int i = 0; i < roomWidth; i++) {
			cin >> boxTop[i]; // �ڽ��� ������ �Է¹޴´�.
			for (int j = 0; j < boxTop[i]; j++) // �ڽ��� ������� 1�� ��ŷ
				room[i][j] = BOX;
		}
		for (int i = 0; i < roomWidth; i++) {
			if (boxTop[i] > 0) { // �ڽ��� 1�� �̻� ������ ��
				countEmptySpace = 0;
				for (int j = i + 1; j < roomWidth; j++) { // �� ��ġ ���� �ڽ� ���� �˻�
					if (room[j][boxTop[i] - 1] == EMPTY) // �� ��ġ�� ���� ���� �Ÿ� ���, 0�� ���� �Ÿ�
						countEmptySpace += 1;
				}
				if (countEmptySpace > maxFallen) // ���� ū ���� �Ÿ��� ����
					maxFallen = countEmptySpace;
			}
		}
		cout << maxFallen << endl;
	}
}