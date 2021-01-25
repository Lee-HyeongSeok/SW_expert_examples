#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxMagnetic 4 // �ִ� ���׳�ƽ ����
#define MAXMagnetProperty 8 // �� �ڼ��� ���� �� �ִ� �ڼ� ���� 

int RotationObject[MaxMagnetic]; // ȸ�� ��� �ڼ����� �����ϱ� ���� �迭 
int MagnetMap[MaxMagnetic][MAXMagnetProperty]; // �ڼ����� �����ϱ� ���� �迭
int MagneticDirect[MaxMagnetic]; // �� �ڼ����� ȸ�� ������ ����

void init() {
	for (int i = 0; i < MaxMagnetic; i++) {
		MagneticDirect[i] = RotationObject[i] = 0;
	}
}

// ȸ�� ��� �ڼ��� ����� �ڼ����� ������ �����ϱ� ���� �Լ�
// ȸ�� ���� ����Ǿ� �ִ� �ڼ��鸸 ����
void RotationMagneticCheck(int magneticNumber) {
	int head = 0; 
	int leftMagnet = MAXMagnetProperty - 2;
	int rightMagnet = head + 2;

	// ���� ȸ�� ����� �ڼ��� ��� �κ��� �ڼ��� ��� ȸ���ؾ� �ϹǷ�
	// ȸ�� ��� �ڼ� ����Ʈ�� �߰���
	RotationObject[magneticNumber] = 1;

	if (magneticNumber > 0) {
		// �������� �˻�
	// ������ left >= 0�̿���
		for (int left = magneticNumber; left > 0; left--) {
			// ���� �ڼ��� ���� �κа� ���� �ڼ��� �������� ������ �ڼ��� ������ �κ� �˻�
			// �� �ڼ��� ��ġ�ϸ� ȸ���� �ʿ䰡 �����Ƿ� break
			if (MagnetMap[left][leftMagnet] == MagnetMap[left - 1][rightMagnet]) {
				break;
			}
			// �� �ڼ��� ��ġ���� �ʴٸ� ȸ���ؾ� �ϹǷ� ȸ�� ��� �ڼ� ����Ʈ�� �߰�
			else {
				RotationObject[left - 1] = 1;
			}
		}
	}
	
	if (magneticNumber < MaxMagnetic) {
		// ���������� �˻�
		for (int right = magneticNumber; right < MaxMagnetic; right++) {
			// ���� �ڼ��� ������ �κа� ���� �ڼ��� ���������� ������ �ڼ��� ���� �κ� �˻�
			// �� �ڼ��� ��ġ�ϸ� ȸ���� �ʿ䰡 �����Ƿ� break
			if (MagnetMap[right][rightMagnet] == MagnetMap[right + 1][leftMagnet]) {
				break;
			}
			// �� �ڼ��� ��ġ���� �ʴٸ� ȸ���ؾ� �ϹǷ� ȸ�� ��� �ڼ� ����Ʈ�� �߰�
			else {
				RotationObject[right + 1] = 1;
			}
		}
	}
}

