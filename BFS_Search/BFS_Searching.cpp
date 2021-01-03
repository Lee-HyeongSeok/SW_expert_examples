#include <iostream>

using namespace std;

#define MAX_VERTEX 30

int num;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front;

void breadthFirstSearch(int vertex) {
	int i;

	// �ش� ���� �湮 ǥ��
	// ������ �ε����� ���
	visit[vertex] = 1; 

	// �湮�� ���� ���
	cout << vertex;
	

	// �湮�� ������ ť�� ���� 
	queue[rear++] = vertex;
	while (front < rear) {
		vertex = queue[front++];

		for (i = 1; i <= num; i++) {
			// ���� �湮���� ���� �����̶��, ���� ����
			if (map[vertex][i] == 1 && !visit[i]) {
				visit[i] = 1; // �湮������ ǥ��
				cout << " " << i; // �湮�� ���� ���
				queue[rear++] = i; // ť�� �湮�� ���� ����
				cout << "push";
			}
		}
	}
}

int main() {
	int T;
	int test_case;
	int start;
	int v1, v2;

	cin >> T; // �׽�Ʈ ���̽� �Է¹���

	for (test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				map[i][j] = 0;
			}
			visit[i] = 0;
			visit[i] = 0;
		}
		front = 0;
		rear = 0;

		cin >> num >> start;

		while (true) {
			cin >> v1 >> v2; // ���� 1, ���� 2�� �Է� ����
			if (v1 == -1 && v2 == -1)
				break;
			map[v1][v2] = map[v2][v1] = 1; // v1�� v2�� ������踦 ǥ���� 
		}
		cout << "# " << test_case;
		breadthFirstSearch(start);
		cout << endl;
	}
	return 0;
}