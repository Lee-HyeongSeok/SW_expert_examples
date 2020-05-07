#include <iostream>
#include <vector>
using namespace std;

// x, y 좌표가 할당된 배열을 넘어가지 않게 검사하는 메소드
bool isWall(int x, int y) {
	if (x < 0 || x >= 5)
		return true;
	if (y < 0 || y >= 5)
		return true;
	return false;
}

// 큰 것에서 작은 것을 뺀다.
int callAbs(int a1, int a2) {
	return (a1 - a2) > 0 ? (a1 - a2) : -(a1 - a2);
}
void main() {
	int arr[][5] = {
		{9, 20, 2, 18, 11},
	{19, 1, 25, 3, 21},
	{8, 24, 10, 17, 7},
	{15, 4, 16, 5, 6},
	{12, 13,22, 23, 14}
	};

	/*
			(-1, 0)
	(0, -1)	현재위치 (0, 1)
			(1, 0)
	*/
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };
	int newX, newY;
	int sum = 0;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			for (int dir = 0; dir < 4; dir++) {
				// x, y는 현재위치를 의미
				// dx[dir], dy[dir]은 상하좌우를 의미
				newX = x + dx[dir];
				newY = y + dy[dir];
				// 상하좌우의 좌표가 벽에 막히지 않았다면
				// 큰 값 - 작은 값을 처리하는 함수로 전달한다.
				// 현재위치의 각 상, 하, 좌, 우의 값을 전달한다.
				if (!isWall(newX, newY))
					sum += callAbs(arr[y][x], arr[newY][newX]); 
			}
		}
	}
	cout << sum << endl;
}