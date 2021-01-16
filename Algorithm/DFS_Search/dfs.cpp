#include <iostream>

using namespace std;

/*
	���� ����� �̿��� DFS Ž��
	�ð� ���⵵ : O(V^2), V�� ����, E�� ���� ����
*/
// ù°�ٿ� ���̽� ����
// ��°�ٺ��� ������ ������ ���� ������ �Է��Ѵ�.

#define MAX_VERTEX 30 // �ִ� ���� ���� 30���� ����

int vertex; // ���� ������ �����ϱ� ���� ����
int map[MAX_VERTEX][MAX_VERTEX]; // �׷��� ������ ǥ���ϱ� ���� 2���� �迭
int visit[MAX_VERTEX]; // �湮�� ������ ǥ���ϱ� ���� 1���� �迭

void depthFirstSearch(int v) {
	int i = 0;
	visit[v] = 1; // Ž���� �����ϴ� ���� �湮������ �̸� ǥ��

	// ���� �� ������ŭ loop
	// Ư�� ������ ����Ǿ� �ִ� �������� ǥ�����ֱ� ����
	for (i = 1; i <= vertex; i++) {
		// �̹� �湮�ߴ� ���� ǥ�õǾ����� ��
		if (map[v][i] == 1 && !visit[i]) {
			cout << i; // ���� v�� ����� i���� ����Ѵ� -> �湮���� ���
			depthFirstSearch(i); // ���� v�� ����� i�� ���ؼ� ��� Ž��(��� Ž��)
		}
	}
}




int main() {
	int T;
	int i, j;
	int start;
	int v1;
	int v2;

	cin >> T; // �׽�Ʈ ���̽� �� �Է¹���

	cin >> vertex >> start; // ������ �������� �Է�

	for (int test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				map[i][j] = 0; // ��� ���� �ʱ�ȭ
			}
			visit[i] = 0; // ��� ���� �湮 ���� �迭 �ʱ�ȭ
		}

		while (1) {
			cin >> v1 >> v2; // ����� ���� �Է�
			if (v1 == -1 && v2 == -1) // �� ������ -1�� �����ϸ� ���� �Է� ����
				break;

			map[v1][v2] = map[v2][v1] = 1; // �� ������ ���� ����Ǿ� ������ ǥ�� 
		}

		cout << "#Test Case : " << test_case << endl;
		cout << "���� ���� : " << start << endl;
		depthFirstSearch(start);
		cout << endl;
	}

	

	return 0;
}