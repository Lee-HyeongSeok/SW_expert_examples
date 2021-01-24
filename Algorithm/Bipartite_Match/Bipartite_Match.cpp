#include <iostream>

using namespace std;

#define MAX 1000

int countA, countB;
int matchA[MAX];
int matchB[MAX];
int adj[MAX][MAX];
int visited[MAX];

int dfs(int a) {
	int b = 0;

	// a정점을 이미 방문 했다면
	if (visited[a])
		return 0; // 0 리턴

	// a정점 미방문 상태
	visited[a] = 1; // 방문 상태로 만들어줌

	// 아직 연결 안한 부분이 있는지 검사
	for (b = 0; b < countB; ++b) {
		// 새로운 정점과 연결이 안되어있다면
		if (adj[a][b] && (matchB[b] == -1 || dfs(matchB[b]))) {

			// 연결 해준다
			matchA[a] = b;
			matchB[b] = a;
			return 1;
		}
	}
	return 0;
}

int bipartiteMatch(void) {
	int size = 0;
	int start = 0;
	int i = 0;

	for (start = 0; start < countA; ++start) {
		for (i = 0; i < countA; i++) {
			visited[i] = 0;
		}

		if (dfs(start)) {
			size++;
		}
	}
	return size;
}

void init() {
	for (int i = 0; i < countA; i++) {
		matchA[i] = -1;

		for (int j = 0; j < countB; j++) {
			adj[i][j] = 0;
		}
		for (int z = 0; z < countB; z++)
			matchB[z] = -1;
	}
}

int main() {
	int T = 0;
	int adjCount = 0;
	int a, b;

	cin >> T; // 테스트 케이스 입력 

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> countA;
		cin >> countB;

		init();

		cin >> adjCount;

		for (int i = 0; i < adjCount; i++) {
			cin >> a;
			cin >> b;
			adj[a - 1][b - 1] = 1;
		}

		cout << "#" << test_case << " " << bipartiteMatch() << endl;
	}
	return 0;
}