// �� �ڼ��� ȸ�� ������ ���ϴ� �Լ�
// ȸ�� ��� �ڼ� ��ȣ�� �ش� �ڼ��� ȸ�� ������ ���� �޴´�.
void MagneticDirection(int magnetNum, int direct) {
	MagneticDirect[magnetNum] = direct; // ���� �ڼ��� ���� ���� 
	int switchDirect = direct; // ���� �ڼ��� ȸ�� ������ -1�̸� ���� �ڼ��� 1�� ����

	// 2�� �ڼ��� ȸ�� ������ -1�̶� ġ��

	// �������� �˻�
	// ���� �ڼ��� ���� �������� -1, 1 �� �߿� �ϳ��� �����Ͽ� ����
	for (int i = magnetNum - 1; i >= 0; i--) {
		// �� �ڼ� �������� ���ʿ� �ڼ��� ȸ�� ��� ����Ʈ�� �����Ѵٸ�
		if (RotationObject[i] == 1) {
			// �ڼ��� ȸ�� ������ ����
			// ���� ȸ�� ������ 1�̿��ٸ�
			if (switchDirect == 1) {
				switchDirect = -1; // ���� ȸ�� ������ -1�� �ٲ��ְ�
				MagneticDirect[i] = switchDirect; // ���� ��ġ�� �ش��ϴ� �ڼ��� ������ �ٲ���
			}
			else if (switchDirect == -1) {
				switchDirect = 1;
				MagneticDirect[i] = switchDirect;
			}
		}
	}

	// ���� ���� �ڼ��� ȸ�� ������ ����
	switchDirect = direct;

	// ���������� �˻�
	for (int i = magnetNum + 1; i < MaxMagnetic; i++) {
		// �� �ڼ� �������� �����ʿ� �ڼ��� ȸ�� ��� ����Ʈ�� �����Ѵٸ�
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

// 1�� ��� ������ ȸ��
// ���ڷδ� ��� �ڼ��� ȸ����ų�� ���� �޴´�.
void RotationArrayRight(int obj) {
	int temp = 0;
	temp = MagnetMap[obj][MAXMagnetProperty-1]; // ���� ������ �ڼ��� ����

	for (int i = MAXMagnetProperty - 1; i >= 1; i--) {
		MagnetMap[obj][i] = MagnetMap[obj][i - 1]; // ���������� �� ĭ�� ���
	}
	MagnetMap[obj][0] = temp; // ���� �����ʿ� �ִ� ���� ó�� �ε�����
}

// -1�� ��� ���� ȸ�� 
// ���ڷδ� ��� �ڼ��� ȸ����ų�� ���� �޴´�.
void RotationArrayLeft(int obj) {
	int temp = 0;
	temp = MagnetMap[obj][0]; // ���� ������ �ڼ��� ����

	for (int i = 0; i <= MAXMagnetProperty - 1; i++) {
		MagnetMap[obj][i] = MagnetMap[obj][i + 1];
	}
	MagnetMap[obj][MAXMagnetProperty - 1] = temp;
}

void RotationMagnetic() {
	// �ڼ� ��ȣ ��ȸ
	for (int i = 0; i < MaxMagnetic; i++) {
		// ȸ�� ����̶��
		if (RotationObject[i] == 1) {
			if (MagneticDirect[i] == 1) {
				RotationArrayRight(i); // �ش� �ڼ� ������ ȸ��
			}
			else if (MagneticDirect[i] == -1) {
				RotationArrayLeft(i); // �ش� �ڼ� ���� ȸ��
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

	// �ڼ� ����ŭ ��ȸ
	for (int i = 0; i < MaxMagnetic; i++) {
		result += MagnetMap[i][0] * sc;
		sc *= 2;
	}
	printf("%d", result);
}

int main() {
	int T = 0;
	int rotationValue = 0;
	int magneticNumber = 0, direct = 0; // ȸ�� ��� �ڼ�, ȸ�� ����(1 or -1)

	scanf("%d", &T); // �׽�Ʈ ���̽�

	// �׽�Ʈ ���̽���ŭ ��ȸ
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &rotationValue); // ȸ�� ���̽� ��
		inputMagnetic();
		
		// ȸ�� ���̽� ����ŭ ȸ�� ��� �ڼ��� ȸ�� ������ �޾ƾ� �Ѵ�.
		for (int i = 0; i < rotationValue; i++) {
			init(); // ȸ�� ��� �迭 �ʱ�ȭ

			// ȸ�� ��� �ڼ�, ȸ�� ����
			// ȸ�� ���� : 1�� �ð� ����(������), -1�� �ݽð����(����)
			scanf("%d %d", &magneticNumber, &direct);

			// ȸ�� ���� ȸ�� ������ ���� �˰��� ����
			// �ڼ� ��ȣ�� 0������ ����ϱ� ������ �Լ��� �ѱ� �� -1�� ����� ��
			RotationMagneticCheck(magneticNumber - 1); // ���� ȸ�� �� �ڼ� üũ

			// ȸ���� ��ȿ�� �ڼ����� ȸ�� ���� ����
			MagneticDirection(magneticNumber - 1, direct); 

			// ȸ��
			RotationMagnetic();
		}
		// �ϳ��� ���̽��� ���� ���� ����
		printf("#%d ", test_case); // �׽�Ʈ ���̽� ���
		Score(); // ���� ���
	}
		
}