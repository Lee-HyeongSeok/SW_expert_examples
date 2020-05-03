#include <iostream>

using namespace std;

#define EMPTY 0
#define BOX 1
#define MAX_SIZE 100

int main() {
	int testCase;

	int roomWidth, roomHeight; // 가로, 세로
	int maxFallen;

	int room[MAX_SIZE][MAX_SIZE] = { EMPTY, }; // 박스 여부를 표시하기 위한 맵
	int boxTop[MAX_SIZE] = { 0, }; // 가장 왼쪽의 상단에 있는 박스를 검사하기 위한 배열
	int countEmptySpace; // 빈 방의 개수를 세기 위함

	cin >> testCase; // 테스트 케이스 입력

	for (int t = 0; t < testCase; t++) {
		cin >> roomWidth >> roomHeight; // 가로, 세로 입력
		maxFallen = 0;
		for (int i = 0; i < roomWidth; i++) {
			cin >> boxTop[i]; // 박스의 개수를 입력받는다.
			for (int j = 0; j < boxTop[i]; j++) // 박스의 개수대로 1을 마킹
				room[i][j] = BOX;
		}
		for (int i = 0; i < roomWidth; i++) {
			if (boxTop[i] > 0) { // 박스가 1개 이상 존재할 때
				countEmptySpace = 0;
				for (int j = i + 1; j < roomWidth; j++) { // 현 위치 다음 박스 부터 검사
					if (room[j][boxTop[i] - 1] == EMPTY) // 현 위치로 부터 낙하 거리 계산, 0이 낙하 거리
						countEmptySpace += 1;
				}
				if (countEmptySpace > maxFallen) // 가장 큰 낙하 거리를 저장
					maxFallen = countEmptySpace;
			}
		}
		cout << maxFallen << endl;
	}
}