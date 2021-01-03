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

	// 해당 정점 방문 표시
	// 정점을 인덱스로 사용
	visit[vertex] = 1; 

	// 방문한 정점 출력
	cout << vertex;
	

	// 방문한 정점을 큐에 삽입 
	queue[rear++] = vertex;
	while (front < rear) {
		vertex = queue[front++];

		for (i = 1; i <= num; i++) {
			// 아직 방문하지 않은 정점이라면, 인접 정점
			if (map[vertex][i] == 1 && !visit[i]) {
				visit[i] = 1; // 방문했음을 표시
				cout << " " << i; // 방문한 정점 출력
				queue[rear++] = i; // 큐에 방문한 정점 삽입
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

	cin >> T; // 테스트 케이스 입력받음

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
			cin >> v1 >> v2; // 정점 1, 정점 2를 입력 받음
			if (v1 == -1 && v2 == -1)
				break;
			map[v1][v2] = map[v2][v1] = 1; // v1과 v2의 연결관계를 표시함 
		}
		cout << "# " << test_case;
		breadthFirstSearch(start);
		cout << endl;
	}
	return 0;
}