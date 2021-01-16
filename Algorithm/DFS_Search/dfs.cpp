#include <iostream>

using namespace std;

/*
	연결 행렬을 이용한 DFS 탐색
	시간 복잡도 : O(V^2), V는 정점, E는 간선 개수
*/
// 첫째줄에 케이스 개수
// 둘째줄부터 정점과 정점의 연결 정보를 입력한다.

#define MAX_VERTEX 30 // 최대 정점 개수 30개로 제한

int vertex; // 정점 개수를 저장하기 위한 변수
int map[MAX_VERTEX][MAX_VERTEX]; // 그래프 연결을 표시하기 위한 2차원 배열
int visit[MAX_VERTEX]; // 방문한 정점을 표시하기 위한 1차원 배열

void depthFirstSearch(int v) {
	int i = 0;
	visit[v] = 1; // 탐색을 시작하는 노드는 방문했음을 미리 표시

	// 정점 총 개수만큼 loop
	// 특정 정점과 연결되어 있는 정점들을 표시해주기 위함
	for (i = 1; i <= vertex; i++) {
		// 이미 방문했던 노드로 표시되어있을 때
		if (map[v][i] == 1 && !visit[i]) {
			cout << i; // 정점 v와 연결된 i들을 출력한다 -> 방문순서 출력
			depthFirstSearch(i); // 정점 v와 연결된 i에 대해서 재귀 탐색(깊게 탐색)
		}
	}
}




int main() {
	int T;
	int i, j;
	int start;
	int v1;
	int v2;

	cin >> T; // 테스트 케이스 수 입력받음

	cin >> vertex >> start; // 정점과 시작정점 입력

	for (int test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i < MAX_VERTEX; i++) {
			for (int j = 0; j < MAX_VERTEX; j++) {
				map[i][j] = 0; // 모든 정점 초기화
			}
			visit[i] = 0; // 모든 정점 방문 여부 배열 초기화
		}

		while (1) {
			cin >> v1 >> v2; // 연결된 정점 입력
			if (v1 == -1 && v2 == -1) // 두 정점에 -1을 삽입하면 정점 입력 종료
				break;

			map[v1][v2] = map[v2][v1] = 1; // 두 정점이 서로 연결되어 있음을 표시 
		}

		cout << "#Test Case : " << test_case << endl;
		cout << "시작 정점 : " << start << endl;
		depthFirstSearch(start);
		cout << endl;
	}

	

	return 0;
}