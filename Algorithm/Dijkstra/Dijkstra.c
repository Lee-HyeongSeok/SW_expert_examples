#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 100 // 정점의 개수 100개로 제한
#define INF 100000

int map[N + 1][N + 1]; // 전체 정점을 저장하기 위한 배열
int pre[N + 1]; // 이전 정점을 저장하기 위한 배열
int visit[N + 1]; // 방문한 정점을 저장하기 위한 배열
int dist[N + 1]; 

int vertex; // 정점
int edge; // 간선
int start; // 시작 정점
int end; // 완료 정점

void dijkstra() {
	int i = 0, j = 0, min = 0, v = 0;

	// 시작 정점을 인덱스로 사용 
	dist[start] = 0;

	// 저장된 정점의 개수만큼 순회
	for (i = 1; i <= vertex; i++) {
		min = INF;

		for (j = 1; j <= vertex; j++) {
			// 방문하지 않았고 min보다 작은 가중치를 가지고 있을 때
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j]; // 더 작은 가중치로 교체
				v = j; // 가중치가 가장 작은 정점으로 이동
			}
		}

		visit[v] = 1; // 해당 정점은 방문한 것으로 판단

		printf("unhighlight");

		for (j = 1; j <= vertex; j++) {
			if (j == v) // 현재 위치인 정점과 겹치면 pass
				continue;
			if (map[v][j] == INF) // 정점이 없으면 pass
				continue;

			if (dist[j] > dist[v] + map[v][j]) {
				dist[j] = dist[v] + map[v][j];
				if (pre[j] != -1) // 이전 정점이 존재한다면
					puts("unhighlight");
				pre[j] = v; // 이전 정점에 현재 정점 저장
			}
			printf("unhighlight");
		}
		puts("unhighlight");
	}
}

int main() {
	int T = 0;
	int from = 0, to = 0, value = 0;

	scanf("%d", &T); // 테스트 케이스 입력

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d%d", &vertex, &start, &end);

		for (int i = 1; i <= vertex; i++) {
			printf("setData");
		}
		scanf("%d", &edge);

		for (int i = 1; i <= vertex; i++) {
			for (int j = 1; j <= vertex; j++) {
				if (i != j) {
					map[i][j] = INF;
				}
			}
		}

		// 연결된 정점을 표시하기 위해 간선의 개수만큼 순회
		for (int i = 1; i <= edge; i++) {
			scanf("%d %d %d", &from, &to, &value);
			map[from][to] = value;
		}

		for (int i = 1; i <= vertex; i++) {
			dist[i] = INF;
			visit[i] = 0;
			pre[i] = -1;
		}

		printf("#%d ", test_case);
		dijkstra();
		printf("%d \n", dist[end]);
	}
	return 0;
}