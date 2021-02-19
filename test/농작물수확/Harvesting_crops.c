#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 50

int N;
int Map[MAXN][MAXN];

void process() {
	int half = N / 2;
	int SW = 0;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// half가 0이 아닐 때는 규칙에 따라 값을 더한다.
			if (half != 0) {
				if (j < half || j >= N - half)
					continue;
				else
					sum += Map[i][j];
					//printf("%d", Map[i][j]);
			}
			// half가 0일 때는 해당 라인에 모든 점수가 더해져야 한다.
			// 어떤 규칙도 적용하지 않고 loop를 수행 
			else {
				sum += Map[i][j];
				//printf("%d", Map[i][j]);
			}
		}
		// 중간 까지 돌고나면 SW를 1로 바꿔서 half를 계속 증가시킨다.
		// 중간 까지라는 의미는 half가 처음으로 0이 되었을 때를 말한다.
		if (half == 0)
			SW = 1;

		// switch 동작을 이용해서 half가 증가할지 감소할지를 결정
		if (SW) {
			half++;
		}
		else if (!SW) {
			half--;
		}
	}
	printf(" %d", sum);
}

int main() {
	int T = 0;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &Map[i][j]);
			}
		}
		printf("#%d", tc);
		process();
	}
}