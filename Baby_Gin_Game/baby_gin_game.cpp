#include <iostream>

using namespace std;

int cardArr[10] = { 0, };

bool triple_flag = false;
bool run_flag = false;

void Check() {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (cardArr[i] >= 3) {
			cardArr[i] -= 3; // 해당 카드의 검사한 개수에 대해서는 제거
			triple_flag = true;
			i--;	// 바로 이전부터 재검사
		}
		// 1이 등장한 카드를 포함해 연속된 3개의 카드에 1이상의 개수가 있는지 판단
		if ((cardArr[i] >= 1) && (cardArr[i + 1] >= 1) && (cardArr[i + 2] >= 1)) {
			// 해당 카드의 검사한 개수에 대해서는 제거
			cardArr[i] -= 1;
			cardArr[i + 1] -= 1;
			cardArr[i + 2] -= 1;
			run_flag = true;
			i--;
		}
	}
}
int main() {
	int T;
	cin >> T; // 테스트 케이스 입력
	int card = 0;
	

	for (int i = 0; i < T; i++) {
		cin >> card;
		for (int j = 0; j < 6; j++) {
			cardArr[(card % 10)]++;
			card /= 10;
		}
		Check();

		if (triple_flag) {
			if (run_flag)
				cout << "Baby Gin" << endl;
			else
				cout << "Lose" << endl;
		}

	}
}