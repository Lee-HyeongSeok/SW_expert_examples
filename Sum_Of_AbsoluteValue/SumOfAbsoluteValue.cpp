#include <iostream>
#include <vector>
using namespace std;

// x, y ��ǥ�� �Ҵ�� �迭�� �Ѿ�� �ʰ� �˻��ϴ� �޼ҵ�
bool isWall(int x, int y) {
	if (x < 0 || x >= 5)
		return true;
	if (y < 0 || y >= 5)
		return true;
	return false;
}

// ū �Ϳ��� ���� ���� ����.
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
	(0, -1)	������ġ (0, 1)
			(1, 0)
	*/
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };
	int newX, newY;
	int sum = 0;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			for (int dir = 0; dir < 4; dir++) {
				// x, y�� ������ġ�� �ǹ�
				// dx[dir], dy[dir]�� �����¿츦 �ǹ�
				newX = x + dx[dir];
				newY = y + dy[dir];
				// �����¿��� ��ǥ�� ���� ������ �ʾҴٸ�
				// ū �� - ���� ���� ó���ϴ� �Լ��� �����Ѵ�.
				// ������ġ�� �� ��, ��, ��, ���� ���� �����Ѵ�.
				if (!isWall(newX, newY))
					sum += callAbs(arr[y][x], arr[newY][newX]); 
			}
		}
	}
	cout << sum << endl;
}