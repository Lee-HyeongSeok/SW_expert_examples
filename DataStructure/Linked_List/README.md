## **Linked List - 연결 리스트 자료구조**

***

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

1. 단순 연결 리스트(Single Linked List)

![단순](https://user-images.githubusercontent.com/55940552/105948967-42ba9700-60af-11eb-85b3-f987f2dd41a2.png)

2. 단순 원형 연결 리스트(Single Circular Linked List)

![단순원형](https://user-images.githubusercontent.com/55940552/105948968-42ba9700-60af-11eb-9952-a5cfb64f26c6.png)

3. 이중 연결 리스트(Double Linked List)

![이중연결](https://user-images.githubusercontent.com/55940552/105948964-41896a00-60af-11eb-8971-f92d9cd0380c.png)

4. 이중 원형 연결 리스트(Double Circular Linked List)

![이중원형](https://user-images.githubusercontent.com/55940552/105948965-42220080-60af-11eb-978d-dbd12a751527.png)



***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/mainlayout)

[한국산업기술대학교](https://portal.kpu.ac.kr/portal/default/stu)

[코딩 팩토리 블로그](https://coding-factory.tistory.com/228)