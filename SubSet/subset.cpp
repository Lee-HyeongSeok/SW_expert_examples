#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int sum = 0; // 부분 집합의 합 
	bool ret = false;
	vector<int> vect;
	int i=0, j;
	int Test_case = 0; // 테스트 케이스
	int n = 0; // 배열 개수
	int val = 0;

	cin >> Test_case; // 테스트 케이스 입력 

	for (int t = 0; t < Test_case; t++) {
		cin >> n; // 배열의 개수 입력 
		for (int k = 0; k < n; k++) {
			cin >> val;
			vect.push_back(val);
		}
		// 1<<n : 부분집합의 개수, 1비트를 왼쪽으로 n번 쉬프트함
		// 부분 집합은 2x2x2x...xn번 이므로 2^n개가 부분 집합의 개수이다.
		for (j = 1; i < (1 << (n)); i++) { // N=5 이므로 32번 loop
			sum = 0; // 모든 부분집합의 합을 검사한 후 다시 0으로 set

			// j는 0, 1, 01, 101, 100까지의 값
			// i는 1, 10, 101, 100, 101, ..., 11111 까지의 값을 가짐
			for (j = 0; j < n; j++) {
				if (i & (1 << j)) { // 00000 ~ 11111 까지 모든 부분집합
					sum += vect[j];
				}
			}
			if (sum == 0) {
				ret = true;
				break;
			}
		}
		n = 0;
	}
	
	
	if (ret)
		cout << "True";
	else
		cout << "False";
	return 0;
}