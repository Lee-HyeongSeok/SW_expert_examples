#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXV 100005
#define MAXE 500005

struct EDGE {
	int x, y, w; // �� ���� x, y�� ���� ����ġ w
}edge[MAXE], tmp[MAXE];

int V, E; // ����, ����
int disjoint_set[MAXV]; // ���� ������ �����ϱ� ���� �迭

// ���� ������ ã���ش�.
int find_root(int x) {
	if (disjoint_set[x] == x)
		return x;
	// ���� x�� ����� �ٸ� ������ ���� ��� ȣ��
	disjoint_set[x] = find_root(disjoint_set[x]);

	return disjoint_set[x];
}

// s���� e������ ������ �պ� �����Ѵ�.
void MergeSort(int s, int e) {
	if (s < e) {
		int m = (s + e) / 2; // s ���� e���� �Ÿ��� �߰��� ã�Ƴ���.
		MergeSort(s, m); // s�������� m ���� �պ� ���� �ǽ�
		MergeSort(m + 1, e); // m+1�������� e���� �պ� ���� �ǽ�

		int left = s, right = m + 1, pointer = s;

		// ���ĵ� ���Ұ� �ùٸ� ��ġ�� �ִ��� �˻�
		while (left <= m && right <= e) {
			// ����� ������ ����ġ�� ���� ���� ���� �˻�
			if (edge[left].w <= edge[right].w) {
				// tmp �迭�� ����ġ�� ���� ���� ������ ����
				tmp[pointer++] = edge[left++];
			}
			else {
				tmp[pointer++] = edge[right++];
			}
		}
		// ������ ���� ���� ó���ϴ� �κ�
		while (left <= m)
			tmp[pointer++] = edge[left++];
		while (right <= e)
			tmp[pointer++] = edge[right++];

		// tmp�� ����� �ּ� ���� �������� edge�� �ٽ� ����
		for (int i = s; i <= e; i++) {
			edge[i] = tmp[i];
		}
	}
}

void Kruskal(void) {
	int mst_total_weight = 0;

	// ��� ������ ���� ��ȸ
	for (int i = 0; i < E; i++) {
		int group_x = find_root(edge[i].x); // x����
		int group_y = find_root(edge[i].y); // y����

		// ����Ŭ�� �����Ѵٸ�
		if (group_x == group_y)
			continue;

		// �ּ� ���� Ʈ���� ��� ����ġ�� ���Ѵ�.
		mst_total_weight += edge[i].w;

		disjoint_set[group_y] = group_x; // ���� ���� ���¸� ������ش�.
		printf("Union %d - %d\n", group_x, group_y);
	}

	printf("%d\n", mst_total_weight);
}

int main(void) {
	int TC;
	// �׽�Ʈ ���̽��� �Է¹ް� 1�� ���ҽ�Ų��.
	for (scanf("%d", &TC); TC--;) {
		scanf("%d%d", &V, &E); // ������ ������ �Է¹޴´�.

		for (int i = 1; i <= V; i++) {
			printf("Draw vertex %d\n", i);
			disjoint_set[i] = i; // ���� ������ ����
		}

		// ������ �� ����ŭ ��ȸ
		for (int i = 0; i < E; i++) {
			// ����� ���� 1, 2�� �� ���� ������ ����ġ�� �Է¹޴´�.
			scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
		}

		// ��� ���� ������ �պ� ���� ��Ŵ
		MergeSort(0, E - 1);

		static int testcase = 0;
		printf("#%d", ++testcase);

		Kruskal();
	}
	return 0;
}