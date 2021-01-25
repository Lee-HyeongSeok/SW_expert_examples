#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxMagnetic 4 // 최대 마그네틱 개수
#define MAXMagnetProperty 8 // 각 자석이 가질 수 있는 자성 개수 

int RotationObject[MaxMagnetic]; // 회전 대상 자석들을 저장하기 위한 배열 
int MagnetMap[MaxMagnetic][MAXMagnetProperty]; // 자석들을 저장하기 위한 배열
int MagneticDirect[MaxMagnetic]; // 각 자석들의 회전 방향을 저장

void init() {
	for (int i = 0; i < MaxMagnetic; i++) {
		MagneticDirect[i] = RotationObject[i] = 0;
	}
}

// 회전 대상 자석과 연결된 자석들의 정보를 저장하기 위한 함수
// 회전 대상과 연결되어 있는 자석들만 저장
void RotationMagneticCheck(int magneticNumber) {
	int head = 0; 
	int leftMagnet = MAXMagnetProperty - 2;
	int rightMagnet = head + 2;

	// 현재 회전 대상인 자석은 닿는 부분의 자성이 어떻든 회전해야 하므로
	// 회전 대상 자석 리스트에 추가함
	RotationObject[magneticNumber] = 1;

	if (magneticNumber > 0) {
		// 왼쪽으로 검사
	// 원래는 left >= 0이였음
		for (int left = magneticNumber; left > 0; left--) {
			// 기준 자석의 왼쪽 부분과 기준 자석과 왼쪽으로 인접한 자석의 오른쪽 부분 검사
			// 두 자성이 일치하면 회전할 필요가 없으므로 break
			if (MagnetMap[left][leftMagnet] == MagnetMap[left - 1][rightMagnet]) {
				break;
			}
			// 두 자성이 일치하지 않다면 회전해야 하므로 회전 대상 자석 리스트에 추가
			else {
				RotationObject[left - 1] = 1;
			}
		}
	}
	
	if (magneticNumber < MaxMagnetic) {
		// 오른쪽으로 검사
		for (int right = magneticNumber; right < MaxMagnetic; right++) {
			// 기준 자석의 오른쪽 부분과 기준 자석과 오른쪽으로 인접한 자석의 왼쪽 부분 검사
			// 두 자성이 일치하면 회전할 필요가 없으므로 break
			if (MagnetMap[right][rightMagnet] == MagnetMap[right + 1][leftMagnet]) {
				break;
			}
			// 두 자성이 일치하지 않다면 회전해야 하므로 회전 대상 자석 리스트에 추가
			else {
				RotationObject[right + 1] = 1;
			}
		}
	}
}

// 각 자석의 회전 방향을 구하는 함수
// 회전 대상 자석 번호와 해당 자석의 회전 방향을 전달 받는다.
void MagneticDirection(int magnetNum, int direct) {
	MagneticDirect[magnetNum] = direct; // 기준 자석의 방향 저장 
	int switchDirect = direct; // 현재 자석의 회전 방향이 -1이면 인접 자석은 1을 가짐

	// 2번 자석의 회전 방향이 -1이라 치자

	// 왼쪽으로 검사
	// 현재 자석의 방향 기준으로 -1, 1 둘 중에 하나를 선택하여 저장
	for (int i = magnetNum - 1; i >= 0; i--) {
		// 현 자석 기준으로 왼쪽에 자석이 회전 대상 리스트에 존재한다면
		if (RotationObject[i] == 1) {
			// 자석의 회전 방향을 저장
			// 이전 회전 방향이 1이였다면
			if (switchDirect == 1) {
				switchDirect = -1; // 다음 회전 방향을 -1로 바꿔주고
				MagneticDirect[i] = switchDirect; // 다음 위치에 해당하는 자석의 방향을 바꿔줌
			}
			else if (switchDirect == -1) {
				switchDirect = 1;
				MagneticDirect[i] = switchDirect;
			}
		}
	}

	// 현재 기준 자석의 회전 방향을 저장
	switchDirect = direct;

	// 오른쪽으로 검사
	for (int i = magnetNum + 1; i < MaxMagnetic; i++) {
		// 현 자석 기준으로 오른쪽에 자석이 회전 대상 리스트에 존재한다면
		if (RotationObject[i] == 1) {
			if (switchDirect == 1) {
				switchDirect = -1;
				MagneticDirect[i] = switchDirect;
			}
			else if (switchDirect == -1) {
				switchDirect = 1;
				MagneticDirect[i] = switchDirect;
			}
		}
	}
}

