## * S/W expert Self Study : Palindrome   
#### * 출처 : S/W expert   

#### * 컴퓨터에서의 문자 저장   
			* 아스키 코드, 유니코드   
			* 아스키 코드 : 7비트 코드체계, 128개의 문자 표현 가능   
			* 유니코드 : 16비트 코드 체계, 65,536개의 문자 표현 가능   

#### * Palindrome   
			* 기러기 또는 level과 같이 거꾸로 읽어도 원래의 문장이나 낱말을 회문이라 한다.   
			* 주어진 8x8 평면 글자판에서 가로, 세로를 모두 보아 제시된 길이를 가진 회문의 총 개수를 구하는 문제   


#### * 문자열 복사   
		* 복사열 배열에서 빈 배열로 처음부터 끝까지 순회하며 대입   

```c
void user_strcpy(char *dest, char *src){
	while(*src != '\0'){ // 복사열 배열이 NULL이 아닐 때 
		*dest = *src; // 복사열 배열의 현재 인덱스를 빈 배열의 같은 인덱스에 삽입
		src++; //  복사열 배열의 주소 값 증가
		dest++; // 빈 배열의 주소 값 증가 
	}
	*dest = '\0';	// 빈 배열의 마지막에 NULL을 삽입
}
```   

#### * 문자열 뒤집기   
		* 처음과 끝의 문자를 바꾸는 과정 반복   

```c
void Flip_string(char str[]){
	int len=0;
	char t;
	
	len = strlen(str);
	
	// 양 쪽의 
	for(int i=0; i<len/2;  i++){
		t = str[i];	
		str[i] = str[len-1-i];
		str[len-1-i] = t;
	}
}
```   

#### * Palindrome 확인하기   
		* 처음과 끝의 문자를 바꾸는 과정에서 바꾸지 않고 두 문자가 같은지 확인한다면?   
		* strcmp : 두 문자열이 같으면 0반환, 다르면 1반환
```c
int Palindrome_String(char str[]){
	int len=strlen(str);
	int different=0;

	for(int i=0; i<len/2; i++){
		if(str[i] != str[len-1-i]) // 왼쪽, 오른쪽 문자가 다를 때
			different++;
	}
	if(different == 0)
		return 0;	// 증가가 없었다는 것은 사이드 문자가 모두 같은 문자였다는 것
	else 
		return 1; // 하나라도 다르면 Palindrome이 아니므로
}
```   

#### * strcmp 구현하기   
		* 두 문자열이 같은 경우 0 리턴, 아닌 경우 1 리턴
```c
int user_strcmp(const char *str1, const char *str2){
	int i=0, j=0;
	while(str1[i] != '\0'){
		if(str1[i] != str2[j]){ // 양쪽 사이드 각 문자가 서로 다른 경우
			i++; j++;
			break;
		}
	}
	return (str1[i] - str2[j]);
}
```   

#### * 문자열 숫자를 정수로 변환 atoi() 함수   

```c
int user_atoi(const char *str){
	int value=0, digit, c;

	while((c = *str++) != '\0'){	// int형 c변수에 문자를 하나씩 받는다.
		if('0' <= c && <= '9'){	// 해당 c변수의 값이 문자 0 보다 크거가 같고, 9보다 작거나 같으면
			digit = c-'0';	// '0'은 아스키 코드값으로 48, 문자의 아스키 값-0의 아스키 값은 해당 문자의 int형 숫자 값
		}
		else{
			break;
		}
		value = (value * 10) + digit;
	}
	return value;
}
```   

#### * 정수를 문자열로 변환 itoa() 함수   
		* 입력된 숫자를 한자리씩 나누어 보면서 문자로 변경하는 과정을 반복함   
		* 양의 정수를 입력 받아 문자열로 변환하는 함수   
		* x는 변환할 정수 값   
		* str[]은 변환된 문자열을 저장할 문자 배열   

```c

/*
7980 입력 -> 0 처리 -> str[0] =0;
	  -> 8 처리 -> str[1] = 8;
	  -> 9 처리 -> str[2] = 9;
	  -> 7 처리 -> str[3] = 7;

str = "0897" : 거꾸로 저장되어 있다.
때문에 문자열을 거꾸로 뒤집는 Flip_string 함수를 통해 다시 7980으로 돌려 놓는다.
*/
void user_itoa(int x, char str[]){
	int cnt=0;
	int i=0, y;
	
	while(1){
		y = x % 10;	// 일의 자리 숫자를 저장하는 y
		str[i++] = y + '0';	// y와 아스키 코드 값 48을 의미하는 '0'을 더하면 y의 아스키 코드 값이 나옴
		x /= 10;
	
		if(x == 0)	// 나누는 수가 0일 때
			break;
	}
	str[i] = '\0'; // 마지막에 문자열의 끝인 NULL 값 삽입 
	Flip_string(str); // 문자열이 거꾸로 저장되었기 때문에 다시 바꿔준다.
}   
```   

#### * Palindrome 제약사항   
		* 각 칸의 글자는 char type으로 주어짐   
		* 'A', 'B', 'C' 중 하나를 가질 수 있다.   
		* 글자 판은 정방행렬로 주어진다.   
		* 글자 하나인 'A' 또한 길이 1짜리 회문이다.   
		* 가로, 세로 각각에 대해 직선으로만 판단한다.   

* 입력
```c
1	// 테스트 케이스
4	// 찾아야 할 회문 길이
CBBCBAAB
CCCBABCB
CAAAACAB
BACCCCAC
AABCBBAC
ACAACABC
BCCBAABC
ABBBCCAA
```   
* 출력   
```c
12 // 찾은 회문의 개수 출력 
```   

#### * 전체 코드   

```c
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
```
