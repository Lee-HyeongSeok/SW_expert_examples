#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 50005
#define MAXM 150005

struct EDGE {
	int s, e, prv;
}E[MAXM];

int to[MAXN];

int N, M;
int deg[MAXN], Q[MAXN], fr, re;

void makeVertex() {
	for (int i = 1; i <= N; i++) {
		to[i] = -1;
	}
}
int main() {
	int x, y;
	int T = 0;

	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &N, &M);

		makeVertex();

		for (int i = 1; i <= M; i++) {
			scanf("%d %d", &x, &y);
			E[i].s = x;
			E[i].e = y;
			E[i].prv = to[x];
			to[x] = i;

			deg[y]++;
		}

		fr = 0, re = -1;
		for (int i = 1; i <= N; i++) {
			if (deg[i] == 0) {
				Q[++re] = i;
			}
		}

		static int tc = 0;
		printf("#%d", ++tc);

		while (fr <= re) {
			x = Q[fr++];
			printf(" %d", x);
			for (int i = to[x]; i != -1; i = E[i].prv) {
				y = E[i].e;
				if (--deg[y] == 0) {
					Q[++re] = y;
				}
			}
		}
	}
}