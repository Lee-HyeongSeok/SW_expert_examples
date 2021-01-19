#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXV 100005
#define MAXE 500005

struct EDGE {
	int x, y, w; // 두 정점 x, y와 엣지 가중치 w
}edge[MAXE], tmp[MAXE];

int V, E; // 정점, 엣지
int disjoint_set[MAXV]; // 정점 집합을 저장하기 위한 배열

// 시작 정점을 찾아준다.
int find_root(int x) {
	if (disjoint_set[x] == x)
		return x;
	// 정점 x와 연결된 다른 정점에 대해 재귀 호출
	disjoint_set[x] = find_root(disjoint_set[x]);

	return disjoint_set[x];
}

// s에서 e까지의 정점을 합병 정렬한다.
void MergeSort(int s, int e) {
	if (s < e) {
		int m = (s + e) / 2; // s 에서 e까지 거리의 중간을 찾아낸다.
		MergeSort(s, m); // s에서부터 m 까지 합병 정렬 실시
		MergeSort(m + 1, e); // m+1에서부터 e까지 합병 정렬 실시

		int left = s, right = m + 1, pointer = s;

		// 정렬될 원소가 올바른 위치에 있는지 검사
		while (left <= m && right <= e) {
			// 연결된 엣지의 가중치가 가장 작은 값을 검사
			if (edge[left].w <= edge[right].w) {
				// tmp 배열에 가중치가 가장 작은 간선을 저장
				tmp[pointer++] = edge[left++];
			}
			else {
				tmp[pointer++] = edge[right++];
			}
		}
		// 나머지 남은 값을 처리하는 부분
		while (left <= m)
			tmp[pointer++] = edge[left++];
		while (right <= e)
			tmp[pointer++] = edge[right++];

		// tmp에 저장된 최소 신장 엣지들을 edge에 다시 저장
		for (int i = s; i <= e; i++) {
			edge[i] = tmp[i];
		}
	}
}

void Kruskal(void) {
	int mst_total_weight = 0;

	// 모든 간선에 대해 순회
	for (int i = 0; i < E; i++) {
		int group_x = find_root(edge[i].x); // x정점
		int group_y = find_root(edge[i].y); // y정점

		// 사이클을 형성한다면
		if (group_x == group_y)
			continue;

		// 최소 신장 트리의 모든 가중치를 더한다.
		mst_total_weight += edge[i].w;

		disjoint_set[group_y] = group_x; // 강한 연결 상태를 만들어준다.
		printf("Union %d - %d\n", group_x, group_y);
	}

	printf("%d\n", mst_total_weight);
}

int main(void) {
	int TC;
	// 테스트 케이스를 입력받고 1씩 감소시킨다.
	for (scanf("%d", &TC); TC--;) {
		scanf("%d%d", &V, &E); // 정점과 간선을 입력받는다.

		for (int i = 1; i <= V; i++) {
			printf("Draw vertex %d\n", i);
			disjoint_set[i] = i; // 정점 집합을 저장
		}

		// 간선의 총 수만큼 순회
		for (int i = 0; i < E; i++) {
			// 연결된 정점 1, 2와 그 사이 간선의 가중치를 입력받는다.
			scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
		}

		// 모든 간선 범위를 합병 정렬 시킴
		MergeSort(0, E - 1);

		static int testcase = 0;
		printf("#%d", ++testcase);

		Kruskal();
	}
	return 0;
}