// 1인 경우 오른쪽 회전
// 인자로는 어느 자석을 회전시킬지 전달 받는다.
void RotationArrayRight(int obj) {
	int temp = 0;
	temp = MagnetMap[obj][MAXMagnetProperty-1]; // 가장 오른쪽 자성을 저장

	for (int i = MAXMagnetProperty - 1; i >= 1; i--) {
		MagnetMap[obj][i] = MagnetMap[obj][i - 1]; // 오른쪽으로 한 칸씩 당김
	}
	MagnetMap[obj][0] = temp; // 가장 오른쪽에 있던 값을 처음 인덱스로
}

// -1인 경우 왼쪽 회전 
// 인자로는 어느 자석을 회전시킬지 전달 받는다.
void RotationArrayLeft(int obj) {
	int temp = 0;
	temp = MagnetMap[obj][0]; // 가장 왼쪽의 자성을 저장

	for (int i = 0; i <= MAXMagnetProperty - 1; i++) {
		MagnetMap[obj][i] = MagnetMap[obj][i + 1];
	}
	MagnetMap[obj][MAXMagnetProperty - 1] = temp;
}

void RotationMagnetic() {
	// 자석 번호 순회
	for (int i = 0; i < MaxMagnetic; i++) {
		// 회전 대상이라면
		if (RotationObject[i] == 1) {
			if (MagneticDirect[i] == 1) {
				RotationArrayRight(i); // 해당 자석 오른쪽 회전
			}
			else if (MagneticDirect[i] == -1) {
				RotationArrayLeft(i); // 해당 자석 왼쪽 회전
			}
		}
	}
}

void inputMagnetic() {
	for (int i = 0; i < MaxMagnetic; i++) {
		for (int j = 0; j < MAXMagnetProperty; j++) {
			scanf("%d", &MagnetMap[i][j]);
		}
	}
}

void Score() {
	int sc = 1;
	int result = 0;

	// 자석 수만큼 순회
	for (int i = 0; i < MaxMagnetic; i++) {
		result += MagnetMap[i][0] * sc;
		sc *= 2;
	}
	printf("%d", result);
}

int main() {
	int T = 0;
	int rotationValue = 0;
	int magneticNumber = 0, direct = 0; // 회전 대상 자석, 회전 방향(1 or -1)

	scanf("%d", &T); // 테스트 케이스

	// 테스트 케이스만큼 순회
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &rotationValue); // 회전 케이스 수
		inputMagnetic();
		
		// 회전 케이스 수만큼 회전 대상 자석과 회전 방향을 받아야 한다.
		for (int i = 0; i < rotationValue; i++) {
			init(); // 회전 대상 배열 초기화

			// 회전 대상 자석, 회전 방향
			// 회전 방향 : 1은 시계 방향(오른쪽), -1은 반시계방향(왼쪽)
			scanf("%d %d", &magneticNumber, &direct);

			// 회전 대상과 회전 방향을 통한 알고리즘 구현
			// 자석 번호를 0번부터 취급하기 때문에 함수로 넘길 때 -1을 해줘야 함
			RotationMagneticCheck(magneticNumber - 1); // 같이 회전 할 자석 체크

			// 회전이 유효한 자석들의 회전 방향 지정
			MagneticDirection(magneticNumber - 1, direct); 

			// 회전
			RotationMagnetic();
		}
		// 하나의 케이스에 대한 점수 산출
		printf("#%d ", test_case); // 테스트 케이스 출력
		Score(); // 점수 출력
	}
		
}