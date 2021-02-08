## **Linked List - 연결 리스트 자료구조**

***

### **목차**

- **ArrayList와 LinkedList**

  - ArrayList 선형 리스트란

    - ArrayList 선형 리스트 특징

  - LinkedList 연결 리스트란

    - LinkedList 연결 리스트 특징
    - LinkedList 연결 리스트 종류

    

- **연결 리스트 구현**

  - 1차원 배열을 이용한 구현
  - 포인터를 이용한 구현

  

- **단순 연결 리스트를 이용한 다양한 구현**



### **⚙ ArrayList(선형리스트)와 LinkedList(연결리스트)**

**1. ArrayList 선형 리스트란**

> 배열과 같이 연속되는 메모리에 저장되는 리스트

- 연접 리스트(Dense List) 또는 축차 구조(Sequential Structure)라고도 한다.

**1-1. ArrayList 선형 리스트 특징**

- 가장 간단한 자료구조

- 접근 속도가 빠르다.

- 중간에 자료를 사입하기 위해서는 연속된 빈 공간이 있어야 한다.

- 자료의 개수가 n개일 때 

  > 삽입 시 평균 이동 횟수 : (n+1)/2
  >
  > 삭제 시 평균 이동 횟수 : (n-1)/2

  ![ArrayList](https://user-images.githubusercontent.com/55940552/105946651-038a4700-60ab-11eb-85a3-9a6a578c828a.png)



**2. LinkedList 연결 리스트란**

> 자료들을 임의의 메모리에 저장 시키지만 자료 항목의 순서에 따라 노드의 포인터<br> 부분을 이용하여 서로 연결 시킨 자료 구조

**2-1. LinkedList 연결 리스트 특징**

- 노드의 삽입, 삭제 작업이 용이하다.
- 메모리 공간이 연속적이지 않아도 된다.
- 포인터를 찾는 시간이 필요하기 때문에 접근 속도가 느리다.
- 중간에 연결이 끊길 시 다음 노드를 찾기 힘들다.
- 트리에 적합한 자료 구조

**2-2. LinkedList 연결 리스트 종류**

1. **단순 연결 리스트(Single Linked List)**

![단순](https://user-images.githubusercontent.com/55940552/105948967-42ba9700-60af-11eb-85b3-f987f2dd41a2.png)

2. **단순 원형 연결 리스트(Single Circular Linked List)**

![단순원형](https://user-images.githubusercontent.com/55940552/105948968-42ba9700-60af-11eb-9952-a5cfb64f26c6.png)

3. **이중 연결 리스트(Double Linked List)**

![이중연결](https://user-images.githubusercontent.com/55940552/105948964-41896a00-60af-11eb-8971-f92d9cd0380c.png)

4. **이중 원형 연결 리스트(Double Circular Linked List)**

![이중원형](https://user-images.githubusercontent.com/55940552/105948965-42220080-60af-11eb-978d-dbd12a751527.png)



### **⚙ 연결 리스트 구현 방법 - 단순 연결 리스트(SLL)**

- **1차원 배열을 이용한 구현**
  
  - 구현이 간단하다.
  
  - 삽입, 삭제 시 오버헤드 발생 가능
  
  - 항목 개수 제한
  
  - 순차적 메모리 공간할당 특징으로 **순차적 표현(Sequential Representation)**이라고 한다.   
  
    [1차원 배열을 이용한 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/1%EC%B0%A8%EC%9B%90%EB%B0%B0%EC%97%B4%EA%B5%AC%ED%98%84)
  
    [1차원 배열을 이용한 구현 - SW expert academy](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/SW_Expert_Reference_Code)   
    
    
  
- **포인터를 이용한 구현**
  
  - 구현이 복잡하다.
  - 삽입, 삭제가 효율적이다.
  - 데이터를 저장할 공간이 제한적이지 않다.
  - 메모리를 효율적으로 사용할 수 있다.
  - 메모리 공간이 연속적으로 구성되지 않는다.
  



### **⚙  1차원 배열을 이용한  단순 연결 리스트 구현**

- 1차원 배열에 항목들을 순서대로 저장
- **삽입 연산** : 삽입 위치 다음의 항목들을 데이터의 개수 만큼 이동해야 한다.
- **삭제 연산** : 삭제 위치 다음의 항목들을 데이터의 개수 만큼 이동해야 한다.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // 리스트 최대 크기 지정

typedef int element; // 자료형 정의
typedef struct {
	element Arr[MAX]; // 1차원 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
}ArrayList;

// 오류 처리 함수
void error(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// 리스트 초기화 함수
void init(ArrayList * L) {
	L->size = 0;
}

// 리스트 공백 상태 검출 함수
element is_empty(ArrayList * L) {
	// 리스트가 비어있으면 1, 그렇지 않으면 0 반환
	return (L->size == 0);
}

// 리스트 포화 상태 검출 함수
element is_full(ArrayList * L) {
	// size는 현재 인덱스 위치를 나타냄
	// size가 99라면 모든 인덱스에 접근된 것이므로 포화 상태임을 의미
	// 포화 상태일 시 1, 그렇지 않으면 0 반환
	return (L->size == MAX - 1);
}

// 인자로 전달한 pos 인덱스 위치에 값을 반환한다.
element get_entry(ArrayList * L, int pos) {
	// pos는 ArrayList의 인덱스 위치
	// 0보다 작거나 저장된 값의 인덱스보다 크다면 오류
	if (pos < 0 || pos >= L->size) {
		error("위치 오류");
	}
	return L->Arr[pos];
}

// 자료를 삽입 하는 함수
void insert(ArrayList * L, int pos, element item) {
	// 리스트가 포화 상태가 아니고 삽입 위치가 0보다 크거나 현재 사이즈 보다 작거나 같을 때
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		// 뒤에서부터 삽입
		for (int i = (L->size - 1); i >= pos; i--) {
			L->Arr[i + 1] = L->Arr[i]; // 삽입 위치 다음 요소들을 한칸씩 밀어낸다.
		}
		L->Arr[pos] = item; // 삽입 위치에 데이터 삽입
		L->size++; // 데이터 삽입 후 현재 항목 개수 증가
	}
}

// pos 위치에 데이터를 삭제하는 함수
element Delete(ArrayList * L, int pos) {
	element item;

	// 삭제하려는 데이터의 위치가 옳바르지 않을 때
	if (pos < 0 || pos >= L->size)
		error("위치 오류");

	item = L->Arr[pos]; // 삭제하려는 데이터 임시 저장

	// 삭제하려는 위치를 시작으로 배열의 마지막 항목까지 순회
	for (int i = pos; i < (L->size - 1); i++) {
		L->Arr[i] = L->Arr[i + 1]; // 앞으로 한 칸씩 당긴다.
	}
	L->size--; // 항목 개수 감소

	return item; // 삭제할 데이터 반환
}

// 리스트 출력 함수
void printArrayList(ArrayList * L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d -> ", L->Arr[i]);
	}
	printf("\n");
}

int main() {
	ArrayList list;
	int T = 0;
	element pos = 0; // 사용자에게 입력받을 데이터 삽입 포지션
	element item = 0; // 사용자에게 입력받을 데이터

	// 테스트 케이스 입력 받음과 동시에 개수만큼 순회
	for (scanf("%d", &T); T--;) {
		init(&list);

		while (1) {
			scanf("%d %d", &pos, &item); // 데이터 삽입 포지션과 데이터 입력 받음

			// 사용자, -1입력 시 입력 종료
			if (item == -1)
				break;

			insert(&list, pos, item);
		}
		printArrayList(&list);
	}
	return 0;
}
```



### **⚙ 연결 리스트, 포인터를 이용한 구현**

- 하나의 노드 구조체에 <데이터, 다음 노드 주소> 쌍을 나타낸다.
- 삽입 연산 시 새로운 노드를 생성하고 head 노드와 연결해준다.



### **삽입 연산**

![insert](https://user-images.githubusercontent.com/55940552/105963484-64724900-60c4-11eb-8456-bad0b1add025.png)   

```c
// 노드를 생성함과 동시에 head와 연결 시켜주는 함수
ListNode * insertNode(ListNode * head, element value) {
	ListNode * newNode = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
	newNode->data = value; // 새로운 노드에 데이터 삽입

	newNode->link = head; // 새로 생성한 노드가 인자로 전달된 head를 가리키게 함
	head = newNode; // head에 새로 생성한 노드를 복사함
	return head;
}
```





### **삭제 연산**

![delete](https://user-images.githubusercontent.com/55940552/105963491-65a37600-60c4-11eb-9035-581cc7be92f2.png)

```c
// pre 노드가 가리키는 다음 노드를 삭제
ListNode * deleteNode(ListNode * head, ListNode *pre) {
	ListNode * removed;
	removed = pre->link; // pre가 가리키는 다음 노드를 임시 저장
	pre->link = removed->link; // removed가 가리키는 다음 노드를 임시 저장
	free(removed); // 삭제할 노드 메모리 해제
	return head;
}
```





### **⚙ 단순 연결 리스트를 이용한 다양한 구현**

- 📌 [포인터를 이용한 단순 연결 리스트 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/%EB%85%B8%EB%93%9C%EA%B5%AC%ED%98%84)
- 📌 [포인터를 이용한 다항식 연산 연결 리스트 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/%EB%8B%A4%ED%95%AD%EC%8B%9D)
- 📌 [head, tail 포인터를 이용한 Stack 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/LinkedList_stack%EA%B5%AC%ED%98%84)   





***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/mainlayout)

[한국산업기술대학교](https://portal.kpu.ac.kr/portal/default/stu)

[코딩 팩토리 블로그](https://coding-factory.tistory.com/228)