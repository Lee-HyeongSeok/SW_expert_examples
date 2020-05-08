#include <iostream>
using namespace std;

#define MAX_SIZE 8

int main() {
	int length;
	int cnt;
	char map[MAX_SIZE][MAX_SIZE] = { 0, };
	bool flag;

	int Test_case = 0;	// 테스트 케이스
	cin >> Test_case;	// 테스트 케이스 입력
	for (int i = 0; i < Test_case; i++) {
		cin >> length;	// 찾고자 하는 길이
		
		for (int j = 0; j < MAX_SIZE; j++) {
			for (int k = 0; k < MAX_SIZE; k++) {
				cin >> map[j][k];
			}
		}

		cnt = 0;
		for (int j = 0; j < MAX_SIZE; j++) { // 가로 검사 
			// 정해진 길이가 4라면, 8-4+1 = 5
			// k는 0부터 4까지 증가, 전체 가로의 인덱스는 0부터 7까지
			// 검사할 개수를 한정시키는 for문
			for (int k = 0; k < (MAX_SIZE - length + 1); k++) { 
				flag = true;	// 초기 플래그 1로 설정
				// 정해진 길이가 4라면, m은 0부터 1까지 증가
				// (4, 7)-(5, 6) 이런식으로 검사
				for (int m = 0; m < (length / 2); m++) {
					if (map[j][m + k] != map[j][k + length - m - 1])
						flag = false;  // 문자가 비대칭일 때 false;
				}
				if (flag)
					cnt++;
			}
		}
		for (int j = 0; j < MAX_SIZE; j++) { // 세로 검사
			for (int k = 0; k < (MAX_SIZE - length + 1); k++) { // 검사할 개수 한정
				flag = true;

				for (int m = 0; m < (length / 2); m++) { // 양쪽을 나눠서 검사하기 위함
					if (map[m + k][j] != map[k + length - m - 1][j])
						flag = false;
				}
				if (flag)
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;

}