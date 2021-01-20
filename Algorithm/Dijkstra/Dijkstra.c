#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 100 // ������ ���� 100���� ����
#define INF 100000

int map[N + 1][N + 1]; // ��ü ������ �����ϱ� ���� �迭
int pre[N + 1]; // ���� ������ �����ϱ� ���� �迭
int visit[N + 1]; // �湮�� ������ �����ϱ� ���� �迭
int dist[N + 1]; 

int vertex; // ����
int edge; // ����
int start; // ���� ����
int end; // �Ϸ� ����

void dijkstra() {
	int i = 0, j = 0, min = 0, v = 0;

	// ���� ������ �ε����� ��� 
	dist[start] = 0;

	// ����� ������ ������ŭ ��ȸ
	for (i = 1; i <= vertex; i++) {
		min = INF;

		for (j = 1; j <= vertex; j++) {
			// �湮���� �ʾҰ� min���� ���� ����ġ�� ������ ���� ��
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j]; // �� ���� ����ġ�� ��ü
				v = j; // ����ġ�� ���� ���� �������� �̵�
			}
		}

		visit[v] = 1; // �ش� ������ �湮�� ������ �Ǵ�

		printf("unhighlight");

		for (j = 1; j <= vertex; j++) {
			if (j == v) // ���� ��ġ�� ������ ��ġ�� pass
				continue;
			if (map[v][j] == INF) // ������ ������ pass
				continue;

			if (dist[j] > dist[v] + map[v][j]) {
				dist[j] = dist[v] + map[v][j];
				if (pre[j] != -1) // ���� ������ �����Ѵٸ�
					puts("unhighlight");
				pre[j] = v; // ���� ������ ���� ���� ����
			}
			printf("unhighlight");
		}
		puts("unhighlight");
	}
}

int main() {
	int T = 0;
	int from = 0, to = 0, value = 0;

	scanf("%d", &T); // �׽�Ʈ ���̽� �Է�

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

		// ����� ������ ǥ���ϱ� ���� ������ ������ŭ ��ȸ
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